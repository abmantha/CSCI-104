#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
using namespace std;

std::string convToLower(std::string src) {
  std::transform(src.begin(), src.end(), src.begin(), ::tolower);
  return src;
}

/** Complete the code to convert a string containing a rawWord 
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string line) {

	uint i = 0; 
	uint head = 0; 
	std::set<std::string> subWords; 
	while (i <= line.size()) {

		if ( (ispunct(line[i]) || isblank(line[i])) || i == line.size() )  {
			int subWordLen = i - head; 
			string subWord = line.substr(head, subWordLen); 
			if (subWord.length() > 1) {
				subWord = convToLower(subWord); 
				subWords.insert(subWord); 
			}
			head = i + 1;
		}

		i++; 

	}

	return subWords; 

}
