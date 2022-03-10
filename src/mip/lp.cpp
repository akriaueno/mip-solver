#include "lp.hpp"
#include <limits>
#include <stdexcept>

MIP::LP::LP(): variable_list_(), constraint_list_(), objective_(), optimal_() {}

void MIP::LP::add_variable(MIP::Variable const &variable) {
  variable_list_.insert(variable);
}

void MIP::LP::add_variable(std::vector<MIP::Variable> const &variable_list) {
 for(auto variable: variable_list) {
   add_variable(variable);
 }
}

void MIP::LP::add_constraint(const MIP::Constraint const &constraint) {
  constraint_list_.push_back(constraint);
}

void MIP::LP::set_objective(const MIP::Objective const & objective) {
  objective_ = objective;
}

double MIP::LP::get_optimal() {
  return optimal_;
}

std::set<MIP::Variable> MIP::LP::get_variable() {
  return variable_list_;
}

void MIP::LP::solve() {
  // preprocessing
  if (variable_list_.empty()) {
    throw std::runtime_error("No variable");
  }
  if (objective_.isMaximize()) {
    optimal_ = std::numeric_limits<double>::lowest();
  } else if(objective_.isMinimize()) {
    optimal_ = std::numeric_limits<double>::max();
  } else {
    optimal_ = 0;
  }
  // TODO: implement
}