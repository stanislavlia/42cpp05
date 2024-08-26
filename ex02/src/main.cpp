#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    Bureaucrat sergey("Sergey", 5);
    Bureaucrat jack("Jack", 90);

    AForm f1;
    AForm f2("TM30", 10, 20);
    AForm f3("B34", 120, 150);

    //uncomment this  to hit exception
    //Form f4("TTTTTTTTT40", 100000, 30);
    
    std::cout << f1;
    std::cout << f2;
    std::cout << f3;
    
    std::cout << "LET's SIGN THEM!\n";

    jack.signForm(f1);
    jack.signForm(f2);
    jack.signForm(f3);

    std::cout << "\nChecking Form status...\n";
    std::cout << "Is " << f1.getFormName() << "signed?: " << f1.isSigned() << std::endl;
    std::cout << "Is " << f2.getFormName() << "signed?: " << f2.isSigned() << std::endl;
    std::cout << "Is " << f3.getFormName() << "signed?: " << f3.isSigned() << std::endl;
    
    std::cout << "\nLet higher-rank clerk to sign the remaining form..." << std::endl;
    sergey.signForm(f2);

    std::cout << "\nChecking Form status AGAIN...\n";
    std::cout << "Is " << f1.getFormName() << "signed?: " << f1.isSigned() << std::endl;
    std::cout << "Is " << f2.getFormName() << "signed?: " << f2.isSigned() << std::endl;
    std::cout << "Is " << f3.getFormName() << "signed?: " << f3.isSigned() << std::endl;

    return 0;
};