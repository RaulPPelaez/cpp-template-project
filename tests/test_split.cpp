#include "gtest/gtest.h"
#include "split.h"
using namespace homework;
TEST(Split, MultipleWordsWithExtraSpaces){
  auto res = split(" hello world lorem ipsum ");
  ASSERT_EQ(res.size(),4);
  ASSERT_EQ(res[0],"hello");
  ASSERT_EQ(res[1],"world");
  ASSERT_EQ(res[2],"lorem");
  ASSERT_EQ(res[3],"ipsum");
}
