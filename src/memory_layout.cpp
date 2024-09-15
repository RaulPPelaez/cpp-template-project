#include <iostream>
#include <vector>
#include <array>

int main() {

  std::cout << "Size of int: " << sizeof(int) << std::endl;
  std::cout << "Size of double: " << sizeof(double) << std::endl;
  std::cout << "Size of char: " << sizeof(char) << std::endl;
  std::vector<int> v(1000);
  std::cout << "Size of vector: " << sizeof(v) << std::endl;
  std::array<int, 1000> arr;
  std::cout << "Size of array: " << sizeof(arr) << std::endl;

  return 0;
}
