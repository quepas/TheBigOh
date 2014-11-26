#pragma once

#include "data/list.hpp"

namespace oh {
  namespace search {

template<typename T>
bool LinearSearch(unsigned size, const T* data, T searched, unsigned& position);
template<typename T, size_t N>
bool LinearSearch(T (&data)[N], T searched, unsigned& position);
template<typename T>
bool LinearSearch(data::List<T> list, T searched, unsigned& position);

template<typename T>
static bool ListLinearSearch(data::List<T> list, T searched, unsigned start, unsigned& position);

// --------------------------------------------------------------------- //
template<typename T>
bool LinearSearch(unsigned size, const T* data, T searched, unsigned& position)
{
  for (unsigned idx = 0; idx < size; ++idx) {
    if (data[idx] == searched) {
      position = idx;
      return true;
    }
  }
  return false;
}

template<typename T, size_t N>
bool LinearSearch(T (&data)[N], T searched, unsigned& position)
{
  return LinearSearch(N, data, searched, position);
}

template<typename T>
bool LinearSearch(data::List<T> list, T searched, unsigned& position)
{
  return ListLinearSearch(list, searched, 0, position);
}

template<typename T>
bool ListLinearSearch(data::List<T> list, T searched, unsigned start, unsigned& position)
{
  if (list.IsEmpty()) return false;
  else if (list.Head() == searched) {
    position = start;
    return true;
  }
  else ListLinearSearch(list.Tail(), searched, ++start, position);
}

}}
// ~~ oh::search::
