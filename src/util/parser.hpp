#ifndef UTIL_PARESER_H_
#define UTIL_PARSER_H_

#include <string>

#include "../mip/expression/linear.hpp"

namespace Util {
class Paraser {
 public:
  static MIP::Expression::Linear &parse(std::string);
};
}  // namespace Util
#endif