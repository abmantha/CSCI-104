#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "setint.h"
using namespace std;

void conv_lower(string& s)
{
  for(size_t i = 0; i < s.size(); i++){
    if(isalpha(s[i])){
      s[i] = tolower(s[i]);
    }
  }
}

void parse(string token, map<string,SetInt>& idx, int pageNum)
{
  size_t start = 0, end = token.size();
  while(start < end && ispunct(token[start])){
    start++;

  }

  while(end > start && ispunct(token[end-1])){
    end--;
  }

  if( (end-start) > 1){
    token = token.substr(start, end-start);

    start = 0;
    end = 0;
    
    for(size_t i = 0; i < token.size(); i++){
      if( ispunct(token[i]) && token[i] != '-'){
	return;
      }
    }
    // Make all lower case
    conv_lower(token);
 
    while(token.size() > 0 && end < token.size()){
      if( token[end] == '-'){
	if(end > 1){
#ifdef DEBUG
	  cout << "Adding string: " << token.substr(0,end) << endl;
#endif
	  string term = token.substr(0,end);
	  if(idx.find(term) == idx.end()){
	    SetInt myset;
	    idx.insert( pair<string,SetInt>(term,myset));
	  }
	  idx[term].insert(pageNum);
	}
	token = token.substr(end+1);
	end = 0;
	continue;
      }
      end++;
    }
#ifdef DEBUG
    cout << "Adding string: " << token.substr(0,end) << endl;
#endif
    string term = token.substr(0,end);
    if(idx.find(term) == idx.end()){
      SetInt myset;
      idx.insert( pair<string,SetInt>(term,myset));
    }
    idx[term].insert(pageNum);

  }
}


int main(int argc, char* argv[])
{
  if(argc < 4){
    cerr << "Usage ./pgindex input_file output_file term1 ... termN" << endl;
    return 1;
  }

  map<string,SetInt> idx;

  ifstream ifile(argv[1]);
  if(ifile.fail()){
    cerr << "Unable to open " << argv[1] << endl;
    return 1;
  }
  string token;
  int pageNum = 1;
  while(ifile >> token){
    
    if(token == "<pagebreak>"){
      pageNum++;
    }
    else {
      parse(token, idx, pageNum);
    }
  }
  ifile.close();
  ofstream ofile(argv[2]);
  for(int i=3; i < argc; i++){
    string term(argv[i]);
    conv_lower(term);
    if(idx.find(term) != idx.end()){
      ofile << *(idx[term].first());
      int const *p1;
      while( p1 = idx[term].next() ){
	ofile << " " << *p1;
      }
      ofile << endl;
    }
    else {
      ofile << "None" << endl;
    }
  }
  ofile.close();
  return 0;
}
