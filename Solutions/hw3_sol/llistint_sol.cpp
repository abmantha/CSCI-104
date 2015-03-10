#include "llistint.h"
#include <iostream>
#include <cstdlib>
using namespace std;
LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::LListInt(const LListInt& other)
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
  Item* temp = other.head_;
  while(temp){
    push_back(temp->val);
    temp = temp->next;
  }
}

LListInt& LListInt::operator=(const LListInt& other)
{
  if(this == &other){
    return *this;
  }
  clear();
  Item* temp = other.head_;
  while(temp){
    push_back(temp->val);
    temp = temp->next;
  }
  return *this;
}


LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

void LListInt::insert(int loc, const int& val)
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


void LListInt::remove(int loc)
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

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


LListInt::Item* LListInt::getNodeAt(int loc) const
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

void LListInt::push_back(const int& val)
{
  if(head_ == NULL){
    head_ = new Item;
    head_->val = val;
    head_->next = NULL;
    head_->prev = NULL;
    tail_ = head_;
    size_ = 1;
  }
  else {
    Item* n = new Item;
    n->val = val;
    n->next = NULL;
    n->prev = tail_;
    tail_->next = n;
    tail_ = n;
    size_++;
  }
}
