#include <iostream>
#include <string>
namespace homework {

namespace expression {
/**
 * @brief Base class for all expressions
 *
 */
struct Expression {
  /**
   * @brief Convert the expression to a string
   *
   * @return std::string
   */
  virtual std::string toString() const = 0;

  /**
   * @brief Evaluate the expression
   *
   * @return double
   */
  virtual double evaluate() const = 0;

  /**
   * @brief Convert the expression to a string
   *
   * @return std::string
   */
  explicit operator std::string() const { return toString(); }
};

/**
 * @brief A constant expression
 *
 */
class Constant : public Expression {
  double value;

public:
  Constant(double value) : value(value) {} ///< Constructor
  std::string toString() const override { return std::to_string(value); }
  double evaluate() const override { return value; }
};

class BinaryPlus : public Expression {
  Expression &left, &right;

public:
  BinaryPlus(Expression &left, Expression &right)
      : left(left), right(right) {} ///< Constructor
  std::string toString() const override {
    return "(" + left.toString() + " + " + right.toString() + ")";
  }
  double evaluate() const override {
    return left.evaluate() + right.evaluate();
  }
};

/**
 * @brief Print the expression
 *
 * @param expression
 */
void printExpression(const Expression &expression) {
  std::cout << expression.toString() << " = " << expression.evaluate()
            << std::endl;
}
} // namespace expression

} // namespace homework
