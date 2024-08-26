#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    //=======employees==========
    Bureaucrat sergey("Sergey", 5);
    Bureaucrat jack("Jack", 40);
    Intern  intern;

    //allowed forms:
        // "RobotomyRequestForm",
        // "PresidentialPardonForm",
        // "ShrubberyCreationForm"

    //=======Let Interns create forms =================
    AForm   *form1 = intern.makeForm("RobotomyRequestForm", "Sergey");
    AForm   *form2 = intern.makeForm("ShrubberyCreationForm", "Jack");

    //try to create not existing form; raise exception
    //AForm   *form3 = intern.makeForm("BlaBlaForm", "Sergey");

    sergey.signForm(*form1);
    jack.signForm(*form2);

    jack.executeForm(*form1);
    jack.executeForm(*form2);

    return 0;
};