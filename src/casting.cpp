#include <iostream>
#include <cstdint>

int main() {
  int32_t intValue = 0x40000000;  // Binary: 01000000 00000000 00000000 00000000

  // C-style cast
  float floatValue1 = (float)intValue;

  // static_cast
  float floatValue2 = static_cast<float>(intValue);

  // reinterpret_cast
  float floatValue3 = *reinterpret_cast<float*>(&intValue);

  std::cout << "C-style cast: " << floatValue1 << std::endl;
  std::cout << "static_cast: " << floatValue2 << std::endl;
  std::cout << "reinterpret_cast: " << floatValue3 << std::endl;

  return 0;
}
