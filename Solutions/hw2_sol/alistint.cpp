#include "alistint_sol.h"

AListInt::AListInt() :
  _size(0), _cap(10)
{
  _data = new int[_cap];
}

AListInt::AListInt(int cap) :
  _size(0), _cap(cap)
{
  _data = new int[_cap];
}

AListInt::~AListInt() 
{
  delete [] _data;
}

bool AListInt::empty() const
{
  return _size==0;
}

int AListInt::size() const
{
  return _size;
}

void AListInt::insert (int position, const int& val)
{
  if(_size+1 > _cap){
    resize();
  }
  for(int i=_size-1; i >= position; --i){
    _data[i+1] = _data[i];
  }
  _data[position] = val;
  _size++;
}


void AListInt::remove (int position)
{
  for(int i=position; i < _size; i++){
    _data[i] = _data[i+1];
  }
  _size--;
}


void AListInt::set (int position, const int & val)
{
  _data[position] = val;
}


int& AListInt::get (int position)
{
  return _data[position];
}

int const & AListInt::get (int position) const
{
  return _data[position];
}

void AListInt::resize()
{
  int* temp = new int[2*_cap];
  for(int i=0; i < _size; i++){
    temp[i] = _data[i];
  }
  _cap *= 2;
  delete [] _data;
  _data = temp;
}




