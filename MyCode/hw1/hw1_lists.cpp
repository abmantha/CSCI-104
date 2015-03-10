 /* =============================
 * | Name: Abhishek Mantha	|
 * | Email: amantha@usc.edu	|
 * | GitHub: abmantha		|
 * | Date Submitted: 1/23/15	|
 * | HW 1 			|
 * =============================
 * 
 * 1. Given two linked-lists of integers, recursively make a new linked-list 
 * (i.e. copy...leaving the original two linked-lists unchanged) such that the 
 * new list contains the concatenation of the first and second list using recursion.
 * 
 * 2. Given a linked-list of integers, recursively removes any even integer in 
 * the linked list, freeing its memory resources.
 * 
 * 3. Recursively computing the average of the numbers in the linked-list and 
 * returning that value.
 * 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;


/* Item struct provided by homework */
struct Item {
	int val;
	Item* next;
	Item (int v, Item *n) {
		val = v;
		next = n;
	}
};


/* Function prototypes */
void readLists(Item*& head1, Item*& head2, ifstream & infile); 
Item* concatenate(Item* head1, Item* head2);
Item* copy(Item* toCopy, Item* newList);
Item* traverse(Item* head); 
void createList(Item*& head, string line);
void appendElement(Item*& head, int val);
void removeEvens(Item*& head); 
double findAverage(Item* head);
int sumElements(Item* head);  
int numElements(Item* head); 
void printList(ofstream & ofile, Item* head);
void deleteMemory(Item*& head); 


/* Function: main
 * ========================================================
 * This function takes in as arguments an input and output
 * files and produces a concatentation, remove evens, and 
 * calculate average functions of the ADT linked list using
 * recursion and dynamic memory allocation. 
 */
int main(int argc, char *argv[]) {
	/* Initialize file streams  */
	ifstream infile;
	ofstream outfile; 
	infile.open(argv[1]);  
	outfile.open(argv[2]); 

	/* Declare linked list head pointers */
	Item* head1 = NULL;
	Item* head2 = NULL;
 
	/* Check file suscces */
	if (infile.fail() || outfile.fail()) {
		cout << "Problems with opening file." << endl;
		return 0; 
	}

	/* Read in integers from file and create lists */
	readLists(head1, head2, infile);

	/* Create third list as concatenation of 
	list one and list two and print to file */
	Item* head3 = concatenate(head1, head2);
	printList(outfile, head3);

	/* Remove the evens from the third list and print
	updated list to output file */
	removeEvens(head3);
	printList(outfile, head3);

	/* Return the average of the concatenated list 
	and print to output file */
	double listAverage = findAverage(head3);
	printList(outfile, head3);
	outfile << listAverage << " ";

	/* Close file streams */
 	infile.close(); 
 	outfile.close();

 	/* Delete dynamically allocated memory */
	if (head1 != NULL || head2 != NULL || head3 != NULL) {
		deleteMemory(head1);
		deleteMemory(head2);
		deleteMemory(head3); 
		delete head1;
		delete head2;
		delete head3;
		head1 = NULL;
		head2 = NULL;
		head3 = NULL;
	}

	return 0;
}


/* Function: readLists
 * Usage: readLists(head1, head2, infile) 
 * ========================================================
 * Read in integers from input file and recursively create
 * linked lists. Pass head pointers by reference to keep 
 * changes to list persisting outside of function. istringstream
 * to convert strings to integers. 
 */
void readLists(Item*& head1, Item*& head2, ifstream & infile) {
	string line = "";
	getline(infile, line); 
	createList(head1, line); 
	getline(infile, line);
	createList(head2, line); 
}


/* Function: createList
 * Usage: createList(head, line)
 * ========================================================
 * Recursively create a linked list with the istringstream.
 */
void createList(Item*& head, string line) {
	istringstream strm;
	strm.clear(); 
	strm.str(line);
	int num = 0;
	while (strm >> num) {
		appendElement(head, num); 
	}
}


/* Function: concatenate
 * Usage: concatenate(head1, head2)
 * ========================================================
 * Concatenate two linked lists recursively. At a high-level,
 * copy the contents of the first list and store in a local 
 * pointer using recursion. Copy the second list and store in 
 * a local pointer using recursion. Set the head of the 
 * concatenated list to return to the first list copy. Traverse
 * the list and using a pointer to the last element, set next 
 * to the list two copy. Return the pointer to the concatenated
 * list. 
 */
Item* concatenate(Item* head1, Item* head2) {
	if (head1 == NULL && head2 == NULL) {
		return NULL;
	} else if (head1 == NULL && head2 != NULL) {
		return head2; 
	} else if (head2 == NULL && head1 != NULL) {
		return head1; 
	} else {
		Item* listOneCopy = copy(head1, NULL); 
		Item* listTwoCopy = copy(head2, NULL); 
		Item* head3 = listOneCopy; 
		Item* lastOfHead3 = traverse(head3); 
		lastOfHead3->next = listTwoCopy; 
		return head3; 
	}
}


/* Function: traverse
 * Usage: traverse(head)
 * ========================================================
 * Traverse a given linked list and return a pointer to the 
 * last element. This is used in the above function.
 */
Item* traverse(Item* head) {
	if (head->next == NULL) {
		return head;
	} else {
		return traverse(head->next); 
	}
}


/* Function: copy
 * Usage: copy(toCopy, newList)
 * ========================================================
 * Copy the elements of a list toCopy and recursively create
 * a new list newList. Return the pointer to newList. 
 */
Item* copy(Item* toCopy, Item* newList) {
	if (toCopy == NULL) {
		return newList;
	} else {
		appendElement(newList, toCopy->val); 
		return copy(toCopy->next, newList); 
	}
}


/* Function: appendElement
 * Usage: appendElement(head, val)
 * ========================================================
 * Append a new element with value val to a given linked list 
 * recursively. Special Cases: list is empty, list has only 
 * one element. Recursion: set head to point to last value.
 * This function was supplied by Prof. Cote. 
 */
void appendElement(Item*& head, int val) {
	if (head == NULL) 	{
		head = new Item(val, NULL); 
	} else if (head->next == NULL) {
		head->next = new Item(val, NULL); 
	} else {
		appendElement(head->next, val); 
	}
}


/* Function: removeEvens
 * Usage: removeEvens(head) 
 * ======================================================== 
 * Recursively remove the evens of a given linked list. 
 * Base case: return when pointer is null (odd value at end
 * of list). Special cases to watch for: if the first element
 * of a list is even, if the last element of a list is even,
 * (implicit: if a single element list is even), if next
 * element is even. 
 */
void removeEvens(Item*& head) {
	if (head == NULL) {
		return;
	} 

	if (head->next == NULL) {
		return;
	}

	if (head->val % 2 == 0) {
		if (head->next == NULL) {
			head = NULL; 			
			return;
		} else {
			Item* temp = head;
			head = head->next; 
			delete temp;
			temp = NULL;
			removeEvens(head->next); 
		}
	} 

	if ((head->next->val % 2) == 0) {
		Item* temp = head->next; 
		head->next = head->next->next; 
		delete temp;
		temp = NULL; 
		removeEvens(head); 
	} else {
		removeEvens(head->next); 
	}

}


/* Function: findAverage
 * Usage: findAverage(head)
 * ========================================================
 * Recursively find the average of a given list. If the 
 * number of elements in the list is not 0 (computed recursively)
 * return the total sum of elements divided by the total 
 * number of elements. 
 */
double findAverage(Item* head) {
	if (numElements(head) != 0) {
		return (double) sumElements(head) / numElements(head); 
	} 
	return 0;
}


/* Function: sumElements
 * Usage: sumElments(head)
 * ========================================================
 * Recursively return the sum of all elements in the list. 
 */
int sumElements(Item* head) {	
	if (head == NULL) {
		return 0;
	}
	return head->val + sumElements(head->next); 
}


/* Function: numElements
 * Usage: numElements(head)
 * ========================================================
 * Recursively return the total number of all elements in 
 * in the list. 
 */
int numElements(Item* head) {
	if (head == NULL) {
		return 0;
	}
	return 1 + numElements(head->next); 
}


/* Function: printList
 * Usage: printList(outfile, head)
 * ========================================================
 * Recursively print out the contents of a list through a 
 * specified file stream and output file.
 */
void printList(ofstream & ofile, Item* head) {
  	if(head == NULL)
    	ofile << endl;
  	else {
		ofile << head->val << " ";
		printList(ofile, head->next);    
	}
}


/* Function: deleteMemory
 * Usage: deleteMemory(head) 
 * ========================================================
 * Recursively delete memory allocated by a given list. This
 * function was supplied by Prof. Cote in class. 
 */
void deleteMemory(Item*& head) {
	Item* curr = head;
	Item* temp = NULL;
	while (curr) {
		temp = curr->next;
		delete curr;
		curr = temp;
	}
}
