#include "flexible_container.h"
#include "gtest/gtest.h"
#include <string>
using namespace homework;
TEST(FlexibleContainer, IntStorage) {
  FlexibleContainer<int> container;
  container.add(5);
  container.add(10);
  ASSERT_EQ(container.size(), 2);
  ASSERT_EQ(container.get(0), 5);
  ASSERT_EQ(container.get(1), 10);
}
TEST(FlexibleContainer, StringStorage) {
  FlexibleContainer<std::string> container;
  container.add("Hello");
  container.add("World");
  ASSERT_EQ(container.size(), 2);
  ASSERT_EQ(container.get(0), "Hello");
  ASSERT_EQ(container.get(1), "World");
}
TEST(FlexibleContainer, DefaultType) {
  FlexibleContainer container;
  container.add(42);
  ASSERT_EQ(container.size(), 1);
  ASSERT_EQ(container.get(0), 42);
}
TEST(FlexibleContainer, MapFunction) {
  FlexibleContainer<int> container;
  container.add(1);
  container.add(2);
  container.add(3);
  auto doubled = container;
  doubled.map([](int x) { return x * 2; });
  ASSERT_EQ(doubled.size(), 3);
  ASSERT_EQ(doubled.get(0), 2);
  ASSERT_EQ(doubled.get(1), 4);
  ASSERT_EQ(doubled.get(2), 6);
}

TEST(FlexibleContainer, VariadicConstructor) {
  FlexibleContainer<int> container(1, 2, 3, 4, 5);
  ASSERT_EQ(container.size(), 5);
  ASSERT_EQ(container.get(0), 1);
  ASSERT_EQ(container.get(4), 5);
  FlexibleContainer<std::string> strContainer("Hello", "World", "C++");
  ASSERT_EQ(strContainer.size(), 3);
  ASSERT_EQ(strContainer.get(0), "Hello");
  ASSERT_EQ(strContainer.get(2), "C++");
}
