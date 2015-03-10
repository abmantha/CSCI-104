 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/13/15    |
 * | HW 3                       |
 * ==============================
 * 
 *  Filename: pgindex.cpp
 * 
 * 	Directions from  bits.usc.edu/cs104/assignments/hw3:
 * 		
 * 		Write a program to read in all words of a text 
 * 		file that is logically broken into "pages" via 
 * 		a string <pagebreak> and then compute an index
 * 		that associates each word in the text file with 
 * 		other page numbers it appears on. 
 * 	
 * 		You may only use the STL map class and classes
 * 		you have implemented for past homework assignments.
 * 		I am using the SetInt class defined for Problem3
 * 		of hw3. 
 *   
 */

#include "../problem3/lib/setint.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

/* Function prototypes */
void buildPageIndex(ifstream& infile, map<string, SetInt>& index); 
void insertIntoMap(string& subWord, int& page_number, map<string, SetInt>& index); 
void searchDatabase(map<string, SetInt>& index, ofstream& outfile, int argc, char *argv[]);
void convertToLowercase(string& str);  
bool isValidWord(string& str);
void removeFrontEndPunct(string& str);
bool isHyphenated(string& str);

/* Function: main
 * ========================================================
 * This program reads inall the words ofa  text file that is 
 * logically broken into "pages" via a special string 
 * <pagebreak> and then computes an index that associates 
 * each word in the text file (other than <pagebreak>) with
 * the page numbers it appears on. All streams are initialized
 * and closed here. buildPageIndex() and searchDatabase() 
 * are the main driving functions of this program. 
 */
int main (int argc, char *argv[]) {

	/* Initialize streams. */
	ifstream infile;
	ofstream outfile;
	infile.open(argv[1]);
	outfile.open(argv[2]);

	/* Check file success. */
	if (infile.fail()) {
		cout << "Problem with input file." << endl;
		return 0;
	}

	if (outfile.fail()) {
		cout << "Problem with output file." << endl;
		return 0;
	}

	/* Create map instance */
	map<string, SetInt> index;

	/* Build the database */
	buildPageIndex(infile, index); 

	/* Search the database with command line queries */
	searchDatabase(index, outfile, argc, argv); 

	/* Close file streams */
	infile.close();
	outfile.close(); 

	return 0; 
}


/* Function: buildPageIndex
 * Usage: buildPageIndex(infile, index)
 * ========================================================
 * This function reads in individual words from a text file
 * and computes an index associated with their "page" number,
 * storing them in a map with word keys mapping to page 
 * index values. Page numbering begins on page 1. If a word
 * appears on a page multiple times, that page number should 
 * still only appear once for the word. Punctuation at the 
 * beginning or end of a word should be discarded. This is
 * achieved with the helper function removeFrontEndPunct().
 * Index and search words are case-insensitive -- everything
 * is lower case. Valid words must contain as least 2 letters.
 * Words of any size with punctuation in the middle of the word 
 * should be ignored (e.g. I'm, didn't) with the exception of the 
 * hyphen, -, which should cause the word to be split into multiple 
 * words. For example, rope-a-dope should be split into 
 * rope and dope (a is discarded since its only 1 char) while 
 * devil-may-care should be split into devil, may, and care.
 */
void buildPageIndex(ifstream& infile, map<string, SetInt>& index) {

	/* Stringstream and line variables for input */
	string line = "";
	istringstream strm;
	int page_number = 1; 


	while (getline(infile, line)) {
		/* Clear stream for reuse and tokenize line of text */
		strm.clear();
		strm.str(line); 
		string temp = "";

		/* For every word in a line */
		while (strm >> temp) {

			/* Increment if word is <pagebreak> */
			if (temp == "<pagebreak>") {
				page_number++; 

			/* Otherwise */
			} else {

				/* Remove front and end punctuation */
				removeFrontEndPunct(temp); 

				/* Special treatment of hyphenated words */
				if(isHyphenated(temp)) {

					/* Extract every subword of the hyphenated text */
					string subWord = "";
					uint found = temp.find_first_of('-');
					int head = 0;

					/* For every subword */
					while (found < temp.size()) {
						subWord = temp.substr(head, found-head); 
						head = found+1; 
						found = temp.find_first_of('-', found+1); 
 						
 						/* Remove the punctuation */
						removeFrontEndPunct(subWord);

						/* Check that word has >=2 characters and no middle punctuation */  
						if (isValidWord(subWord)) {
							/* Convert word to lowercase */
							convertToLowercase(subWord);
							/* Insert this value into the map */
							insertIntoMap(subWord, page_number, index) ;
						} 

						/* SPECIAL CASE: extract last word of hyphenated set manually
						 * and conduct the same proofing and checking as before, before
						 * inserting into the map.
						 */
						if (found > temp.size()) {
							subWord = temp.substr(head);	
							removeFrontEndPunct(subWord);  
							if (isValidWord(subWord)) {
								convertToLowercase(subWord);
								insertIntoMap(subWord, page_number, index) ;
							} 
						}
					}

				/* For non-hyphenated words, conduct same checking */
				} else {
					if (isValidWord(temp)) {
						convertToLowercase(temp);
						insertIntoMap(temp, page_number, index) ;
					}
				}
			}	
		}
	}
}


/* Function: insertIntoMap
 * Usage: insertIntoMap(subWord, page_number, index)
 * ========================================================
 * This function inserts an element into the word index
 * implemented using a map. When new word has been inserted,
 * this creates a new set of page numbers and inserts the 
 * current page number. The map then inserts this pair.
 * If it has already seen a word, it checks to see if 
 * it has already been seen before on this same page. If it 
 * has, it does not insert the same page number again. If it 
 * has not seen this same word on this current page, it inserts
 * this current page into the word's set of index page numbers.
 */
void insertIntoMap(string& subWord, int& page_number, map<string, SetInt>& index) {
	map<string, SetInt>::iterator it;
	it = index.find(subWord); 
	if (it != index.end()) {
		if (!(it->second).exists(page_number)) {
			(it->second).insert(page_number); 
		}
	} else {
		SetInt pages; 
		pages.insert(page_number); 
		index.insert( std::pair<string, SetInt>(subWord, pages)); 
	}
}


/* Function: searchDatabase
 * Usage: searchDatabase(index, outfile, argc, argv)
 * ========================================================
 * This function searches the map index database using 
 * the user-specified queries. It then outputs the page numbers
 * if a word exists in the database to an output file. If a word
 * is not in the database, it outputs "None"
 */
void searchDatabase(map<string, SetInt>& index, ofstream& outfile, int argc, char *argv[]) {
	for (int i = 3; i < argc; i++) {
		string word = (string)argv[i];
		convertToLowercase(word); 

		map<string, SetInt>::iterator it;
		it = index.find(word); 
		const int* item = it->second.first(); 
		if (it != index.end()) {
			while (item != NULL) {
				outfile << *item << " ";
				item = it->second.next();
			}
			outfile << endl;
		} else {
			outfile << "None" << endl;
		}
	}
}


/* Function: isHyphenated
 * Usage: bool hyphenated = isHyphenated(str)
 * ========================================================
 * Returns if a given word contains hyphens. 
 */
bool isHyphenated(string& str) {
	for (uint i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			return true;
		}
	}
	return false;
}


/* Function: isValidWord
 * Usage: bool valid = isValidWord(str)
 * ========================================================
 * Returns if a word is valid. Valid is defined by has no
 * punctuation within the middle of the characters after 
 * the isHyphenated() check and removeFrontEndPunct() functions,
 * and is at least two characters. 
 */
bool isValidWord(string& str) {
	bool valid = true;
	for (uint i = 0; i < str.size(); i++) {
		if (ispunct(str[i])) {
			valid = false; 
		} 
	}

	if (valid) {
		if (str.size() < 2) {
			valid = false;
		} 
	}

	return valid;

}


/* Function: removeFrontEndPunct
 * Usage: removeFrontEndPunt(str)
 * ========================================================
 * Removes punctuation from front and end of a given string.
 */
void removeFrontEndPunct(string& str) {
	while (ispunct(str[0])) {
		str = str.substr(1);
	}
	
	while (ispunct(str[str.size()-1])) {
		str = str.substr(0, str.size()-1);
	}
}


/* Function: convertToLowercase
 * Usage: convertToLowercase(str)
 * ========================================================
 * Converts a string to all lowercase letters. 
 */
void convertToLowercase(string& str) {
	for (uint i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]); 
	}
}



