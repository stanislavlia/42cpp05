#include "Bureaucrat.hpp"

//=====================CONSTRUCTORS==========================

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150) //lowest grade by default
{

};

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
{
    //Need to throw exception if out of range!
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    //Need to throw exception if out of range!
    if (other._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (other._grade > 150)
        throw Bureaucrat::GradeTooLowException();
};

Bureaucrat::~Bureaucrat()
{

};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (other._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (other._grade > 150)
        throw Bureaucrat::GradeTooLowException();

    //We can copy only grade
    _grade = other._grade;
    return *this;
};



const std::string& Bureaucrat::getName() const
{
    return _name;
};

unsigned int Bureaucrat::getGrade() const
{
    return _grade;
};

void    Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();

    std::cout << "Increment grade for "<< getName() << std::endl;
    _grade -= 1;
};

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Decrement grade for "<< getName() << std::endl;
    _grade += 1;
};

//====================EXCEPTION IMPLEMENTATION===============================
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "The grade is too high. The highest possible grade is 1\n";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "The grade is too low. The lowest possible grade is 150\n";
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj)
{
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return o;
};