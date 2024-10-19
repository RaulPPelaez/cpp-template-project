#pragma once
#include <vector>
namespace homework {
/**
 * @brief A flexible container that can hold elements of any type.
 * @tparam T The type of the elements in the container. Defaults to int.
 */
template <typename T = int> class FlexibleContainer {
  std::vector<T> data;

public:
  /**
   * @brief Construct a new Flexible Container object including all the elements
   * passed as arguments. All elements must be convertible to T.
   * @tparam Args The types of the arguments passed to the constructor.
   * @param args The arguments passed to the constructor.
   */
  template <typename... Args> FlexibleContainer(Args... args) : data{args...} {}

  /**
   * @brief Add a new element to the container.
   * @param value The value to add to the container.
   */
  void add(T value) { data.push_back(value); }
  /**
   * @brief Get the element at the specified index.
   * @param index The index of the element to get.
   * @return T The element at the specified index.
   */
  T get(int index) const { return data[index]; }
  /**
   * @brief Get the number of elements in the container.
   * @return size_t The number of elements in the container.
   */
  size_t size() const { return data.size(); }
  /**
   * @brief Apply a function to all elements in the container.
   * @tparam Op The type of the function to apply. Must be a callable object
   * that takes a T and returns a T.
   * @param op The function to apply to all elements in the container.
   */
  template <class Op> void map(Op op) {
    for (auto &elem : data) {
      elem = op(elem);
    }
  }
};

} // namespace homework
