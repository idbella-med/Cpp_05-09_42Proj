#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "=== Test 1: Intern creates valid forms ===" << std::endl;
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        
        std::cout << "\n--- Creating Robotomy Request ---" << std::endl;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
        
        std::cout << "\n--- Creating Shrubbery Creation ---" << std::endl;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
        if (scf) {
            std::cout << *scf << std::endl;
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }
        
        std::cout << "\n--- Creating Presidential Pardon ---" << std::endl;
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (ppf) {
            std::cout << *ppf << std::endl;
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Invalid form name ===" << std::endl;
    try {
        Intern intern;
    
        AForm* invalid = intern.makeForm("coffee making", "break room");
        if (invalid) {
            delete invalid;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}