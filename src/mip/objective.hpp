#ifndef MIP_OBJECTIVE_H_
#define MIP_OBJECTIVE_H_

#include <string>

#include "expression/linear.hpp"

namespace MIP {
class Objective {
 public:
  Objective(MIP::Expression::Linear &expression, std::string type)
      : expression_(expression), type_(type) {}

 private:
  MIP::Expression::Linear &expression_;
  std::string type_;
};
}  // namespace MIP
#endif