#ifndef MIP_OBJECTIVE_H_
#define MIP_OBJECTIVE_H_

#include <string>

#include "expression/linear.hpp"

namespace MIP {
const std::string MINIMIZE = "minimize";
const std::string MAXIMIZE = "maximize";

class Objective {
 public:
  Objective();
  Objective(MIP::Expression::Linear, std::string);
  MIP::Expression::Linear getExpression();
  bool isMinimize();
  bool isMaximize();

 private:
  MIP::Expression::Linear expression_;
  std::string type_;
};
}  // namespace MIP
#endif