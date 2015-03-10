 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/13/15    |
 * | HW 3                       |
 * ==============================
 * 
 *  Filename: setint.h 
 *
 *  Directions from bits.usc.edu/cs104/assignments/hw3:
 * 
 *      Implement a basic Set class using your 
 *      LListInt implementation in Problem 2. 
 *    
 */

#ifndef SETINT_H
#define SETINT_H
#include "../../problem2/lib/llistint.h"

class SetInt {
 public:
  /**
   * Default constructor - default to a list of capacity = 10
   */
  SetInt();

  /**
   * Destructor
   */
  ~SetInt();


  /**
   * Copy constructor
   */
  SetInt(const SetInt& other); 


  /**
   * Assignment operator overload
   */
  SetInt& operator=(const SetInt& other); 


  /**
   * Returns the current number of items in the list 
   */
  int size() const;


  /**
   * Returns true if the list is empty, false otherwise
   */
  bool empty() const;


  /**
   * Inserts val so it appears at index, pos
   */
  void insert(const int& val);


  /**
   * Removes the value at index, pos
   */
  void remove(const int& val);


  /**
   * Returns true if the item is in the set
   */
  bool exists(const int& val) const;


  /**
   * Return a pointer to the first item
   *  and support future calls to next()
   */
  int const* first();


  /**
   * Return a pointer to the next item
   *  after the previous call to next
   *  and NULL if you reach the end
   */
  int const* next();


  /**
   * Returns another (new) set that contains
   * the union of this set and "other"
   */
  SetInt setUnion(const SetInt& other) const;


  /**
   * Returns another (new) set that contains
   * the intersection of this set and "other"
   */
  SetInt setIntersection(const SetInt& other) const;


  /**
   * Operator | overload. Returns new set from 
   * setUnion()
   */
  SetInt operator|(const SetInt& other) const;


  /**
   * Operator & overload. Returns new set from 
   * setIntersection()
   */
  SetInt operator&(const SetInt& other) const;


 private:
  LListInt list_;

   /* Return the index of item with value val */
   int getIndex(int val) const;

   /* Current value of list iterator */
   int iter_;  

};

#endif
