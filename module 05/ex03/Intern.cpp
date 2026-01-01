#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm* createShrubberyForm(std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyForm(std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialForm(std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name_form, std::string target) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    AForm* (*formCreators[3])(std::string&) = {createShrubberyForm, createRobotomyForm, createPresidentialForm};
    
    for (int i = 0; i < 3; i++) {
        if (name_form == formNames[i]) {
            std::cout << "Intern creates " << name_form << std::endl;
            return formCreators[i](target);
        }
    }
    
    std::cout << "Error: Form name \"" << name_form << "\" does not exist!" << std::endl;
    return NULL;
}