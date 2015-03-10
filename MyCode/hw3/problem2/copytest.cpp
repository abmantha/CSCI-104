 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/13/15    |
 * | HW 3                       |
 * ==============================
 * 
 * 	Filename: copytest.cpp
 * 
 * 	Test file for the llistint.h and llistint.cpp file
 */
#include "lib/llistint.h"
#include <iostream>
using namespace std;

/* Function prototypes */
void basicTesting(LListInt& list); 
void pushBackTesting(LListInt& list); 
void copyConstructorTesting(LListInt& list);
void assignmentOverloadTesting(LListInt& list);

/* Executes testing for LListInt class */
int main (int argc, char *argv[]) {

	cout << "LLISTINT -- BEGIN TESTING!" << endl;
	cout << endl;

	LListInt list1; 
	basicTesting(list1); 
	pushBackTesting(list1); 
	copyConstructorTesting(list1);
	assignmentOverloadTesting(list1); 

	cout << "ALL TESTING IS COMPLETE!" << endl;

	return 0; 
}


/* Testing basic functions */
void basicTesting(LListInt& list) {
	cout << "BASIC TESTING." << endl;
	if (list.empty()) {
		cout << "SUCCESS: LList is initially empty." << endl;
	} else {
		cout << "FAIL: Unexpected elements living in LList." << endl;
	}

	if (list.size() == 0) {
		cout << "SUCCESS: LList size is expected to be 0." << endl;
	} else {
		cout << "FAIL: LList size is actually " << list.size() << endl;
	}

	cout << "Inserting 5 elements." << endl;
	for (int i = 0; i < 5; i++) {
		list.insert(0, i+4); 
	}

	if (list.size() == 5) {
		cout << "SUCCESS: LList size is expected to be 5." << endl;
	} else {
		cout << "FAIL: LList size is actually " << list.size() << endl;
	}

	cout << "Print list contents." << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << "Element at " << i << ": " << list.get(i) << endl;
	}

	cout << "Removing element from 2 index." << endl;
	list.remove(2);

	if (list.size() == 4) {
		cout << "SUCCESS: LList size is expected to be 4." << endl;
	} else {
		cout << "FAIL: LList size is actually " << list.size() << endl;
	}

	cout << "This is the first element in the list: " << list.get(0) << endl;
	cout << "This is the last element in the list: " << list.get(list.size()-1) << endl; 
	cout << "Changing first element to 12." << endl;
	list.set(0, 12); 
	cout << "This is the first element in the list now: " << list.get(0) << endl;
	cout << "Changing last element to 7." << endl;
	list.set(list.size()-1, 7); 
	cout << "This is the last element in the list now: " << list.get(list.size()-1) << endl;
	
	if (list.size() == 4) {
		cout << "SUCCESS: LList size is expected to be 4." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << ": " << list.get(i) << endl;
		}
	} else {
		cout << "FAIL: LList size is actually " << list.size() << endl;
	}

	cout << endl;

}


/* Testing push_back function */
void pushBackTesting(LListInt& list) {
	cout << "TESTING push_back() FUNCTION." << endl;

	cout << "Current list size: " << list.size() << endl;
	cout << "Pushing back new element to list." << endl;
	list.push_back(67); 

	if (list.size() == 5) {
		cout << "SUCCESS: push_back pushes new element to back of list." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << ": " << list.get(i) << endl;
		}
	} else {
		cout << "FAIL: LList size is actually " << list.size() << endl;
	}

	if (list.get(list.size()-1) == 67) {
		cout << "SUCCESS: Last element is 67." << endl;
	} else {
		cout << "FAIL: Last element in list is " << list.get(list.size()-1) << endl;
	}
	cout << endl;
}


/* Testing the copy constructor */
void copyConstructorTesting(LListInt& list) {
	cout << "COPY CONSTRUCTOR TESTING." << endl;
	LListInt list2(list); 

	if (list.size() == list2.size()) {
		cout << "SUCCESS: Both lists have the same number of elements." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list2: " << list.get(i) << endl;
		}
	} else {
		cout << "FAIL: Both lists have different sizes." << endl;
		cout << "FAIL: List1 size -- " << list.size() << endl;
		cout << "FAIL: List2 size -- " << list2.size() << endl;
	}

	cout << "Inserting new element to list." << endl;
	list.push_back(56); 

	if (list.size() != list2.size()) {
		cout << "SUCCESS: list and list2 don't have the same elements any more." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list2.size(); i++) {
			cout << "Element at " << i << " in list2: " << list.get(i) << endl;
		}
	} else {
		cout << "FAIL: list and list2 have the same elements. Copy constructor has failed." << endl;
	}

	cout << "Inserting two new elements to list2." << endl;
	list2.insert(0, 65);
	list2.push_back(1);

	if (list.size() != list2.size()) {
		cout << "SUCCESS: list and list2 don't have the same elements any more." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list2.size(); i++) {
			cout << "Element at " << i << " in list2: " << list2.get(i) << endl;
		}
	} else {
		cout << "FAIL: list and list2 have the same elements. Copy constructor has failed." << endl;
	}

	cout << "Removing three elements from list." << endl;
	list.remove(0);
	list.remove(1);
	list.remove(2); 
	if (list.size() != list2.size()) {
		cout << "SUCCESS: list and list2 don't have the same elements any more." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list2.size(); i++) {
			cout << "Element at " << i << " in list2: " << list2.get(i) << endl;
		}
	} else {
		cout << "FAIL: list and list2 have the same elements. Copy constructor has failed." << endl;
	}

	cout << "Removing one element from list2." << endl;
	list2.remove(0); 
	if (list.size() != list2.size()) {
		cout << "SUCCESS: list and list2 don't have the same elements any more." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list2.size(); i++) {
			cout << "Element at " << i << " in list2: " << list2.get(i) << endl;
		}
	} else {
		cout << "FAIL: list and list2 have the same elements. Copy constructor has failed." << endl;
	}
	cout << endl;
}


/* Testing the assignment overload operator */
void assignmentOverloadTesting(LListInt& list) {
	cout << "ASSIGNMENT OVERLOAD TESTING." << endl;
	cout << "Setting new list2 equal to list." << endl;
	LListInt list2;
	list2 = list; 

	if (list.size() == list2.size()) {
		cout << "SUCCESS: Both lists have the same number of elements." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list2: " << list.get(i) << endl;
		}
	} else {
		cout << "FAIL: Both lists have different sizes." << endl;
		cout << "FAIL: List1 size -- " << list.size() << endl;
		cout << "FAIL: List2 size -- " << list2.size() << endl;
	}

	cout << "Inserting new element to list." << endl;
	list.push_back(56); 

	if (list.size() != list2.size()) {
		cout << "SUCCESS: list and list2 don't have the same elements any more." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list2.size(); i++) {
			cout << "Element at " << i << " in list2: " << list.get(i) << endl;
		}
	} else {
		cout << "FAIL: list and list2 have the same elements. Copy constructor has failed." << endl;
	}

	cout << "Inserting two new elements to list2." << endl;
	list2.insert(0, 65);
	list2.push_back(1);

	if (list.size() != list2.size()) {
		cout << "SUCCESS: list and list2 don't have the same elements any more." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list2.size(); i++) {
			cout << "Element at " << i << " in list2: " << list2.get(i) << endl;
		}
	} else {
		cout << "FAIL: list and list2 have the same elements. Copy constructor has failed." << endl;
	}

	cout << "Removing three elements from list." << endl;
	list.remove(0);
	list.remove(1);
	list.remove(2); 
	if (list.size() != list2.size()) {
		cout << "SUCCESS: list and list2 don't have the same elements any more." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list2.size(); i++) {
			cout << "Element at " << i << " in list2: " << list2.get(i) << endl;
		}
	} else {
		cout << "FAIL: list and list2 have the same elements. Copy constructor has failed." << endl;
	}

	cout << "Removing one element from list2." << endl;
	list2.remove(0); 
	if (list.size() != list2.size()) {
		cout << "SUCCESS: list and list2 don't have the same elements any more." << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << "Element at " << i << " in list: " << list.get(i) << endl;
		}
		for (int i = 0; i < list2.size(); i++) {
			cout << "Element at " << i << " in list2: " << list2.get(i) << endl;
		}
	} else {
		cout << "FAIL: list and list2 have the same elements. Copy constructor has failed." << endl;
	}
	cout << endl;
}