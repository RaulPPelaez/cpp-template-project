// tests/test_pair.cpp
#include "pair.h"
#include "gtest/gtest.h"

using namespace homework;
TEST(Pair, IntPair) {
  Pair<int, int> p{1, 2};
  ASSERT_EQ(p.first, 1);
  ASSERT_EQ(p.second, 2);
}
TEST(Pair, DoublePair) {
  Pair<double, double> p{1.1, 2.2};
  ASSERT_EQ(p.first, 1.1);
  ASSERT_EQ(p.second, 2.2);
}
TEST(Pair, IntStringPair) {
  Pair<int, std::string> p{1, "Hello"};
  ASSERT_EQ(p.first, 1);
  ASSERT_EQ(p.second, "Hello");
}
