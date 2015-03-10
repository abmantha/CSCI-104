 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/13/15    |
 * | HW 3                       |
 * ==============================
 * 
 *	Filename: llistint.cpp 
 *
 *	Implementation details of the llistint.h class.     
 */

#include "../lib/llistint.h"
#include <cstdlib>
#include <iostream>
using namespace std;

/* LListInt constructor */
LListInt::LListInt() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}


/* LListInt destructor -- delete  allocated memory */
LListInt::~LListInt() {
  clear();
}


/* Function: LListInt
 * Usage: LListInt l2 (l1)
 * ========================================================
 * This is the copy constructor for the LListInt class. 
 * It makes a deep of a LListInt and returns a new LListInt
 * object. It resets all variables and copies over elements 
 * from the argument LListInt to the LListInt pointed to by
 * this. Guaranteed deep copy in O(n) time. 
 */
LListInt::LListInt(const LListInt& other) {

	this->head_ = NULL;
	this->tail_ = NULL;
	this->size_ = 0; 

	Item* otherHead = other.head_; 

	if (otherHead == NULL) {
		this->head_ = NULL; 
	} else {
		while (otherHead != NULL) {			
			push_back(otherHead->val); 		
			otherHead = otherHead->next; 
		}
	}

}


/* Function: operator=
 * Usage: list2 = list1
 * ========================================================
 * This is the assignment= overloaded operator for the 
 * LListInt class. It deletes all dynamically allocated memory
 * of the old lefthand list and allocates new memory while 
 * copying over the contents of the righthand list, named other.
 * It access the lefthand list using this. Guaranteed deep copy
 * in O(n) time. 
 */ 
LListInt& LListInt::operator=(const LListInt& other) {	


	if (this == &other) return *this;
	this->clear();							
	Item *otherHead = other.head_;
	while (otherHead != NULL) {				
		push_back(otherHead->val);
		otherHead = otherHead->next;
	}
	return *this;
	

}


/* Returns true if the list is empty, false otherwise */
bool LListInt::empty() const {
  return size_ == 0;
}


/* Returns the current number of items in the list */
int LListInt::size() const {
  return size_;
}


/* Function: insert
 * Usage: insert(loc, val)
 * ========================================================
 * Inserts val so it appears at index, pos. Valid locations
 * are between 0 and size inclusive, where insert(0) inserts
 * to the head of the list and insert(size) inserts to the 
 * tail of the list. Dynamically creates new item struct. 
 * If the list is originally empty, then both head and tail 
 * point to the newVal. If the loc = 0, then head simply 
 * takes a step back and points to the new element, updating
 * previous head next pointer. If loc = size, then tail simply 
 * takes a step forward and points to the new element, 
 * updating previous tail next pointer. At any other position,
 * the pointer to the current node at loc is returned,
 * and the newVal's pointers are updated appropriately. Finally,
 * the size of the list increments by 1. 
 */
void LListInt::insert(int loc, const int& val) {
	if (loc >= 0 && loc <= size_) {
		
		Item* newVal = new Item; 
		newVal->val = val;
		newVal->prev = NULL; 
		newVal->next = NULL; 

		if (empty()) { 
			head_ = newVal; 
			tail_ = newVal;

		} else if (loc == 0) { 
			newVal->next = head_;
			head_->prev = newVal;
			head_ = newVal;
			
		} else if (loc == size_) { 
			newVal->prev = tail_;
			tail_->next = newVal;
			tail_ = newVal;
			
		} else {	
			Item* curr = getNodeAt(loc); 
			curr->prev->next = newVal;
			newVal->prev = curr->prev; 
			newVal->next = curr;
			curr->prev = newVal; 
		}

		size_++;

	}
}

/* Function: push_back
 * Usage: list.push_back(6);
 * ========================================================
 * Inserts a new element to the back of the list. This 
 * operation takes O(1) time. 
 */

void LListInt::push_back(const int& val) {

	Item* newVal = new Item;
	newVal->val = val; 
	newVal->prev = NULL;
	newVal->next = NULL;

	if (empty()) {		/* Is this necessary? */
		head_ = newVal; 
		tail_ = newVal; 

	} else {
		newVal->prev = tail_;
		tail_->next = newVal;
		tail_ = newVal;
	}
	size_++; 
}


/* Function: remove
 * Usage: remove(loc) 
 * ========================================================
 * Removes the value at index, pos. Valid positions are 
 * between 0 and size-1 inclusive. If the list is empty,
 * the function returns immediately. Otherwise, if there 
 * is only one element in the list, then the head pointer 
 * is deleted and both head and tail are NULL. Removing 
 * from the head_, the current head steps forward, while
 * the pointer to the previous head is deleted. Removing 
 * from the tail_, the current tail steps backward, while 
 * the pointer to the previous tail is deleted. Removing 
 * at any other position requires using a pointer to the 
 * location node and updating it's neighboring pointer 
 * values and next and prev pointers, effectively excising
 * itself from the list. That pointer to the location node
 * is then deleted. 
 */
void LListInt::remove(int loc) {
	if (loc >= 0 && loc < size_) {

		if (empty()) {	
			return; 

		} else if (size_ == 1) {	
			delete head_;
			head_ = NULL;
			tail_ = NULL; 

		} else if (loc == 0) {
			Item* currHead = head_; 
			head_ = head_->next;	
			head_->prev = NULL;
			delete currHead; 

		} else if (loc == size_-1) {	
			Item* currTail = tail_;	
			tail_ = tail_->prev;	
			tail_->next = NULL; 
			delete currTail; 

		} else {	
			Item* curr = getNodeAt(loc); 
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr; 
		}

		size_--; 

	}
}


/* Overwrites the old value at index, pos, with val */
void LListInt::set(int loc, const int& val) {
  Item *temp = getNodeAt(loc);
  temp->val = val;
}


/* Returns the value at index, pos */
int& LListInt::get(int loc) {
  Item *temp = getNodeAt(loc);
  return temp->val;
}


/* Returns the value at index, pos */
int const & LListInt::get(int loc) const {
  Item *temp = getNodeAt(loc);
  return temp->val;
}


/* Deletes all items in the list */
void LListInt::clear() {
  while(head_ != NULL) {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/* Returns a pointer to the item at index, pos and NULL otherwise */
LListInt::Item* LListInt::getNodeAt(int loc) const {
  Item *temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}
