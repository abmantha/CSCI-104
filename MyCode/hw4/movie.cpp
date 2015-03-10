#include "movie.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) : 
		   Product (category, name, price, qty) {

	genre_ = convToLower(genre);
	rating_ = rating; 

}


Movie::~Movie() {
}


std::set<std::string> Movie::keywords() const {

	/* Valid keywords are: 
	 *  product name
	 *  genre
	 */

	std::set<std::string> nameKeywords = parseStringToWords(name_);
	std::set<std::string> movieKeywords = nameKeywords;
	movieKeywords.insert(genre_);
	return movieKeywords; 

}


bool Movie::isMatch(std::vector<std::string>& searchTerms) const {
	return false;
}


std::string Movie::displayString() const {
	return name_ + "\n" + "Genre: " + genre_ + " " + "Rating: " + rating_; 
}


void Movie::dump(std::ostream& os) const {
	Product::dump(os);
	os << genre_ << "\n" << rating_ << "\n";
}


std::string Movie::getGenre() const {
	return genre_;
}


std::string Movie::getRating() const {
	return rating_; 
}