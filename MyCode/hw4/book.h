#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include "product.h"
#include "util.h"

class Book : public Product {

	public: 
		Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn);

		~Book(); 

		std::set<std::string> keywords() const;

		bool isMatch(std::vector<std::string>& searchTerms) const;

		std::string displayString() const;

		void dump(std::ostream& os) const;

		std::string getAuthor() const;

		std::string getISBN() const; 

	private: 
		std::string author_;

		std::string isbn_; 


}; 
#endif