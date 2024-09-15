#include <iostream>
#include <vector>
#include <numeric>

// Function that takes vector by value
int sum_val(std::vector<int> v) {
  int sum = 0;
  for (int num : v) {
    sum += num;
  }
  return sum;
}

// Function that takes vector by reference
int sum_ref(const std::vector<int>& v) {
  int sum = 0;
  for (int num : v) {
    sum += num;
  }
  return sum;
}

// Function that takes pointer to first element
int sum_ptr(const int* ptr, int size) {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += ptr[i];
  }
  return sum;
}

int main() {
  constexpr int size = 1000;
  std::vector<int> v(size);
  std::iota(v.begin(), v.end(), 0);

  std::cout << "Sum by value: " << sum_val(v) << std::endl;
  std::cout << "Sum by reference: " << sum_ref(v) << std::endl;

  auto* ptr = v.data();
  v.clear();

  std::cout << "Sum by value after clear: " << sum_val(v) << std::endl;
  std::cout << "Sum by pointer after clear: " << sum_ptr(ptr, size) << std::endl;

  return 0;
}
