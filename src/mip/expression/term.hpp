#ifndef MIP_EXPRESSION_TERM_H_
#define MIP_EXPRESSION_TERM_H_

#include "../variable.hpp"

namespace MIP {
namespace Expression {
class Term {
  public:
    Term(double coefficient, MIP::Variable &variable)
        : coefficient_(coefficient), variable_(variable) {}
    void set_coefficient(double);
    double get_coefficient() const;
    MIP::Variable get_variable() const;

  private:
    double coefficient_;
    MIP::Variable &variable_;
};

inline void MIP::Expression::Term::set_coefficient(double new_value) {
    coefficient_ = new_value;
}

inline double MIP::Expression::Term::get_coefficient() const {
    return coefficient_;
}

inline MIP::Variable MIP::Expression::Term::get_variable() const {
    return variable_;
}

std::ostream &operator<<(std::ostream &lhs, const Term &rhs) {
    lhs << std::to_string(rhs.get_coefficient()) + " " +
               rhs.get_variable().get_name();
    return lhs;
}
} // namespace Expression
} // namespace MIP
#endif