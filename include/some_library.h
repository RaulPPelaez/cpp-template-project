#pragma once
#include <string>
namespace homework {

/**
 * @brief This function does something useful
 * @param a This is a double
 * @param str This is a string
 * @return The result of the useful operation
 */
int this_is_a_function(double a, std::string str);

/**
 * @brief This is a class that does something useful
 */
class ThisIsAClass {

  int internal_variable1;
  double internal_variable2;
public:
    /**
     * @brief This is a constructor
     */
    ThisIsAClass();

    /**
     * @brief This is a destructor
     */
    ~ThisIsAClass();

    /**
     * @brief This is a member function
     * @param a This is a double
     * @param str This is a string
     * @return The result of the useful operation
     */
    int this_is_a_member_function(double a, std::string str);
};

} // namespace homework
