 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/3/15     |
 * | HW 2                       |
 * ==============================
 * 
 *  Filename: listdbl.h 
 *
 *  Directions from bits.usc.edu/cs104/assignments/hw2:
 * 
 *    Examine the code provided below and complete the 
 *    insert() and remove() member functions in llistdbl.cpp
 *    
 */

#ifndef LLISTDBL_H
#define LLISTDBL_H

class LListDbl {
 
  public:
    /**
     * Struct Item 
     */
    struct Item {
      double val;
      Item *prev;
      Item *next;
  };


  /**
   * Default constructor - default to a list of capacity = 10
   */
  LListDbl();


  /**
   * Destructor
   */
  ~LListDbl();


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
  void insert(int pos, const double& val);


  /**
   * Removes the value at index, pos
   */
  void remove(int pos);


  /**
   * Overwrites the old value at index, pos, with val
   */
  void set(int pos, const double& val);


  /**
   * Returns the value at index, pos
   */
  double& get(int pos);


  /**
   * Returns the value at index, pos
   */
  double const & get(int pos) const;


  /**
   * Deletes all items in the list
   */
  void clear();


 private:
  /** 
   * Returns a pointer to the item at index, pos
   *  and NULL otherwise
   */
  Item* getNodeAt(int pos) const;


  /**
   * Data members
   */
  Item* head_;
  Item* tail_;
  int size_;


};

#endif
