 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *  Filename: stackdbl.cpp 
 *
 *  Directions from bits.usc.edu/cs104/assignments/hw2:
 * 
 *    Use your linked list implementation from problem 3 to 
 *    create a Stack data structure for variables of type double.
 *    Think carefully about efficiency and ensure that your Stack
 *    implementation is not unduly slow. 
 *    
 */

#include "../lib/stackdbl.h"
#include <cstdlib>
#include <limits>

/* Function: StackDbl
 * Usage: StackDbl s;
 * ========================================================
 * Default constructor of StackDbl class. No variables to 
 * initialize.
 */
StackDbl::StackDbl() {
}


/* Function: ~StackDbl
 * ========================================================
 * No memory to deallocate. 
 */
StackDbl::~StackDbl() {
}


/* Function: empty
 * Usage: if(s.empty())
 * ========================================================
 * Returns if stack is empty. Wrapper function for list
 * implementation of .empty().
 */
bool StackDbl::empty() const {
	return list_.empty(); 
}


/* Function: push
 * Usage: push(3);
 * ========================================================
 * Pushes new element to the head of stack. Wrapper function
 * for list function insert(0, val). 
 * Top of stack --> index = 0
 */
void StackDbl::push(const double& val) {
	list_.insert(0, val); 
}


/* Function: top
 * Usage: double value = s.top(); 
 * ========================================================
 * Returns the topmost element on the stack. If the 
 * stack is empty, then it returns the minimum integer 
 * value provided by the <limits> library. Wrapper function
 * for list function list.get(0). 
 * Top of stack --> index = 0
 */
double const & StackDbl::top() const {
	if (empty()) {
		int defaultVal = std::numeric_limits<int>::min(); 
		return defaultVal; 
	}
	return list_.get(0);
}


/* Function: pop
 * Usage: s.pop()
 * ========================================================
 * Pops off the topmost element from the stack uf stack
 * contains elements to pop. Wrapper function for list 
 * function list.remove(0). 
 */
void StackDbl::pop() {
	list_.remove(0);  	
}

