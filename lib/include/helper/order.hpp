#pragma once

#include <cstddef>

namespace oh {
  namespace helper {

template<typename T>
bool InAscendingOrder(unsigned size, T* data);
template<typename T, size_t N>
bool InAscendingOrder(T (&data)[N]);

template<typename T>
bool InNonAscendingOrder(unsigned size, T* data);
template<typename T, size_t N>
bool InNonAscendingOrder(T (&data)[N]);

template<typename T>
bool InDescendingOrder(unsigned size, T* data);
template<typename T, size_t N>
bool InDescendingOrder(T(&data)[N]);

template<typename T>
bool InNonDescendingOrder(unsigned size, T* data);
template<typename T, size_t N>
bool InNonDescendingOrder(T(&data)[N]);

}}

template<typename T>
bool oh::helper::InAscendingOrder(unsigned size, T* data)
{
  for (unsigned idx = 0; idx < size - 1; ++idx) {
    if (data[idx] >= data[idx + 1]) return false;
  }
  return true;
}

template<typename T, size_t N>
bool oh::helper::InAscendingOrder(T(&data)[N])
{
  return InAscendingOrder(N, data);
}

template<typename T>
bool oh::helper::InNonAscendingOrder(unsigned size, T* data)
{
  for (unsigned idx = 0; idx < size - 1; ++idx) {
    if (data[idx] < data[idx + 1]) return false;
  }
  return true;
}

template<typename T, size_t N>
bool oh::helper::InNonAscendingOrder(T(&data)[N])
{
  return InNonAscendingOrder(N, data);
}

template<typename T>
bool oh::helper::InDescendingOrder(unsigned size, T* data)
{
  for (unsigned idx = 0; idx < size - 1; ++idx) {
    if (data[idx] <= data[idx + 1]) return false;
  }
  return true;
}

template<typename T, size_t N>
bool oh::helper::InDescendingOrder(T(&data)[N])
{
  return InDescendingOrder(N, data);
}

template<typename T>
bool oh::helper::InNonDescendingOrder(unsigned size, T* data)
{
  for (unsigned idx = 0; idx < size - 1; ++idx) {
    if (data[idx] > data[idx + 1]) return false;
  }
  return true;
}

template<typename T, size_t N>
bool oh::helper::InNonDescendingOrder(T(&data)[N])
{
  return InNonDescendingOrder(N, data);
}

// ~~ oh::helper::
