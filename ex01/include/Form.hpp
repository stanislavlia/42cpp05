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
        Form& operator=(const Form& other);
        ~Form();

        
        unsigned int getGradetoSign() const;
        unsigned int getGradetoExec() const;
        const std::string& getFormName() const;
        bool         isSigned() const;
        void         beSigned(Bureaucrat& bur);

    // Exception classes for Form
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();  // throw() guarantees no exception raised in func
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();  // throw() guarantees no exception raised in func
    };
    
};


std::ostream& operator<<(std::ostream& o, const Form& obj);


#endif