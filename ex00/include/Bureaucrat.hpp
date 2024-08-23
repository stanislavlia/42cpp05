#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
private:
    const std::string _name;
    unsigned int _grade; // grade 1 - highest; grade 150 - lowest (reverse direction)

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, unsigned int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string& getName() const;
    unsigned int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();  // throw() guarantees no exception raised in func
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();  // throw() guarantees no exception raised in func
    };
};

// Non-member function for operator<<
std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj);

#endif
