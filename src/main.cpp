#include "mip/expression/linear.hpp"
#include "mip/expression/term.hpp"
#include "mip/variable.hpp"

#include <iostream>

int main() {
    auto linear = MIP::Expression::Linear();

    MIP::Variable x1("x1");
    MIP::Expression::Term term1(3.0, x1);
    linear.add_term(term1);
    std::cout << linear << std::endl;

    MIP::Variable x2("x2");
    MIP::Expression::Term term2(-1.0, x2);
    linear.add_term(term2);
    std::cout << linear << std::endl;

    linear.reverse_term_sign();
    std::cout << linear << std::endl;
}
