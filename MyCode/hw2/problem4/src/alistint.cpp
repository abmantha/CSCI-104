 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *  Filename: alistint.cpp 
 *
 *  Directions from bits.usc.edu/cs104/assignments/hw2:
 * 
 *    Write an integer array-based list class. Notice 
 *    it has the same list interface as the linked list
 *    implementation. However, it should also contain a 
 *    private member function resize() that will increase
 *    the capacity of the list by doubling its size and be
 *    called if the list becomes full and the user requests
 *    another insertion.
 *    
 */

#include "../lib/alistint.h"
#include <cstdlib>
#include <limits>


/* Function: AListInt
 * Usage: AListInt a; 
 * ========================================================
 * Default constructor for AListInt class. Dynamically 
 * allocates underlying integer array to default capacity 
 * of 10. The number of elements initially is 0. 
 */
AListInt::AListInt() {
	arrayList_ = new int[10]; 
	size_ = 0; 
	capacity_ = 10; 
}


/* Function: AListInt
 * Usage: AListInt a(20); 
 * ========================================================
 * Alternate constructor for AListInt class. Dynamically 
 * allocates underlying integer array to capacity of cap.
 * The number of elements initially is 0. Guaranteed to have
 * capacity of 1 (when user cap value = 0). 
 */
AListInt::AListInt(int cap) {
	if (cap == 0) {
		cap = 1;
	}
	arrayList_ = new int[cap];
	size_ = 0;
	capacity_ = cap;
}


/* Function: ~AListInt
 * ========================================================
 * Destructor for AListInt class. Deletes all dynamically 
 * allocated memory used by underlying integer array when
 * object goes out of scope. 
 */
AListInt::~AListInt() {
	delete [] arrayList_;
}


/* Function: size
 * Usage: int listSize = a.size();
 * ========================================================
 * Returns the number of elements in the list.
 */
int AListInt::size() const {
	return size_; 
}


/* Function: empty
 * Usage: if (a.empty())
 * ========================================================
 * Returns if list is empty. 
 */
bool AListInt::empty() const {
	return size_ == 0; 
}


/* Function: insert
 * Usage: a.insert(2, 23); 
 * ========================================================
 * Insert an alement at position pos with value val. 
 * When a new element is inserted, all elements to the 
 * right shift one space to the right, making space for the 
 * new element at pos. The size of list then increments.  
 * If the array has reached capactiy, then it will automatically
 * double its capacity and create more space as needed. 
 */
void AListInt::insert(int pos, const int& val) {
	if (pos >= 0 && pos <= size_) {	
		if (size_ == capacity_) {
			resize(); 
		}

		for (int i = size_; i > pos; i--) {
			arrayList_[i] = arrayList_[i-1]; 
		}
		arrayList_[pos] = val; 
		size_++; 
	}
}


/* Function: remove
 * Usage: a.remove(2);
 * ========================================================
 * Removes an element at position pos from the array list.
 * If the list is empty, when remove is called, then the 
 * function returns. Otherwise, if the pos is within 
 * bounds, the size of the array decrements and all values 
 * to the right shift one place to the left, overwriting
 * the original value at pos. 
 */
void AListInt::remove(int pos) {
	if (empty()) {	
		return;
	}

	if (pos >= 0 && pos < size_) {
		size_--; 
		for (int i = pos; i < size_; i++) {
			arrayList_[i] = arrayList_[i+1]; 
		}
	}
}


/* Function: set
 * Usage: a.set(3, 23)
 * ========================================================
 * Overwrites the value at position with val. If the list 
 * is already empty, then the function returns. Otherwise,
 * if position is within bounds, the current position is 
 * overwritten with the new value. 
 */
void AListInt::set(int position, const int& val) {	
	if (empty()) {
		return;
	}
	if (position >= 0 && position < size_) {
		arrayList_[position] = val; 
	}
}


/* Function: get
 * Usage: a.get(2)
 * ========================================================
 * Returns reference to value at position within the list. Checks to 
 * see if position is within bounds and list is not empty.
 * If not, function returns the minimum integer value provided
 * by the <limits> library. Otherwise, it simply returns
 * the value at position within the array. 
 */
int& AListInt::get(int position) {					
	if (empty() || position < 0 || position >= size_) {
		int defaultVal = std::numeric_limits<int>::min(); 
		return defaultVal;
	}
	return arrayList_[position]; 
}


/* Function: get
 * Usage: a.get(2)
 * ========================================================
 * Returns constant reference value at position within the list. 
 * Guarantees that list can not be modified after returning 
 * value with const keyword. Checks to see if position is 
 * within bounds and list is not empty. If not, function 
 * returns the minimum integer value provided by the <limits> 
 * library. Otherwise, it simply returns the value at 
 * position within the array. 
 */
int const & AListInt::get(int position) const {		
	if (empty() || position < 0 || position >= size_) {
		int defaultVal = std::numeric_limits<int>::min(); 
		return defaultVal;
	}
	return arrayList_[position]; 
}


/* Function: resize
 * Usage: resize()
 * ========================================================
 * Private void function that resizes the underlying integer
 * array when capacity is maximized. Dynamically allocates
 * a new integer array with capacity * 2 and copies all 
 * elements from previous array into new array. After updating
 * the capacity of the array list, it then deletes the memory
 * that the old array points to and points the old array 
 * to the new array. 
 */
void AListInt::resize() {
	int* copy = new int[capacity_ * 2]; 
	for (int i = 0; i < capacity_; i++) {
		copy[i] = arrayList_[i]; 
	}
	capacity_ *= 2;
	delete [] arrayList_; 
	arrayList_ = copy; 
}