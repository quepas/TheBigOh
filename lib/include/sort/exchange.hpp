#pragma once

#include "helper/manipulate.hpp"
#include <cstddef>

namespace oh {
  namespace sort {

template<typename T>
void ExchangeSort(unsigned size, T* data);
template<typename T, size_t N>
void ExchangeSort(T (&data)[N]);

// --------------------------------------------------------------------- //

template<typename T>
void ExchangeSort(unsigned size, T* data)
{
  for (unsigned idx = 0; idx < size - 1; ++idx) {
    for (unsigned jdx = idx + 1; jdx < size; ++jdx) {
      if (data[idx] > data[jdx]) helper::Swap(data[idx], data[jdx]);
    }
  }
}

template<typename T, size_t N>
void ExchangeSort(T (&data)[N])
{
  ExchangeSort(N, data);
}

}}
// ~~ oh::sort::
