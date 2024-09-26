#include <gtest/gtest.h>
#include "some_library.h"
using namespace homework;

TEST(SomeLibrary, SanityCheck){
  EXPECT_EQ(this_is_a_function(10, "abcde"), 15);
}
