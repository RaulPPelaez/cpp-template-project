// Declarations of the functionality exposed by the library

// This pragma makes sure that the header is included only once
// Some people prefer to use #ifndef, #define, #endif instead like one would do in C
#pragma once

namespace my_library{

  /**
   * @brief A very cool function that prints some messages
   *
   * This function is very cool and prints some messages to the console.
   * It is also documented using Doxygen style comments.
   */
  void very_cool_function();

  /**
   * @brief Adds two numbers
   *
   * @param a The first number
   * @param b The second number
   * @return The sum of the two numbers
   */
  double add(double a, double b);

}
