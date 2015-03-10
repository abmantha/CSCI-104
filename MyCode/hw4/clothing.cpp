#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) : 
		   Product (category, name, price, qty) {

	size_ = size;
	brand_ = brand;
	name_ = name_;  

}


Clothing::~Clothing() {
}


std::set<std::string> Clothing::keywords() const {

	/* Valid keywords are:
	 *  product name 
	 * 	brand
	 */

	std::set<std::string> nameKeywords = parseStringToWords(name_);
	std::set<std::string> brandKeywords = parseStringToWords(brand_); 
	std::set<std::string> clothingKeywords = setUnion(nameKeywords, brandKeywords); 
	return clothingKeywords; 

}


bool Clothing::isMatch(std::vector<std::string>& searchTerms) const {
	return false;
}


std::string Clothing::displayString() const {
	return name_ + "\n" + "Size: " + size_ + " " + "Brand: " + brand_; 
}


void Clothing::dump(std::ostream& os) const {
	Product::dump(os); 
	os << size_ << "\n" << brand_ << "\n";
}


std::string Clothing::getSize() const {
	return size_;
}


std::string Clothing::getBrand() const {
	return brand_; 
	
}