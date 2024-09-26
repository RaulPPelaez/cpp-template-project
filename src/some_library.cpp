#include "some_library.h"

namespace homework {

int this_is_a_function(double a, std::string str) {
    return static_cast<int>(a) + str.size();
}

ThisIsAClass::ThisIsAClass() : internal_variable1(1), internal_variable2(10.0) {
}

ThisIsAClass::~ThisIsAClass() {
}

int ThisIsAClass::this_is_a_member_function(double a, std::string str) {
    return static_cast<int>(a) + str.size();
}

} // namespace homework
