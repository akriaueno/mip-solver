#ifndef MIP_EXPRESSION_LINEAR_H_
#define MIP_EXPRESSION_LINEAR_H_

#include "term.hpp"

#include <iostream>
#include <vector>

namespace MIP {
namespace Expression {
class Linear {
  public:
    Linear() : term_list_() {}
    void add_term(MIP::Expression::Term);
    void reverse_term_sign();
    std::vector<MIP::Expression::Term> get_term_list() const;

  private:
    std::vector<MIP::Expression::Term> term_list_;
};

inline void MIP::Expression::Linear::add_term(MIP::Expression::Term term) {
    term_list_.push_back(term);
}

inline std::vector<MIP::Expression::Term>
MIP::Expression::Linear::get_term_list() const {
    return term_list_;
}

inline void MIP::Expression::Linear::reverse_term_sign() {
    for(auto &term : this->term_list_) {
        term.set_coefficient(term.get_coefficient() * -1.0);
    }
}

std::ostream &operator<<(std::ostream &lhs, const Linear &rhs) {
    auto term_list = rhs.get_term_list();
    for(int i = 0; i < term_list.size(); i++) {
        std::string end = (i < term_list.size() - 1) ? " + " : "";
        lhs << term_list[i] << end;
    };
    return lhs;
}
} // namespace Expression
} // namespace MIP
#endif