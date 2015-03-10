 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *  Filename: stacktest.cpp 
 *
 *  Test file for the stackdbl.h and stackdbl.cpp implementation files.     
 */
#include "lib/stackdbl.h"
#include <iostream>
#include <limits>
using namespace std;

/* Executes testing for the StackDbl class */
int main (int argc, char *argv[]) {

	cout << "STACKDBL -- BEGIN TESTING!" << endl;
    cout << endl;

	StackDbl s;

	// Check that stack is initially empty
	if (s.empty()) {
		cout << "SUCCESS: Stack is initially empty." << endl;
	} else {
		cout << "FAIL: Stack is not initially empty." << endl;
	}

	cout << endl;

	// Check that you can't pop from or top an empty stack
	cout << "Trying to top an element from empty stack." << endl;
	if (s.top() == numeric_limits<int>::min()) {
		cout << "SUCCESS: Not possible to retrieve an element in an empty stack." << endl;
	} else {
		cout << "FAIL: Unexpected behavior. No elements should be on an empty stack." << endl;
	}

	cout << endl;

	cout << "Trying to pop an element off empty stack." << endl;
	s.pop(); 

	if (s.empty()) {
		cout << "SUCCESS: Not possible to retrieve an element in an empty stack. Size remains 0." << endl;
	} else {
		cout << "FAIL: Unexpected behavior. No elements should be on an empty stack." << endl;
	}

	cout << endl;

	cout << "Pushing 5 elements on stack." << endl;
	int size = 0; 
	for (int i = 0; i < 5; i++) {
		size++; 
		s.push(i); 
	}

	cout << endl;

	if (!s.empty()) {
		cout << "SUCCESS: Size is " << size << "." << endl;
	} else {
		cout << "FAIL: Something wrong in pushing elements to stack." << endl;
	}

	cout << endl;

	cout << "Popping all elements from stack." << endl;
	while (!s.empty()) {
		size--; 
		s.pop(); 
	}

	cout << endl;

	if (s.empty() && size == 0) {
		cout << "SUCCESS: All 5 elements have been popped." << endl;
	} else {
		cout << "FAIL: Error in popping all elements from stack." << endl;
	}

  	cout << "ALL TESTING IS COMPLETE!" << endl;

	return 0; 
}


/* 

	1. Pop off an empty stack
	2. Top off an empty stack
	3. Return size of empty stack

	4. Make sure pop reorders elements correctly
	5. Push an element
	6. Push negative elements
	7. Push repeat values

*/ 