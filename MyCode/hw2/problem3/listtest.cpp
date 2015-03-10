 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *  Filename: listtest.cpp 
 *
 *  Test file for the llistdbl.h and llistdbl.cpp implementation files.     
 */
#include "lib/llistdbl.h"
#include <iostream>
using namespace std;

/* Executes testing for the LListDbl class */
int main() {
  LListDbl * list = new LListDbl();

  cout << "LLISTDBL -- BEGIN TESTING!" << endl;
  cout << endl;

  cout << "When inserting at and removing from 0: " << endl;
  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // Insert an item at the head.
  list->insert(0, 3.3);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  // Check that the size has changed 
  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 3.3) {
    cout << "SUCCESS: 3.3 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3.3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  cout << "Inserting new element to end of list" << endl;
  list->insert(list->size(), 5.5); 

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after two insertions." << endl;
  } else {
    cout << "FAIL: List is empty after two insertions." << endl;
  }

  // Check that the size has changed 
  if (list->size() == 2) {
    cout << "SUCCESS: List has size 2 after two insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(list->size()-1) == 5.5) {
    cout << "SUCCESS: 5.5 is at the last index of the list." << endl;
  } else {
    cout << "FAIL: 5.5 is not at the last index of the list, " << list->get(list->size()-1);
    cout << " is instead." << endl;
  }

  cout << endl;

  list->clear(); 
  cout << "Testing removal from 0th index and size-th index." << endl;

  list->insert(0, 3.3);

  cout << "Removing from 0th index." << endl;
  list->remove(0);

  //Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty after removing only element." << endl;
  } else {
    cout << "FAIL: List is not empty after removing only element when it should be." << endl;
  }

  //Check that the size has changed 
  if (list->size() == 0) {
    cout << "SUCCESS: List has size 0 after removing one element." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after removing one element.";
  }

  //Inserting element at size-th index
  list->insert(list->size(), 5.5); 

  cout << "Removing from last index." << endl;
  list->remove(list->size()-1); 

  if (list->empty()) {
    cout << "SUCCESS: List is empty after removing only element." << endl;
  } else {
    cout << "FAIL: List is not empty after removing only element when it should be." << endl;
  }

  //Check that the size has changed 
  if (list->size() == 0) {
    cout << "SUCCESS: List has size 0 after removing one element." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after removing one element.";
  }

  cout << endl;

  list->clear();
  cout << "Testing insert and remove when position out of bounds." << endl;

  list->insert(0, 6.6);
  list->insert(3, 8.8);  
  if (list->size() == 1) {
  	cout << "SUCCESS: Can not insert to a position out of bounds." << endl;
  } else {
  	cout << "FAIL: Value was incorrectly inserted at position out of bounds." << endl;
  }

  list->remove(3); 
  if (list->size() == 1) {
  	cout << "SUCCESS: Can not remove from a position out of bounds." << endl;
  } else {
  	cout << "FAIL: Value was incorrectly removed at position out of bounds." << endl;
  }

  cout << endl;

  list->clear(); 
  cout << "Testing if get(0) = get(size()-1) on list of size 1." << endl;

  list->insert(0, 7.7); 

  if (list->get(0) == list->get(list->size()-1)) {
  	cout << "SUCCESS: list->get(0) and list->get(list->size()-1) return the same value for a list of size 1." << endl;
  } else {
  	cout << "FAIL: list->get(0) = " << list->get(0) << " and list->get(list->size()-1) = " << list->get(list->size()-1); 
  }

  list->set(list->size()-1, 9.9); 

  if (list->get(0) == list->get(list->size()-1)) {
  	cout << "SUCCESS: list->get(0) and list->get(list->size()-1) return the same value for a list of size 1." << endl;
  } else {
  	cout << "FAIL: list->get(0) = " << list->get(0) << " and list->get(list->size()-1) = " << list->get(list->size()-1); 
  }

   cout << endl;

  list->clear(); 
  cout << "Creating a list of size 10." << endl;

  for (int i = 0; i < 10; i++) {
  	list->insert(i, 5+i); 
  }

  if (list->size() == 10) {
  	cout << "SUCCESS: List has size 10 after 10 insertions." << endl;
  } else {
  	cout << "FAIL: List does not have size 10 after 10 insertions." << endl;
  }

  for (int i = 0; i < list->size(); i++) {
  	cout << "Contents of list at " << i << ": " << list->get(i) << endl;
  }

  cout << "Removing 10 items from a list of size 10." << endl;
  for (int i = 0; i < 10; i++) {
  	list->remove(0); 
  }

  if (list->size() == 0) {
  	cout << "SUCCESS: List has size of 0 after removing all 10 elements." << endl;
  } else {
  	cout << "FAIL: List does not have size 0 after removing all 10 elements.";
  	cout << "It has " << list->size() << " instead." << endl;
  }

  cout << "Trying to remove an element from an empty list: " << endl;
  list->remove(0); 

  if (list->size() == 0) {
  	cout << "SUCCESS: It is not possible to remove from an empty list." << endl;
  } else {
  	cout << "FAIL: Size of list is actually: " << list->size() << endl;
  }

  cout << endl;

  list->clear(); 
  cout << "Inserting into and removing from middle elements of list." << endl;
  cout << "Creating a list of size 20 by inserting at 0th index." << endl;

  for (int i = 0; i < 20; i++) {
  	list->insert(0, i+6);
  }

  if (list->size() == 20) {
  	cout << "SUCCESS: List has size 20 after 20 insertions to index 0." << endl;
  	for (int i = 0; i < list->size(); i++) {
	  	cout << "Contents of list at " << i << ": " << list->get(i) << endl;
  	}
  } else {
  	cout << "FAIL: List does not have size 20 after 20 insertions to index 0.";
  	cout << "It has " << list->size() << " instead." << endl;
  }

  cout << "Inserting into 5th index." << endl;
  list->insert(5, 1); 

  if (list->get(5) == 1) {
  	cout << "SUCCESS: Value at 5th index is 1." << endl;
  	for (int i = 0; i < list->size(); i++) {
  		cout << "Contents of list at " << i << ": " << list->get(i) << endl;
  	}
  } else {
  	cout << "FAIL: Value at 5th index is " << list->get(5) << endl;
  }

  if (list->size() == 21) {
  	cout << "SUCCESS: Insertion into middle of list is successful." << endl;
  } else {
  	cout << "FAIL: Insertion into middle of list is not successful. Size is " << list->size() << endl;
  }

  cout << "Removing from 6th, 10th, and 17th index" << endl;
  list->remove(6);
  list->remove(10); 
  list->remove(17);

  if (list->size() == 18) {
  	cout << "SUCCESS: Removal from middle of list is successful." << endl;
  	for (int i = 0; i < list->size(); i++) {
  		cout << "Contents of list at " << i << ": " << list->get(i) << endl;
  	}
  } else {
  	cout << "FAIL: Removal from middle of list is not successful. Size is " << list->size() << endl;
  }


  cout << "ALL TESTING IS COMPLETE!" << endl;

  // Clean up memory.
  delete list;
}