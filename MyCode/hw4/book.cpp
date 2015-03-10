#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn) : 
		   Product (category, name, price, qty) {

	author_ = author;
	isbn_ = isbn;
	name_ = name_;  

}


Book::~Book() {
}


std::set<std::string> Book::keywords() const {

	/* Valid keywords are: 
	 *  product name 
	 * 	author's name (all names: F, M, L)
	 *  book's ISBN number
	 */

	std::set<std::string> nameKeywords = parseStringToWords(name_);
	std::set<std::string> authorKeywords = parseStringToWords(author_);  
	std::set<std::string> bookKeywords = setUnion(nameKeywords, authorKeywords);  
	bookKeywords.insert(isbn_); 
	return bookKeywords; 

}


bool Book::isMatch(std::vector<std::string>& searchTerms) const {
	return false;
}


std::string Book::displayString() const {
	return name_ + "\n" + "Author: " + author_ + " " + "ISBN: " + isbn_;  
}


void Book::dump(std::ostream& os) const {
	Product::dump(os); 
	os << isbn_ << "\n" << author_ << "\n"; 
}


std::string Book::getAuthor() const {
	return author_;
}


std::string Book::getISBN() const {
	return isbn_; 
}
