#include "llistdbl.h"
#include <cstdlib>

LListDbl::LListDbl()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListDbl::~LListDbl()
{
  clear();
}

bool LListDbl::empty() const
{
  return size_ == 0;
}

int LListDbl::size() const
{
  return size_;
}

void LListDbl::insert(int loc, const double& val)
{

  if(loc == 0){
    Item *old_head = head_;
    head_ =  new Item;
    head_->val = val;
    head_->next = old_head;
    if(++size_ == 1){
      tail_ = head_;
    }
  }
  else if(loc < 0 || loc > size_){
    return;
  }
  else {
    Item *temp = getNodeAt(loc-1);

    Item *newitem = new Item;
    newitem->val = val;
    newitem->next = temp->next;
    temp->next = newitem;
    if(loc == size_++){
      tail_ = newitem;
    }
  }
}


void LListDbl::remove(int loc)
{
  if(size_ <= 0){
    return;
  }
  else if(loc == 0){
    // take the Item out of the list
    Item *temp = head_;
    head_ = head_->next;
    delete temp;

    if(--size_ == 0){
      tail_ = NULL;
    }
  }
  else if(loc > 0 && loc < size_){
    Item* temp = getNodeAt(loc-1);
    
    if(temp){
      Item *to_remove = temp->next;
      temp->next = to_remove->next;
      delete to_remove;
      if(loc == size_-1){
	tail_ = temp;
      }
      size_--;
      
    }
  }
}

void LListDbl::set(int loc, const double& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

double& LListDbl::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

double const & LListDbl::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListDbl::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


LListDbl::Item* LListDbl::getNodeAt(int loc) const
{
  Item *temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}
