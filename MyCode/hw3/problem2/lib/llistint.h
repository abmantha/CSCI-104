 /* =============================
 * | Name: Abhishek Mantha      |
 * | Email: amantha@usc.edu     |
 * | GitHub: abmantha           |
 * | Date Submitted: 2/13/15    |
 * | HW 3                       |
 * ==============================
 * 
 *  Filename: llistint.h 
 *
 *  Directions from bits.usc.edu/cs104/assignments/hw3:
 * 
 *      Copy your LListDbl class from hw2 and modify 
 *      your implementation to now store integers instead
 *      of doubles. Change the class name to LListInt and 
 *      a push_back() function, copy constructor, and 
 *      assignment= overload function. 
 *    
 */

#ifndef LLISTINT_H
#define LLISTINT_H

class LListInt {
 
  public:
    /**
     * Struct Item 
     */
    struct Item {
      int val;
      Item *prev;
      Item *next;
  };


  /**
   * Default constructor 
   */
  LListInt();


  /**
   * Destructor
   */
  ~LListInt();


  /**
   * Copy constructor
   */
  LListInt(const LListInt& other);


  /**
   * Assignment operator overload
   */
  LListInt& operator=(const LListInt& other);  


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
  void insert(int pos, const int& val);


  /**
   * Adds an item to the back of the list in O(1) time
   */
  void push_back(const int& val);


  /**
   * Removes the value at index, pos
   */
  void remove(int pos);


  /**
   * Overwrites the old value at index, pos, with val
   */
  void set(int pos, const int& val);


  /**
   * Returns the value at index, pos
   */
  int& get(int pos);


  /**
   * Returns the value at index, pos
   */
  int const & get(int pos) const;


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
