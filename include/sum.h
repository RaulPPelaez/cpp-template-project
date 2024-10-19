// include/sum.h
#pragma once
#include <iostream>
#include <string>
namespace homework {
/**
* @brief Metafunction for summing the elements of a vector holding
elements of any type
* @param s The vector to sum
* @param v The initial value of the sum
* @tparam Container The type of the container holding the elements
* @tparam T The type of the elements in the vector
* @return The sum of the elements in the vector, plus the initial value
*/
template <typename Container, typename T = Container::value_type>
// default value for T, deduced from the container type by using the fact that
// every standard container has a value_type member
T sum_elements(const Container &s, T v = T{}) {
  for (auto i : s) {
    v += i;
  }
  return v;
}
/**
* @brief Specialization of the sum function for std::string
* @param s The vector of strings to sum
* @param v The initial value of the sum
* @return The concatenation of the strings in the vector, plus the initial
value
*/
template <typename Container>
std::string sum_elements(const Container &s, std::string v) {
  // We can operate on types that are known at compile time
  // Static_assert is a compile-time check that will fail if the condition is
  // not met
  static_assert(
      std::is_same<typename Container::value_type, std::string>::value,
      "The container must hold strings");
  std::cout << "String vector detected, printing the strings" << std::endl;
  for (auto i : s) {
    std::cout << i << " ";
    v += i;
  }
  return v;
}

/**
 * @brief Function that returns a tuple with the arguments passed to it
 * @tparam Args The types of the arguments
 * @param args The arguments to be stored in the tuple
 * @return A tuple with the arguments passed to the function
 */
template <typename... Args> auto my_make_tuple(Args... args) {
  return std::tuple<Args...>(args...);
}
} // namespace homework
