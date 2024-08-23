#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1;
    Bureaucrat sergey("Sergey", 5);
    Bureaucrat jack("Jack", 90);
    Bureaucrat john("John", 2);

    std::cout << b1;
    std::cout << sergey;
    std::cout << jack;
    std::cout << john;

    //increment grade for sergey and decrement for jack 2 times
    sergey.incrementGrade();
    sergey.incrementGrade();
    jack.decrementGrade();
    jack.decrementGrade();
    
    std::cout << "=========GRADES after modification for Jack and Sergey ===============\n";

    std::cout << b1;
    std::cout << sergey;
    std::cout << jack;
    std::cout << john;

    //Now let's try to create instance with too low grade or too high and see exceptions
    //Bureaucrat lowgr("LowGradeMan", 200);
    //Bureaucrat higr("HiGradeMan", 0);
    
    std::cout << "=============LET's INCREMENT UNLESS WE HIT EXCEPTION==============\n";
    try
    {   
        john.incrementGrade();
        john.incrementGrade();
        john.incrementGrade();
        john.incrementGrade();
        john.incrementGrade();
        john.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        // Handle the exception
        std::cerr << "Got RangeException: ";
        std::cerr << e.what() << std::endl;
    }

    std::cout << "=============LET's Try to create wrong instance==============\n";
    try
    {
        Bureaucrat wrong("WrongMan", 900);
        //Bureaucrat wrong("WrongMan2", 0);
    }
    catch (const std::exception& e) //specifing base exception, we can catch any exception
    {
        std::cerr << "Some exception occured within block! Check it out:\n";
        std::cerr << e.what();
    }
    

    return 0;
};