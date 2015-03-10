#include <cstdlib>
#include "setint.h"

/**
 * Default constructor - default to a list of capacity = 10
 */
SetInt::SetInt() : list_()
{
  iterLoc_ = -1;
}

/**
 * Destructor
   */
SetInt::~SetInt()
{

}

/**
 * Returns the current number of items in the list 
 */
int SetInt::size() const
{
  return list_.size();
}

/**
 * Returns true if the list is empty, false otherwise
 */
bool SetInt::empty() const
{
  return list_.empty();

}

/**
 * Inserts val so it appears at index, pos
 */
void SetInt::insert(const int& val)
{
  if(!exists(val)){
    list_.insert(0,val);
  }
}

/**
 * Removes the value at index, pos
 */
void SetInt::remove(const int& val)
{
  for(unsigned int i=0; i < list_.size(); i++){
    if(list_.get(i) == val){
      list_.remove(i);
      break;
    }
  }
}

/**
 * Returns true if the item is in the set
 */
bool SetInt::exists(const int& val) const
{
  for(unsigned int i=0; i < list_.size(); i++){
    if(list_.get(i) == val){
      return true;
    }
  }  
  return false;
}

/**
 * Return a pointer to the first item
 *  and support future calls to next()
   */
int const* SetInt::first()
{
  iterLoc_ = 0;
  if(iterLoc_ < list_.size()){
    return &list_.get(0);
  }
  return NULL;
}

/**
 * Return a pointer to the next item
 *  after the previous call to next
 *  and NULL if you reach the end
 */
int const* SetInt::next()
{
  if(iterLoc_ < list_.size()-1){
    return &list_.get(++iterLoc_);
  }
  return NULL;
}

/**
 * Returns another (new) set that contains
 * the union of this set and "other"
 */
SetInt SetInt::setUnion(const SetInt& other) const
{
  SetInt x(other);
  for(unsigned int i = 0; i < list_.size(); i++){
    x.insert(list_.get(i));
  }
  return x;
}

/**
 * Returns another (new) set that contains
 * the intersection of this set and "other"
 */
SetInt SetInt::setIntersection(const SetInt& other) const
{
  SetInt x;
  for(unsigned int i = 0; i < list_.size(); i++){
    if( other.exists( list_.get(i) )){
      x.insert(list_.get(i));
    }
  }
  return x;  
}

SetInt SetInt::operator|(const SetInt& other) const
{
  return setUnion(other);
}

SetInt SetInt::operator&(const SetInt& other) const
{
  return setIntersection(other);
}


