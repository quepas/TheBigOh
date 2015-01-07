#pragma once

namespace oh {
  namespace data {

/*
 *  Stack implemented with fixed-size array
 */
template<typename T, unsigned MAX_SIZE>
class Stack
{
public:
  Stack() : size_(0), capacity_(MAX_SIZE) {}

  void Push(T element);
  T Pop();
  T Top() const;
  bool IsEmpty() const { return size_ == 0; }
  unsigned Size() const { return size_; }
  void Clear();
  unsigned capacity() const { return capacity_; }

private:
  unsigned capacity_;
  unsigned size_;
  T data_[MAX_SIZE];
};

template<typename T, unsigned MAX_SIZE>
void Stack<T, MAX_SIZE>::Push(T element)
{
  if (size_ == capacity_) return;
  data_[size_++] = element;
}

template<typename T, unsigned MAX_SIZE>
T Stack<T, MAX_SIZE>::Pop()
{
  if (IsEmpty()) return T();
  return data_[--size_];
}

template<typename T, unsigned MAX_SIZE>
T Stack<T, MAX_SIZE>::Top() const
{
  if (IsEmpty()) return T();
  return data_[size_ - 1];
}

template<typename T, unsigned MAX_SIZE>
void Stack<T, MAX_SIZE>::Clear()
{
  size_ = 0;
}

}}
// ~~ oh::data::Stack
