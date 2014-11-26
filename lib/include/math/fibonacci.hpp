#pragma once

namespace oh {
  namespace math {

// tail-recursive version
long Fibonacci_(unsigned n);
// iterative version
long Fibonacci(unsigned n);

// helper function for tail-recursion
static long Fibonacci_(unsigned n, long a, long b);

// generated Fibonacci sequence
const unsigned FIBONACCI_SIZE = 39;
const long FIBONACCI_SEQUENCE[FIBONACCI_SIZE] = {
  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
  144, 233, 377, 610, 987, 1597, 2584,
  4181, 6765, 10946, 17711, 28657, 46368,
  75025, 121393, 196418, 317811, 514229,
  832040, 1346269, 2178309, 3524578,
  5702887, 9227465, 14930352, 24157817, 39088169 };

}}
// ~~ oh::math::
