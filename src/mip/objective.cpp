#include "objective.hpp"

MIP::Objective::Objective(): expression_(), type_() {}

MIP::Objective::Objective(MIP::Expression::Linear expression, std::string type)
    : expression_(expression), type_(type) {}

MIP::Expression::Linear MIP::Objective::getExpression() {
  return expression_;
}

bool MIP::Objective::isMinimize() {
  return std::equal(type_.begin(), type_.end(), MIP::MINIMIZE);
}

bool MIP::Objective::isMaximize() {
  return std::equal(type_.begin(), type_.end(), MIP::MAXIMIZE);
}

