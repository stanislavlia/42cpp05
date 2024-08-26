#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{

    public:
        Intern();
        ~Intern();
        Intern(const Intern& intern);
        Intern& operator=(const Intern& intern);
        
        AForm*  makeForm(std::string form_name, std::string target);

    class FormNotSupportedException : public std::exception
    {
        public:
            const char* what() const throw();
    };

};

#endif