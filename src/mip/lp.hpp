#ifndef MIP_LP_H_
#define MIP_LP_H_

#include <set>
#include <string>
#include <vector>

#include "constraint.hpp"
#include "objective.hpp"

namespace MIP {
class LP {
 public:
  LP();
  void add_variable(MIP::Variable);
  void add_variable(std::vector<MIP::Variable>);
  void set_objective(MIP::Expression::Linear);
  void add_constraint(MIP::Expression::Linear, std::string, double);
  void solve();
  double get_optimal();
  std::vector<MIP::Variable> get_optimal_variable();

 private:
  std::set<MIP::Variable> variable_list_;
  MIP::Objective objective_;
  std::vector<MIP::Constraint> constraint_list_;
};
}  // namespace MIP
#endif
