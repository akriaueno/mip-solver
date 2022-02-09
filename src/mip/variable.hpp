#ifndef MIP_VARIABLE_H_
#define MIP_VARIABLE_H_

#include <string>

namespace MIP {
class Variable {
 public:
  Variable(std::string name) : name_(name), value_(0) {}
  void set_value(double);
  double get_value() const;
  std::string get_name() const;
  bool operator<(const Variable &) const;

 private:
  std::string name_;
  double value_;
};

inline void Variable::set_value(double new_value) { value_ = new_value; }

inline double Variable::get_value() const { return value_; }

inline std::string Variable::get_name() const { return name_; }

inline bool Variable::operator<(const Variable &right) const {
  return name_ < right.name_;
}
}  // namespace MIP
#endif