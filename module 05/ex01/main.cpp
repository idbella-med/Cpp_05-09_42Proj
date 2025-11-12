#include "Bureaucrat.hpp"

int main() {
    std::cout << "===== create bureaucrats =====\n";
    Bureaucrat high("Alice", 5);
    Bureaucrat low("Bob", 140);
    std::cout << high << '\n' << low << "\n\n";

    std::cout << "===== create forms =====\n";
    Form tax("Tax Form", 25, 15);   // mid-range
    Form nda("NDA", 130, 130);      // low-range
    std::cout << tax << "\n" << nda << "\n\n";

    std::cout << "===== try to sign (high-grade bureaucrat) =====\n";
    high.signForm(tax);   // success
    high.signForm(nda);   // success

    std::cout << "\n===== try to sign (low-grade bureaucrat) =====\n";
    low.signForm(tax);    // fail
    low.signForm(nda);    // success

    std::cout << "\n===== final form states =====\n";
    std::cout << tax << "\n" << nda << '\n';

    std::cout << "\n===== exception tests =====\n";
    try {
        Form invalid("Invalid", 0, 1); 
    }   // too high
    catch (std::exception& e) {
        std::cout << e.what() << '\n'; 
    }

    try {
        Form invalid("Invalid", 151, 150);
    } // too low
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}