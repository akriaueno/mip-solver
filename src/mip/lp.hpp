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
  void add_variable(MIP::Variable const &);
  void add_variable(std::vector<MIP::Variable> const &);
  void set_objective(const MIP::Objective const &);
  void add_constraint(const MIP::Constraint const &);
  double get_optimal();
  std::set<MIP::Variable> get_variable();
  void solve();

 private:
  std::set<MIP::Variable> variable_list_;
  MIP::Objective objective_;
  std::vector<MIP::Constraint> constraint_list_;
  double optimal_;
};
}  // namespace MIP
#endif
