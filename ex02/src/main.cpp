#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat sergey("Sergey", 5);
    Bureaucrat jack("Jack", 90);

    ShrubberyCreationForm   shubform("Jack");

    sergey.signForm(shubform);
    jack.executeForm(shubform);

    return 0;
};