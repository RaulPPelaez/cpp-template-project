#include <iostream>

namespace homework {

namespace dynarray {

/**
 * @brief A class that represents a dynamic array of integers.
 *
 * The class has the following features:
 * - The size of the array is fixed at construction time and cannot be changed.
 * - The array is dynamically allocated on the heap.
 * - The array is initialized with a default value.
 * - The class has a copy constructor, a move constructor, a copy assignment
 * operator, and a move assignment operator.
 * - The class has a destructor that releases the memory allocated for the
 * array.
 * - The class has an overloaded operator[] that allows access to the elements
 * of the array.
 * - The class has an overloaded operator<< that allows printing the array to
 * the standard output.
 * - The class has an overloaded operator+ that allows concatenating two arrays.
 *
 * Example:
 * @code
 * DynamicArray arr1(5, 1);
 * DynamicArray arr2(5, 2);
 * DynamicArray arr3 = arr1 + arr2;
 * std::cout << arr3 << std::endl; // Output: [1, 1, 1, 1, 1, 2, 2, 2, 2, 2]
 * @endcode
 */
class DynamicArray {
  int *data;
  int size;

public:
  /**
   * @brief Constructs a new DynamicArray object.
   *
   * @param size The size of the array.
   * @param value The default value of the array elements.
   */
  DynamicArray(int size, int value = 0);
  DynamicArray(const DynamicArray &other); // Copy constructor
  DynamicArray(DynamicArray &&other);      // Move constructor
  ~DynamicArray();                         // Destructor
  DynamicArray &
  operator=(const DynamicArray &other);          // Copy assignment operator
  DynamicArray &operator=(DynamicArray &&other); // Move assignment operator
  int &operator[](int index);
  /**
   * @brief Get the size of the array.
   *
   * @return int The size of the array.
   */
  int getSize() const;
  friend std::ostream &operator<<(std::ostream &os, const DynamicArray &arr);
  /**
   * @brief Concatenates two arrays, one after the other.
   *
   * @param other The array to concatenate with.
   * @return DynamicArray The concatenated array.
   */
  DynamicArray operator+(const DynamicArray &other);
};

std::ostream &operator<<(std::ostream &os, const DynamicArray &arr);

} // namespace dynarray
} // namespace homework
