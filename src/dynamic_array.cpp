// class DynamicArray{
//   int* data;
//   int size;
//   public:
//   DynamicArray(int size, int value = 0);
//   DynamicArray(const DynamicArray& other); // Copy constructor
//   DynamicArray(DynamicArray&& other); // Move constructor
//   ~DynamicArray(); // Destructor
//   DynamicArray& operator=(const DynamicArray& other); // Copy assignment
//   operator DynamicArray& operator=(DynamicArray&& other); // Move assignment
//   operator int& operator[](int index); int getSize() const; friend
//   std::ostream& operator<<(std::ostream& os, const DynamicArray& arr);
//   DynamicArray operator+(const DynamicArray& other);
// };

#include "dynamic_array.h"

using namespace homework::dynarray;

DynamicArray::DynamicArray(int size, int value) : size(size) {
  data = new int[size];
  for (int i = 0; i < size; i++) {
    data[i] = value;
  }
}

DynamicArray::DynamicArray(const DynamicArray &other) : size(other.size) {
  data = new int[size];
  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

DynamicArray::DynamicArray(DynamicArray &&other)
    : size(other.size), data(other.data) {
  other.size = 0;
  other.data = nullptr;
}

DynamicArray::~DynamicArray() {
  if (data != nullptr) {
    delete[] data;
  }
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other) {
  if (this == &other) {
    return *this;
  }
  if (data != nullptr) {
    delete[] data;
  }
  size = other.size;
  data = new int[size];
  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
  return *this;
}

DynamicArray &DynamicArray::operator=(DynamicArray &&other) {
  if (this == &other) {
    return *this;
  }
  if (data != nullptr) {
    delete[] data;
  }
  size = other.size;
  data = other.data;
  other.size = 0;
  other.data = nullptr;
  return *this;
}

int &DynamicArray::operator[](int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

int DynamicArray::getSize() const { return size; }

std::ostream &homework::dynarray::operator<<(std::ostream &os, const DynamicArray &arr) {
  os << "[";
  for (int i = 0; i < arr.size; i++) {
    os << arr.data[i];
    if (i < arr.size - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}


DynamicArray DynamicArray::operator+(const DynamicArray &other) {
  DynamicArray result(size + other.size);
  for (int i = 0; i < size; i++) {
    result.data[i] = data[i];
  }
  for (int i = 0; i < other.size; i++) {
    result.data[size + i] = other.data[i];
  }
  return result;
}
