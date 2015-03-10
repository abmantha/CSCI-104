#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "stackdbl.h"

using namespace std;

double do_op(double val1, double val2, char op)
{
  if(op == '+'){
    return val1 + val2;
  }
  else if(op == '-'){
    return val1 - val2;
  }
  else if(op == '*'){
    return val1 * val2;
  }
  else if(op == '/'){
    return val1 / val2;
  }
  return 0;
}

double calculate(string& expr,bool& success)
{
  StackDbl st;

   	 

  int i=0;
  double sol = 0;
  while(i < expr.size() ){
    if( isdigit(expr[i]) ){
      int num_dig=0;
      while(isdigit(expr[i+num_dig])){
	num_dig++;
      }
      string s = expr.substr(i,num_dig);
      double val = std::stoi(s, nullptr);
      st.push(val);
      i += num_dig;
    }
    else if( expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'){
      if(!st.empty()) {
	double val2 = st.top();
	st.pop();
	if(!st.empty()){
	  double val1 = st.top();
	  st.pop();
	  double res = do_op(val1, val2, expr[i]);
	  st.push(res);
	}
	else {
	  cerr << "Syntax error: " << i << endl;
     	  success = false;
	  return -1;
	}
      }
      else {
	cerr << "Syntax error: " << i << endl;
        success = false;
        return -1;
      }
      i++;
      
    }
    else {
      i++;
    }
  }
  sol = st.top();
  st.pop();
  success = true;
  return sol;
}


int main(int argc, char* argv[])
{
  if(argc < 3){
    cout << "Provide input and output filenames" << endl;
    return 1;
  }
  ifstream ifile(argv[1]);
  ofstream ofile(argv[2]);
  string s;
  getline(ifile, s);
  cout << "Calculating " << s << endl;
  while( ! ifile.fail()){
    bool success = true;
    double sol = calculate(s, success);
    if(success)
      ofile << sol << endl;
    else
      ofile << "invalid" << endl;  
    //cout << "Calculating " << ": Done" << endl;
    getline(ifile, s);
    cout << "Calculating " << s << endl;
  }
  ifile.close();
  ofile.close();
  return 0;
}
