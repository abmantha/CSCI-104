 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/13/15    |
 * | HW 3                       |
 * ==============================
 * 
 * 	Filename: settest.cpp
 * 
 * 	Test file for the setint.h and setint.cpp file
 */
#include "lib/setint.h"
#include <iostream>
using namespace std;

/* Function prototypes */
void basicTesting(SetInt& s); 
void iteratorTesting(SetInt& s);
void copyConstructorTesting(SetInt& s);
void assignmentOverloadTesting(SetInt& s);
void unionIntersectionTesting(SetInt& s); 

/* Executes testing for SetInt class*/
int main(int argc, char *argv[]) {

	cout << "SETINT -- BEGIN TESTING!" << endl;
	cout << endl;

	SetInt s; 
	basicTesting(s);
	iteratorTesting(s);
	copyConstructorTesting(s);
	assignmentOverloadTesting(s); 
	unionIntersectionTesting(s); 

	cout << "ALL TESTING IS COMPLETE!" << endl;

	return 0; 
}


/* Testing basic functions */
void basicTesting(SetInt& s) {
	cout << "BASIC TESTING." << endl;

	if (s.empty()) {
		cout << "SUCCESS: Set is initially empty." << endl;
	} else {
		cout << "FAIL: Unexpected elements living in set." << endl;
	}
	if (s.size() == 0) {
		cout << "SUCCESS: Set size expected to be 0." << endl;
	} else {
		cout << "FAIL: Set size is actually " << s.size() << endl;
	}
	cout << "Checking if element 4 exists in empty set." << endl;
	if (!s.exists(4)) {
		cout << "SUCCESS: Empty set does not contain any elements." << endl;
	} else {
		cout << "FAIL: Element 4 does live in set." << endl;
	}

	cout << "Inserting element 4 into set." << endl;
	s.insert(4);
	if (s.size() == 1) {
		cout << "SUCCESS: Set size expected to be 1." << endl;
	} else {
		cout << "FAIL: Set size is actually " << s.size() << endl;
	}
	if (s.exists(4)) {
		cout << "SUCCESS: Element 4 does live in set." << endl;
	} else {
		cout << "FAIL: Element 4 does not live in set." << endl;
	}

	cout << "Removing element 4 from set." << endl;
	s.remove(4); 
	if (s.empty()) {
		cout << "SUCCESS: Set is now empty." << endl;
	} else {
		cout << "FAIL: Unexpected elements living in set." << endl;
	}
	if (s.size() == 0) {
		cout << "SUCCESS: Set size expected to be 0." << endl;
	} else {
		cout << "FAIL: Set size is actually " << s.size() << endl;
	}
	cout << "Checking if element 4 exists in set." << endl;
	if (!s.exists(4)) {
		cout << "SUCCESS: Element 4 does not live in set." << endl;
	} else {
		cout << "FAIL: Element 4 does live in set." << endl;
	}

	cout << "Trying to remove element 4 again." << endl;
	s.remove(4); 
	if (s.size() == 0) {
		cout << "SUCCESS: Set size expected to be 0." << endl;
	} else {
		cout << "FAIL: Set size is actually " << s.size() << endl;
	}
	if (!s.exists(4)) {
		cout << "SUCCESS: Element 4 does not live in set." << endl;
	} else {
		cout << "FAIL: Element 4 does live in set." << endl;
	}

	cout << "Inserting element 5 into set." << endl;
	s.insert(5); 
	if (s.size() == 1) {
		cout << "SUCCESS: Set size expected to be 1." << endl;
	} else {
		cout << "FAIL: Set size is actually " << s.size() << endl;
	}
	if (s.exists(5)) {
		cout << "SUCCESS: Element 5 does live in set." << endl;
	} else {
		cout << "FAIL: Element 5 does not live in set." << endl;
	}
	cout << "Trying to insert element 5 into set again." << endl;
	s.insert(5);
	if (s.size() == 1) {
		cout << "SUCCESS: Set size expected to be 1. NO REPEATS!" << endl;
	} else {
		cout << "FAIL: Set size is actually " << s.size() << endl;
	}

	cout << endl;

}


/* Testing iterator functionality */
void iteratorTesting(SetInt& s) {
	cout << "ITERATOR TESTING." << endl;

	s.insert(6); 
	s.insert(1); 
	s.insert(8);
	s.insert(10); 
	cout << "Current size of set: " << s.size() << endl;
	cout << "Printing out all elements in set via iterators." << endl;

	const int* item = s.first(); 
	cout << "First item is: " << *item << endl;
	while (item != NULL) {
		cout << "Item: " << *item << endl;
		item = s.next(); 
	}

	cout << "Reseting first iterator." << endl;
	item = s.first(); 
	if (*item == 5) {
		cout << "SUCCESS: First element in set is 6." << endl;
	} else {
		cout << "FAIL: First element in set is actually " << *item << endl;
	}

	item = s.next(); 
	if (*item == 6) {
		cout << "SUCCESS: Next element in set is 1." << endl;
	} else {
		cout << "FAIL: First element in set is actually " << *item << endl;
	}

	cout << "Iterating to last element." << endl;
	while(item != NULL) {
		item = s.next(); 
	}

	cout << "Inserting new element at end." << endl;
	s.insert(2); 
	if (item == NULL) {
		cout << "SUCCESS: Element at end is NULL." << endl;
		cout << "Expected behavior. List is modified. However, iterator is not tracking insertions or removals. Must reset iterator." << endl;
	} else {
		cout << "FAIL: Element at end is actually " << *item << endl;
	}

	cout << "All elements in set with new insertion 2." << endl;
	cout << "Current size of set: " << s.size() << endl;
	item = s.first(); 
	while (item != NULL) {
		cout << "Item: " << *item << endl;
		item = s.next(); 	
	}
	cout << endl;

}



/* Testing copy constructor functionality */
void copyConstructorTesting(SetInt& s) {
	cout << "COPY CONSTRUCTOR TESTING." << endl;

	s.insert(6); 
	s.insert(1); 
	s.insert(8);
	s.insert(10); 
	cout << "Current size of set: " << s.size() << endl;
	cout << "Printing out all elements in set via iterators." << endl;

	const int* item = s.first(); 
	cout << "First item is: " << *item << endl;
	while (item != NULL) {
		cout << "Item: " << *item << endl;
		item = s.next(); 
	}

	cout << "Creating new set s2. Copying all elements from s using copy constructor." << endl;
	SetInt s2(s); 
	if (s.size() == s2.size()) {
		cout << "SUCCESS: Both lists have the same number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have different sizes." << endl;
		cout << "FAIL: List1 size -- " << s.size() << endl;
		cout << "FAIL: List2 size -- " << s2.size() << endl;
	}

	cout << "Inserting new element in s." << endl;
	s.insert(17); 
	if (s.size() != s2.size()) {
		cout << "SUCCESS: Both lists have different number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have same sizes." << endl;
	}

	cout << "Inserting two new elements to s2." << endl;
	s2.insert(20); 
	s2.insert(33); 
	if (s.size() != s2.size()) {
		cout << "SUCCESS: Both lists have different number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have same sizes." << endl;
	}

	cout << "Removing three elements from s." << endl;
	s.remove(8); 
	s.remove(10);
	s.remove(6); 
	if (s.size() != s2.size()) {
		cout << "SUCCESS: Both lists have different number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have same sizes." << endl;
	}

	cout << "Removing four elements s2." << endl;
	s2.remove(5);
	s2.remove(6);
	s2.remove(33); 
	if (s.size() != s2.size()) {
		cout << "SUCCESS: Both lists have different number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have same sizes." << endl;
	}
	cout << endl;

}


/* Testing assignment overloading */
void assignmentOverloadTesting(SetInt& s) {
	cout << "ASSIGNMENT OVERLOAD TESTING." << endl;

	s.insert(6); 
	s.insert(1); 
	s.insert(8);
	s.insert(10); 
	cout << "Current size of set: " << s.size() << endl;
	cout << "Printing out all elements in set via iterators." << endl;

	const int* item = s.first(); 
	cout << "First item is: " << *item << endl;
	while (item != NULL) {
		cout << "Item: " << *item << endl;
		item = s.next(); 
	}

	cout << "Creating new set s2. Copying all elements from s using assignment operator." << endl;
	SetInt s2;
	s2 = s;  
	if (s.size() == s2.size()) {
		cout << "SUCCESS: Both lists have the same number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have different sizes." << endl;
		cout << "FAIL: List1 size -- " << s.size() << endl;
		cout << "FAIL: List2 size -- " << s2.size() << endl;
	}

	cout << "Inserting 2 new element in s." << endl;
	s.insert(17); 
	s.insert(42); 
	if (s.size() != s2.size()) {
		cout << "SUCCESS: Both lists have different number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have same sizes." << endl;
	}

	cout << "Inserting two new elements to s2." << endl;
	s2.insert(20); 
	s2.insert(33); 
	if (s.size() != s2.size()) {
		cout << "SUCCESS: Both lists have different number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have same sizes." << endl;
	}

	cout << "Removing three elements from s." << endl;
	s.remove(8); 
	s.remove(10);
	s.remove(6); 
	if (s.size() != s2.size()) {
		cout << "SUCCESS: Both lists have different number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have same sizes." << endl;
	}

	cout << "Removing four elements s2." << endl;
	s2.remove(5);
	s2.remove(6);
	s2.remove(33); 
	if (s.size() != s2.size()) {
		cout << "SUCCESS: Both lists have different number of elements." << endl;
		cout << "Current size of s: " << s.size() << endl;
		const int* item = s.first(); 
		while (item != NULL) {
			cout << "Item in s: " << *item << endl;
			item = s.next(); 
		}
		cout << "Current size of s2: " << s2.size() << endl;
		const int* item2 = s2.first(); 
		while (item2 != NULL) {
			cout << "Item in s2: " << *item2 << endl;
			item2 = s2.next(); 
		}
	} else {
		cout << "FAIL: Both lists have same sizes." << endl;
	}
	cout << endl;
}


/* Testing Union and Intersection testing */
void unionIntersectionTesting(SetInt& s) {
	cout << "UNION AND INTERSECTION TESTING." << endl;

	SetInt s2;
	s2.insert(1);
	s2.insert(2);
	s2.insert(3);
	s2.insert(4);
	
	cout << "Current size of set: " << s.size() << endl;
	cout << "Printing out all elements in set via iterators." << endl;

	const int* item = s.first(); 
	while (item != NULL) {
		cout << "Item in s: " << *item << endl;
		item = s.next(); 
	}

	cout << "Current size of new set2: " << s2.size() << endl;
	cout << "Printing out all elements in set via iterators." << endl;
	const int* item2 = s2.first(); 
	while(item2 != NULL) {
		cout << "Item in s2: " << *item2 << endl;
		item2 = s2.next(); 
	}

	cout << "Creating set3 -- the union of s and s2 using setUnion function." << endl;
	SetInt s3 = s.setUnion(s2);
	if (s3.size() == 7) {
		cout << "SUCCESS: Union set s3 contains 7 elements." << endl;
		const int* item3 = s3.first();
		while (item3 != NULL) {
			cout << "Item in s3: " << *item3 << endl;
			item3 = s3.next(); 
		}
	} else {
		cout << "FAIL: Union set s3 actually contains " << s3.size() << endl;
	}

	cout << "Creating s4 -- the intersection of s and s2 using setIntersection function." << endl;
	SetInt s4 = s.setIntersection(s2);
	if (s4.size() == 2) {
		cout << "SUCCESS: Intersection set s4 contains 2 elements." << endl;
		const int* item4 = s4.first();
		while (item4 != NULL) {
			cout << "Item in s4: " << *item4 << endl;
			item4 = s4.next(); 
		}
	} else {
		cout << "FAIL: Intersection set s4 actually contains " << s4.size() << endl;
	}

	cout << "Inserting new element 10 in s3 and s4." << endl;
	s3.insert(10); 
	s4.insert(10); 

	if (s3.size() == 8) {
		cout << "SUCCESS: s3 contains 8 elements." << endl;
	} else {
		cout << "FAIL: s3 actually contains " << s3.size() << endl;
	}

	if (s4.size() == 3) {
		cout << "SUCCESS: s4 contains 3 elements." << endl;
	} else {
		cout << "FAIL: s4 actually contains " << s4.size() << endl;
	}
	

	cout << "Creating s5 -- the union of s3 and s4 using the | operator." << endl;
	cout << "Creating s6 -- the intersection of s3 and s4 using the & operator." << endl;
	SetInt s5 = s3 | s4;
	SetInt s6 = s3 & s4; 

	if (s5.size() == 8) {
		cout << "SUCCESS: Union set s5 contains 8 elements." << endl;
		const int* item5 = s5.first();
		while (item5 != NULL) {
			cout << "Item in s5: " << *item5 << endl;
			item5 = s5.next(); 
		}
	} else {
		cout << "FAIL: Union set s5 actually contains " << s5.size() << endl;
	}

	if (s6.size() == 3) {
		cout << "SUCCESS: Union set s6 contains 3 elements." << endl;
		const int* item6 = s6.first();
		while (item6 != NULL) {
			cout << "Item in s6: " << *item6 << endl;
			item6 = s6.next(); 
		}
	} else {
		cout << "FAIL: Union set s6 actually contains " << s6.size() << endl;
	}
	cout << endl;

}
