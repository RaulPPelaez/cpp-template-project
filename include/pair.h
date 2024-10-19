#pragma once
namespace homework {
/**
 * @brief A class template that holds two values of any type.
 * @tparam T1 The type of the first value.
 * @tparam T2 The type of the second value.
 */
template <typename T1, typename T2> struct Pair {
  T1 first;
  T2 second;
};
} // namespace homework
