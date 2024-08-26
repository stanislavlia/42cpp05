#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat sergey("Sergey", 5);
    Bureaucrat jack("Jack", 90);

    ShrubberyCreationForm   shubform("Jack");
    RobotomyRequestForm     rbform("Sergey");

    sergey.signForm(shubform);
    sergey.signForm(rbform);
    jack.executeForm(shubform);
    sergey.executeForm(rbform);

    return 0;
};