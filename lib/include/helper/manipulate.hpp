#pragma once

namespace oh {
  namespace helper {

template<typename T>
void Swap(T& a, T& b);
template<typename T>
void ExclusiveAssign(T& a, T expr_a, T& b, T expr_b);

// --------------------------------------------------------------------- //

template<typename T>
void Swap(T& a, T& b)
{
  ExclusiveAssign(a, b, b, a);
}

/*
 * Evaluate expr_x and assign it to x variable (x is a and b)
 *
 * !Remark: arguments passed to function are eagerly evaluated
 */
template<typename T>
void ExclusiveAssign(T& a, T expr_a, T& b, T expr_b)
{
  a = expr_a;
  b = expr_b;
}

}}

// ~~ oh::helper::
