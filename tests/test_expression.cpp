#include "expression.h"
#include <gtest/gtest.h>
using namespace homework::expression;

TEST(Expression, SanityCheck) {
  Constant c1(1);
  Constant c2(2);
  Constant c3(3);
  BinaryPlus bp(c1, c2);
  BinaryPlus bp2(bp, c3);
  std::string c1plusc2plusc3 = bp2.toString();
  double result = bp2.evaluate();
  EXPECT_EQ(result, 6);
}

TEST(Expression, Polymorph) {
  Constant c1(1);
  Constant c2(2);
  Constant c3(3);
  BinaryPlus bp(c1, c2);
  BinaryPlus bp2(bp, c3);

  std::vector<const Expression *> expressions = {&c1, &c2, &c3, &bp, &bp2};
  for (const Expression *e_ptr : expressions) {
    const Expression &e = *e_ptr;
    printExpression(e);
  }
}

TEST(Expression, TypeConversion) {
  Constant c1(1);
  Constant c2(2);
  Constant c3(3);
  BinaryPlus bp(c1, c2);
  BinaryPlus bp2(bp, c3);
  std::string c1plusc2plusc3 = bp2.toString();
  std::string cast = static_cast<std::string>(bp2);
  EXPECT_EQ(c1plusc2plusc3, cast);
}
