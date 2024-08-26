#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& intern)
{
    (void)intern;
}

Intern::~Intern()
{}

Intern& Intern::operator=(const Intern& intern)
{
    (void)intern;
    return *this;
}

const char* Intern::FormNotSupportedException::what() const throw()
{
    return "Intern Exception: This Form is not supportable or doesn't exist!\n";
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
    //allowed forms:
        // "RobotomyRequestForm",
        // "PresidentialPardonForm",
        // "ShrubberyCreationForm"

    AForm* forms_candidates[] = {
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
        new ShrubberyCreationForm(target),
    };

    for (int i=0; i < 3; i++)
    {
        if (forms_candidates[i]->getFormName() == form_name)
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return forms_candidates[i];
        }
    };
    throw FormNotSupportedException();
}