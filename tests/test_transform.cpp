#include "transform.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <list>
#include <string>
#include <vector>

using namespace homework;

TEST(Transform, IntVector) {
  std::vector v{1, 2, 3};
  auto doubled = v;
  transform(doubled, [](int x) { return x * 2; });
  ASSERT_EQ(doubled.size(), 3);
  for (auto i : v)
    ASSERT_EQ(doubled[i], v[i] * 2);
}
TEST(Transform, StringVector) {
  std::vector<std::string> v{"Hello", "World"};
  auto reversed = v;
  auto reverser = [](std::string s) {
    std::reverse(s.begin(), s.end());
    return s;
  };
  transform(reversed, reverser);
  ASSERT_EQ(reversed.size(), 2);
  ASSERT_EQ(reversed[0], "olleH");
  ASSERT_EQ(reversed[1], "dlroW");
}
TEST(Transform, SquareList) {
  std::list l{1, 2, 3};
  auto squared = l;
  transform(squared, [](int x) { return x * x; });
  ASSERT_EQ(squared.size(), 3);
  std::list expected{1, 4, 9};
  ASSERT_EQ(squared, expected);
}
TEST(Transform, DoubleVectorSum) {
  std::vector v{1.1, 2.2, 3.3};
  auto incremented = v;
  // Your code here
  transform(incremented, [](double x) { return x + 1; });
  ASSERT_EQ(incremented.size(), 3);
  for (int i = 0; i < 3; i++)
    ASSERT_EQ(incremented[i], v[i] + 1);
}
