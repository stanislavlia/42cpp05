#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>


class Bureaucrat
{
    private:
        const std::string name;
        unsigned int grade;
    
    public:
        Bureaucrat();
        Bureaucrat(std::string &name, unsigned int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        const Bureaucrat& operator=(const Bureaucrat& other);

        const std::string& getName() const;
        unsigned int getGrade();

};


#endif