// include/split.h
#pragma once
#include <string>
#include <vector>
namespace homework{
  /**
   * @brief Returns a vector of whitespace-separated substrings from the
   argument string
   * @param str The string to split
   * @return A vector of whitespace-separated substrings
   */
  std::vector<std::string> split(const std::string& str);
} // namespace homework
