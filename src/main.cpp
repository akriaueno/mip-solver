#include "mip/expression/linear.hpp"
#include "mip/expression/term.hpp"
#include "mip/variable.hpp"

#include <iostream>

int main() {
    auto linar1 = MIP::Expression::Linear();

    MIP::Variable x1("x1");
    MIP::Expression::Term term1(3.0, x1);
    linar1.add_term(term1);
    std::cout << linar1 << std::endl;

    MIP::Variable x2("x2");
    MIP::Expression::Term term2(-1.0, x2);
    linar1.add_term(term2);
    std::cout << linar1 << std::endl;

    linar1.reverse_term_sign();
    std::cout << linar1 << std::endl;
}
