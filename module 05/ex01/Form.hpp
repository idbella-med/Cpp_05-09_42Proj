#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
    private:
        const std::string Name;
        bool is_it_Signed;
        const int G_required_Sign;
        const int G_required_Execute;

    public:
        Form();
        ~Form();
        void beSigned(Bureaucrat& bureaucrat);

};

std::ostream& operator<<(std::ostream& out, const Form& form);


#endif