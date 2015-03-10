 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/13/15    |
 * | HW 3                       |
 * ==============================
 * 
 *	Filename: setint.cpp 
 *
 *  Directions from bits.usc.edu/cs104/assignments/hw3:
 * 
 *      Implement a basic Set class using your 
 *      LListInt implementation in Problem 2. 
 * 
 */


#include "../lib/setint.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;


/* SetInt default constructor */
SetInt::SetInt() {
	iter_ = 0; 
}


/* SetInt destructor */
SetInt::~SetInt() {
}


/* SetInt copy constructor
 * 	Utilizes LListInt assignment overload 
 * 	and copy constructor. Return new SetInt. 
 */
SetInt::SetInt(const SetInt& other) {
	
	this->list_ = other.list_;

}


/* Assignment= operator overload 
 * 	Utilizes LListInt assignment overload
 * 	and copy constructor. Returns new SetInt.
 */
SetInt& SetInt::operator=(const SetInt& other) {	

	if (this == &other) return *this;
	this->list_ = other.list_;
	return *this;

}


/* Returns the current number of items in the list */
int SetInt::size() const {
	return list_.size();
}


/* Returns true if the list is empty, false otherwise */
bool SetInt::empty() const {
	return list_.empty(); 
}


/* Inserts val so it appears at index, pos */
void SetInt::insert(const int& val) {

	if (!exists(val)) {
		list_.push_back(val); 
	}

}


/* Remove the value at index, pos */
void SetInt::remove(const int& val) {

	if (exists(val)) {
		int pos = getIndex(val); 
		list_.remove(pos);		
	}

}


/* Returns true if the item is in the set */
bool SetInt::exists(const int& val) const {

	for (int i = 0; i < list_.size(); i++) {
		if (list_.get(i) == val) {
			return true;
		}
	}
	return false;

}


/* Return a pointer to the first item
 * and support future calls to next()
 */
int const* SetInt::first() {

	iter_ = 0; 

	if (empty()) {
		return NULL;
	} 

	int* head = &(list_.get(iter_)); 
	iter_++;
	return head;

}


/* Return a pointer to the next item
 * after the previous call to next 
 * and NULL if you reach the end
 */
int const* SetInt::next() {

	if (!empty()) {
		if (iter_ < list_.size()) {
			int* next = &(list_.get(iter_)); 
			iter_++;
			return next;
		}
	}
	return NULL; 
}


/* Returns another (new) set that contains
 * the union of this set and "other"
 */
SetInt SetInt::setUnion(const SetInt& other) const {	//how to make more efficient???

	SetInt s = other;

	for (int i = 0; i < list_.size(); i++) {
		int val = list_.get(i); 
		if (!s.exists(val)) {
			s.insert(val); 
		}
	}

	return s;
}


/* Returns another (new) set that contains 
 * the intersection of this set and "other"
 */
SetInt SetInt::setIntersection(const SetInt& other) const {

	SetInt s;

	if (other.empty() && empty()) {
		return s;
	}

	if (other.empty() && !empty()) {
		s = *this;
		return s;
	}

	if (!other.empty() && empty()) {
		s = other;
		return s; 
	}

	for (int i = 0; i < other.size(); i++) {
		int val = other.list_.get(i); 
		if (exists(val)) {
			s.insert(val);
		}
	}

	return s;

}


/* Operator | overload. Returns new SetInt from 
 * setUnion()
 */
SetInt SetInt::operator|(const SetInt& other) const {
	return setUnion(other); 
}


/* Operator & overload. Returns new SetInt from
 *  setIntersection()
 */
SetInt SetInt::operator&(const SetInt& other) const {
	return setIntersection(other); 
}


/* Return the index of item with value val */
int SetInt::getIndex(int val) const {
	for (int i = 0; i < list_.size(); i++) {
		if (list_.get(i) == val) {
			return i; 
		}
	}
	return -1;
}