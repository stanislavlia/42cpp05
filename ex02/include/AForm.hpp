#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat; // to resolve circular dependency

class AForm
{
    private:
        const std::string _name;
        bool _is_signed;
        unsigned int _grade_to_sign;
        unsigned int _grade_to_execute;
    
    public:
        AForm();
        AForm(const std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();
        
        unsigned int getGradeToSign() const;
        unsigned int getGradeToExec() const;
        const std::string& getFormName() const;
        bool isSigned() const;
        void beSigned(const Bureaucrat& bur);

        // Exception classes for AForm
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();  // throw() guarantees no exception raised in func
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();  // throw() guarantees no exception raised in func
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
