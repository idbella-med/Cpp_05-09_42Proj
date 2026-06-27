#include "RPN.hpp"


int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cerr << "Usage ./RPN \'num1 num2 op\'" << std::endl;
        return 1;
    }
    try {
        RPN rpn;
        rpn.processInput(av[1]);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}