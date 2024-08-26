#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


int main()
{
    //=======employees==========
    Bureaucrat sergey("Sergey", 5);
    Bureaucrat jack("Jack", 40);
    Bureaucrat kane("Kane", 135);
    Bureaucrat kassy("Kassy", 90);

    //=======forms=================
    ShrubberyCreationForm   sb_form("Kane");
    RobotomyRequestForm     rb_form("Jack");
    PresidentialPardonForm  prs_form("Sergey");

    std::cout << "=========TRY TO EXECUTE NOT SIGNED FORMS===============\n";
    //try to execute not signed form
    sergey.executeForm(sb_form);
    kane.executeForm(rb_form);

    std::cout << "=========SIGN FORMS===============\n";
    //now, let's sign them
    sergey.signForm(prs_form);
    jack.signForm(rb_form);
    kassy.signForm(sb_form);
    
    std::cout << "=========TRY TO EXECUTE===============\n";
    //try execute without needed grade
    kane.executeForm(prs_form);
    kassy.executeForm(prs_form);

    std::cout << "=========EXECUTE FORMS CORRECTLY===============\n";
    //execute forms appropriately
    kane.executeForm(sb_form);
    jack.executeForm(rb_form);
    sergey.executeForm(prs_form);

    return 0;
};