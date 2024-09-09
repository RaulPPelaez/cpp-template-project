#include "my_library.h"
#include "gtest/gtest.h"

// A Google test suite that checks that the function add in my library works

using namespace my_library;

TEST(AddTest, PositiveNumbers) {
	EXPECT_EQ(3, add(1, 2));
	EXPECT_EQ(5, add(2, 3));
	EXPECT_EQ(7, add(3, 4));
}

TEST(AddTest, NegativeNumbers) {
	EXPECT_EQ(-1, add(-2, 1));
	EXPECT_EQ(-3, add(-2, -1));
	EXPECT_EQ(-5, add(-3, -2));
}

TEST(AddTest, FloatingPointNumbers) {
	EXPECT_EQ(3.5, add(1.5, 2));
	EXPECT_EQ(5.5, add(2.5, 3));
	EXPECT_EQ(7.5, add(3.5, 4));
}
