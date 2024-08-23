#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool  _is_signed;
        unsigned int _grade_to_sign;
        unsigned int _grade_to_execute;
    
    public:
        Form();
        Form(const std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute);
        Form(const Form& other);
        ~Form();

        

};


std::ostream& operator<<(std::ostream& o, const Form& obj);


# endif