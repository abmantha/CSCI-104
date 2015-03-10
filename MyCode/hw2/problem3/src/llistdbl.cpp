 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *	Filename: llistdbl.cpp 
 *
 *  Directions from bits.usc.edu/cs104/assignments/hw2:
 * 
 *    Examine the code provided below and complete the 
 *    insert() and remove() member functions in llistdbl.cpp
 *    
 */

#include "../lib/llistdbl.h"
#include <cstdlib>

/* LListDbl constructor */
LListDbl::LListDbl() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}


/* LListDbl destructor -- delete  allocated memory */
LListDbl::~LListDbl() {
  clear();
}


/* Returns true if the list is empty, false otherwise */
bool LListDbl::empty() const {
  return size_ == 0;
}


/* Returns the current number of items in the list */
int LListDbl::size() const {
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
void LListDbl::insert(int loc, const double& val) {
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
void LListDbl::remove(int loc) {
	if (loc >= 0 && loc < size()) {

		if (empty()) {	
			return; 

		} else if (size() == 1) {	
			delete head_;
			head_ = NULL;
			tail_ = NULL; 

		} else if (loc == 0) {
			Item* currHead = head_; 
			head_ = head_->next;	
			head_->prev = NULL;
			delete currHead; 

		} else if (loc == size()-1) {	
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
void LListDbl::set(int loc, const double& val) {
  Item *temp = getNodeAt(loc);
  temp->val = val;
}


/* Returns the value at index, pos */
double& LListDbl::get(int loc) {
  Item *temp = getNodeAt(loc);
  return temp->val;
}


/* Returns the value at index, pos */
double const & LListDbl::get(int loc) const {
  Item *temp = getNodeAt(loc);
  return temp->val;
}


/* Deletes all items in the list */
void LListDbl::clear() {
  while(head_ != NULL) {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/* Returns a pointer to the item at index, pos and NULL otherwise */
LListDbl::Item* LListDbl::getNodeAt(int loc) const {
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
