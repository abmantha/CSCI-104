 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *  Filename: alisttest.cpp 
 *
 *  Test file for the alistint.h and alistint.cpp implementation files.     
 */
#include "lib/alistint.h"
#include <iostream>
#include <limits>
using namespace std;

/* Function prototype */
void testStack(AListInt& a);

/* Executes testing for the AListInt class */
int main (int argc, char *argv[]) {
	
    cout << "ALISTINT -- BEGIN TESTING!" << endl;
    cout << endl;

     cout << "TESTING DEFAULT CONSTRUCTOR." << endl;
     AListInt a1;
     testStack(a1);
     cout << endl;

    cout << "TESTING ALTERNATE CONSTRUCTOR." << endl;
    AListInt a2(3);
    testStack(a2);
    cout << endl; 

    cout << "ALL TESTING IS COMPLETE!" << endl;

	return 0; 
}

void testStack(AListInt& a) {

    // Check that list is initially empty
    if (a.empty()) {
        cout << "SUCCESS: AList is initially empty." << endl;
    } else {
        cout << "FAIL: Unexpected elements living in AList." << endl;
    }

    // Check that size is 0
    if (a.size() == 0) {
        cout << "SUCCESS: AList has size 0 when empty." << endl;
    } else {
        cout << "FAIL: AList actually has size " << a.size() << endl;
    }

    // Get from an empty list
    cout << "Trying to get an item from an empty list." << endl;
    if (a.get(0) == numeric_limits<int>::min()) {
        cout << "SUCCESS: No items to get from empty list." << endl;
    } else {
        cout << "FAIL: Unexpected elements living in AList." << endl;
    }

    // Set element in empty list
    cout << "Trying to set an item in an empty list." << endl;
    a.set(0, 700); 
    if (a.get(0) == numeric_limits<int>::min()) {
        cout << "SUCCESS: No items to set in empty list." << endl;
    } else {
        cout << "FAIL: Unexpected elements living in AList." << endl;
    }

    cout << endl;

    cout << "Inserting 1 element at 0th index." << endl;
    a.insert(0, 2.2); 

    if (a.size() == 1) {
        cout << "SUCCESS: AList has size 1 after 1 insertion at 0th index." << endl;
    } else {
        cout << "FAIL: AList has size " << a.size() << " after 1 insertion at 0th index." << endl;
    }

    if (!a.empty()) {
        cout << "SUCCESS: AList is not empty." << endl;
    } else {
        cout << "FAIL: AList did not insert element properly." << endl;
    }

    if (a.get(0) == a.get(a.size()-1)) {
        cout << "SUCCESS: 0th index = size()-1 for a list of size 1." << endl;
    } else {
        cout << "FAIL: 0th index does not equal size()-1 for a list of size 1." << endl;
    }

    a.remove(0); 
    cout << endl;

    cout << "Inserting 1 element at last index." << endl;
    if (a.size() == 1) {
        cout << "SUCCESS: AList has size 1 after 1 insertion at last index." << endl;
    } else {
        cout << "FAIL: AList has size " << a.size() << " after 1 insertion at last index." << endl;
    }

    if (!a.empty()) {
        cout << "SUCCESS: AList is not empty." << endl;
    } else {
        cout << "FAIL: AList did not insert element properly." << endl;
    }

    if (a.get(0) == a.get(a.size()-1)) {
        cout << "SUCCESS: 0th index = size()-1 for a list of size 1." << endl;
    } else {
        cout << "FAIL: 0th index does not equal size()-1 for a list of size 1." << endl;
    }

    a.remove(a.size()-1);
    cout << endl;

    cout << "Creating an AList of 5." << endl;
    for (int i = 0; i < 5; i++) {
        a.insert(i, 2.2+i); 
    }

    if (a.size() == 5) {
        cout << "SUCCESS: All 5 elements inserted." << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
        }
    } else {
        cout << "FAIL: Size is actually " << a.size() << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
        }
    }

    cout << endl;

    cout << "Trying to insert element at 7th index." << endl;
    a.insert(7, 7.7); 

    if (a.size() == 5) {
        cout << "SUCCESS: Size remains 5 because 7th index is out of bounds." << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
        }
    } else {
        cout << "FAIL: Insertion does not work properly. Size is actually " << a.size() << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
        }
    }

    cout << "Tyring to remove element from -1th index." << endl;
    a.remove(-1); 
    if (a.size() == 5) {
        cout << "SUCCESS: Size remains 5 because -1th index is out of bounds." << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
        }
    } else {
        cout << "FAIL: Removal does not work properly. Size is actually " << a.size() << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
        }
    }

    cout << endl;

    cout << "Trying to get an element from the 2nd index." << endl;
    if (a.get(2) == 4.2) {
        cout << "SUCCESS: The element at the 2nd index is 4.2." << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
        }
    } else {
        cout << "FAIL: The element at the 2nd index is actually " << a.get(2) << endl;
    }

    cout << "Trying to get an element from the 10th index." << endl;
    if (a.get(10) == numeric_limits<int>::min()) {
        cout << "SUCCESS: There is no element at the 10th index." << endl;
    } else {
        cout << "FAIL: The element at the 10th index is " << a.get(10) << endl;
    }

    cout << "Trying to set an element from the 3rd index." << endl;
    a.set(3, 56); 
    if (a.get(3) == 56) {
        cout << "SUCCESS: The element at the 3rd index now has value of 56." << endl;
    } else {
        cout << "FAIL: The element at the 3rd index now has value of " << a.get(3) << endl;
    }

    cout << "Trying to set an element from the 100th index." << endl;
    a.set(100, 234); 
    if (a.get(100) == numeric_limits<int>::min()) {
        cout << "SUCCESS: The is no element at the 100th index to set the value of." << endl;
    } else {
        cout << "FAIL: There is an element at the 100th index. It's value is " << a.get(100) << endl;
    }

    int size = a.size(); 
    for (int i = 0; i < size; i++) {
        a.remove(0); 
    }

    cout << endl;

    for (int i = 0; i < 10; i++) {
        a.insert(0, i+5); 
    }

    for (int i = 0; i < a.size(); i++) {
        cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
    }

    cout << "Trying to insert at next available position." << endl;
    a.insert(10, 67); 

    if (a.get(10) == 67) {
        cout << "SUCCESS: AList has doubled its capacity for more variables." << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
        }
    } else {
        cout << "FAIL: AList has not doubled its capacity for more variables." << endl;
    }

    cout << "Remove element from 8th index." << endl;
    a.remove(8); 
    if (a.size() == 10) {
        cout << "SUCCESS: The size of AList is 10." << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << "Contents of AList at " << i << ": " << a.get(i) << endl;
        }

    } else {
        cout << "FAIL: The size of AList is actually " << a.size() << endl;
    }

    cout << "Inserting value at 15th index." << endl;
    a.insert(15, 7779); 
    if (a.size() == 10) {
        cout << "SUCCESS: Size remains 10 because the 15th index is out of bounds." << endl;
    } else {
        cout << "FAIL: Size does not remain 10: " << a.size() << " because the 15th index is within bounds " << a.get(15) << endl;
    }

    cout << "FINISHED TESTING STACK" << endl;
}
