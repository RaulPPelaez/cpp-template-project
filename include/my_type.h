#pragma once
#include <fstream>
#include <iostream>
namespace homework {
/**
 * @brief A type with some members that can be serialized
 */
class MyType {
  int i;
  double d;

public:
  MyType(int i, double d) : i(i), d(d) {}
  /**
   * @brief Equality operator
   */
  auto operator==(const MyType &other) const {
    return i == other.i && d == other.d;
  }
  /**
   * @brief Input stream overload
   */
  friend std::istream &operator>>(std::istream &is, MyType &mt) {
    is >> mt.i >> mt.d;
    return is;
  }
  /**
   * @brief Output stream overload
   */
  friend std::ostream &operator<<(std::ostream &os, const MyType &mt) {
    os << mt.i << " " << mt.d;
    return os;
  }
};
/**
 * @brief Write the MyType object to a file
 * @param mt The MyType object to write
 * @param filename The name of the file to write to
 */
void writeToFile(const MyType &mt, const std::string &filename) {
  // Write the MyType object to a file with the given filename
  std::ofstream file(filename);
  file << mt;
}
/**
 * @brief Read the MyType object from a file
 * @param filename The name of the file to read from
 * @return The MyType object read from the file
 */
MyType readFromFile(const std::string &filename) {
  // Read the MyType object from a file with the given filename and return it
  std::ifstream file(filename);
  MyType mt(0, 0);
  file >> mt;
  return mt;
}
} // namespace homework
