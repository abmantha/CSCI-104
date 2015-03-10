  /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *  Filename: alistint.h 
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

#ifndef ALISTINT_H
#define ALISTINT_H

class AListInt {

 public:
  /**
   * Default constructor - default to a list of capacity = 10
   */
  AListInt();


  /**
   * Another constructor - default to a list to the indicated capacity
   */
  AListInt(int cap);

  
  /**
   * Destructor
   */
  ~AListInt();

  
  /**
   * Standard List interface
   */


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
  void insert (int pos, const int& val);


  /**
   * Removes the value at index, pos
   */
  void remove (int pos);


  /**
   * Overwrites the old value at index, pos, with val
   */
  void set (int position, const int& val);


  /**
   * Returns the value at index, pos
   */
  int& get (int position) ;


  /**
   * Returns the value at index, pos
   */
  int const & get (int position) const;

  
 private:
  /**
   * Doubles the size of the list maintaining its contents
   * when capacity is maximized. 
   */
  void resize(); 

  
  /**
   * Data members
   */
  int* arrayList_; 
  int size_;
  int capacity_; 
  
  
};

#endif
