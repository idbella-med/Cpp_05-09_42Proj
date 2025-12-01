#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name("Default"), Grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : Name(name) {
    std::cout << "Bureaucrat parametric constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    Grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : Name(bureaucrat.Name), Grade(bureaucrat.Grade) {
        std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
    this->Grade = bureaucrat.getGrade();
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return Name;
}

int Bureaucrat::getGrade() const {
    return Grade;
}

void Bureaucrat::incrementGrade() {
    if (Grade - 1 < 1)
        throw GradeTooHighException();
    Grade--;
}

void Bureaucrat::decrementGrade() {
    if (Grade + 1 > 150)
        throw GradeTooLowException();
    Grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat deconstructor called" << std::endl;
};