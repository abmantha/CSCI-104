#include "util.h"
#include <set>
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {

	std::cout << "Hello!" << std::endl; 

	std::string test = "data"; 
	std::cout << test << std::endl;
	std::cout << test.length() << std::endl;

	std::set<std::string> subWords = parseStringToWords(test); 
	std::cout << "# of subwords: " << subWords.size() << std::endl;


	for (std::set<std::string>::iterator it=subWords.begin(); it!=subWords.end(); ++it) {
	    std::cout << ' ' << *it << std::endl;
	}


	return 0; 
}