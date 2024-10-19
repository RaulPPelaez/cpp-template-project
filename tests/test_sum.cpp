#include "sum.h"
#include "gtest/gtest.h"
#include <numeric>
#include <vector>
using namespace homework;
TEST(SumVector, Int) {
  std::vector<int> vint = {1, 2, 3, 4, 5};
  auto sum_ints = sum_elements(vint);
  auto sum_ints_ref = std::accumulate(vint.begin(), vint.end(), 0);
  ASSERT_EQ(sum_ints, sum_ints_ref);
}
TEST(SumVector, Double) {
  std::vector<double> vdouble = {1.1, 2.2, 3.3, 4.4, 5.5};
  auto sum_doubles = sum_elements(vdouble, 0.0);
  auto sum_doubles_ref = std::accumulate(vdouble.begin(), vdouble.end(), 0.0);
  ASSERT_NEAR(sum_doubles, sum_doubles_ref, 1e-10);
}
TEST(SumVector, String) {
  std::vector<std::string> vstring = {"hello", "world"};
  auto sum_strings = sum_elements(vstring, std::string());
  // We need to write std::string() because the default value of "" is const
  // char*. In this instance, we could also simply skip the second argument, as
  // the function can deduce the type and will use the default constructor for
  // it.
  ASSERT_EQ(sum_strings, "helloworld");
}
#include <list>
TEST(SumSequence, List) {
  std::list<int> lint = {1, 2, 3, 4, 5};
  auto sum_ints = sum_elements(lint, 0);
  auto sum_ints_ref = std::accumulate(lint.begin(), lint.end(), 0);
  ASSERT_EQ(sum_ints, sum_ints_ref);
}
#include <array>
TEST(SumSequence, Array) {
  std::array<int, 5> aint = {1, 2, 3, 4, 5};
  auto sum_ints = sum_elements(aint, 0);
  auto sum_ints_ref = std::accumulate(aint.begin(), aint.end(), 0);
  ASSERT_EQ(sum_ints, sum_ints_ref);
}

TEST(SumVector, CustomType) {
  struct MyType {
    int i;
    double d;
    bool operator==(const MyType &rhs) const {
      return i == rhs.i && d == rhs.d;
    }
    void operator+=(const MyType &rhs) {
      i += rhs.i;
      d += rhs.d;
    }
  };
  std::vector<MyType> vmt = {{1, 1.1}, {2, 2.2}, {3, 3.3}};
  auto sum_mts = sum_elements(vmt, MyType{0, 0.0});
  ASSERT_EQ(sum_mts, (MyType{6, 6.6}));
}

#include <tuple>
TEST(Tuple, make) {
  auto t = my_make_tuple(1, 2.2, "hello");
  ASSERT_EQ(std::get<0>(t), 1);
  ASSERT_NEAR(std::get<1>(t), 2.2, 1e-10);
  ASSERT_EQ(std::get<2>(t), "hello");
}
TEST(Tuple, make2) {
  auto t = my_make_tuple("word", (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(std::get<0>(t), "word");
  ASSERT_EQ(std::get<1>(t), (std::vector<int>{1, 2, 3}));
}
