#pragma once

namespace oh {
  namespace data {

/*
 *  Stack implemented with fixed-size array
 */
template<typename T>
class Stack
{
public:
  Stack(unsigned capacity);

  void Push(T element);
  T Pop();
  bool IsEmpty() const { return size_ == 0; }
  unsigned Size() const { return size_; }
  void Clear();
  unsigned capacity() const { return capacity_; }

private:
  unsigned capacity_;
  unsigned size_;
  T* data_;
};

template<typename T>
Stack<T>::Stack(unsigned stack_capacity)
  : capacity_(stack_capacity), size_(0)
{
  data_ = new T[capacity_];
}

template<typename T>
void Stack<T>::Push(T element)
{
  if (size_ == capacity_) return;
  data_[size_++] = element;
}

template<typename T>
T Stack<T>::Pop()
{
  if (IsEmpty()) return T();
  return data_[--size_];
}

template<typename T>
void Stack<T>::Clear()
{
  size_ = 0;
  delete data_;
  data_ = new T[capacity_];
}

}}
// ~~ oh::data::Stack
