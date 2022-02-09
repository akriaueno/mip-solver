#ifndef MIP_CONSTRAINT_H_
#define MIP_CONSTRAINT_H_

#include <stdexcept>
#include <string>

#include "expression/linear.hpp"

namespace MIP {
class Constraint {
 public:
  Constraint(Expression::Linear &, std::string, double);

 private:
  Expression::Linear &l_expression_;
  double r_value_;
};

Constraint::Constraint(Expression::Linear &l_expression,
                       std::string inequality_sign, double r_value)
    : l_expression_(l_expression), r_value_(r_value) {
  if (inequality_sign == "<" || inequality_sign == "<=") {
    // do notiong
  } else if (inequality_sign == ">" || inequality_sign == ">=") {
    l_expression_.reverse_term_sign();
    r_value_ *= -1;
  } else {
    throw std::runtime_error("not implemented inequality_sign: " +
                             inequality_sign);
  }
}
}  // namespace MIP
#endif