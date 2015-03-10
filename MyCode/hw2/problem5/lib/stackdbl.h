 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *  Filename: stackdbl.h 
 *
 *  Directions from bits.usc.edu/cs104/assignments/hw2:
 * 
 *    Use your linked list implementation from problem 3 to 
 *    create a Stack data structure for variables of type double.
 *    Think carefully about efficiency and ensure that your Stack
 *    implementation is not unduly slow. 
 *    
 */

#ifndef STACKDBL_H
#define STACKDBL_H

/* Include linked list impelementation from Problem 3 */ 
#include "../../problem3/lib/llistdbl.h"

class StackDbl {

 public:
  /**
   * Default constructor
   */
  StackDbl();


  /**
   * Destructor
   */
  ~StackDbl();


  /**
   * Returns true if the stack is empty, false otherwise
   */
  bool empty() const;


  /**
   * Pushes a new value, val, onto the top of the stack
   */
  void push(const double& val);


  /**
   * Returns the top value on the stack
   */
  double const &  top() const;


  /**
   * Removes the top element on the stack
   */
  void pop();


 private:
  /** 
   * Single data member of the Stack.
   */
  LListDbl list_;


};

#endif
