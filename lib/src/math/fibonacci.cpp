#include "math/fibonacci.hpp"
#include "helper/manipulate.hpp"

using oh::helper::ExclusiveAssign;

namespace oh {
  namespace math {

long Fibonacci_(unsigned n)
{
  if (n <= 1) return n;
  return Fibonacci_(n, 0, 1);
}

long Fibonacci_(unsigned n, long a, long b)
{
  if (n == 1) return b;
  else Fibonacci_(--n, b, a + b);
}

long Fibonacci(unsigned n)
{
  if (n <= 1) return n;
  long a = 0, b = 1;
  do {
    ExclusiveAssign(a, b, b, a + b);
    --n;
  } while (n > 1);
  return b;
}

}}
// ~~ oh::math::
