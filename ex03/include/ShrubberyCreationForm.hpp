#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
    
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& shb_form);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shb_form);

        void execute(const Bureaucrat& bur) const;
};

#endif