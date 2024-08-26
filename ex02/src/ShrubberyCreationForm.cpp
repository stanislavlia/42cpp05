#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), _target("DefaultTarget")
{

};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shb_form)
    : AForm("ShrubberyCreationForm", 145, 137), _target(shb_form._target)
{

};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
};


ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shb_form)
{
     //We can't change anything in instance
    (void)shb_form; //do nothing
    
    return *this;
};


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    // Check if the form is signed and if the executor's grade is sufficient
    if (!isSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeToExec())
        throw AForm::GradeTooLowException();

    // Create the shrubbery file
    std::ofstream file((this->getFormName() + "_shrubbery").c_str());  // Convert to const char*
    if (!file)
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }

    file << "                      ___" << std::endl;
    file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    file << "             ,-'          __,,-- \\" << std::endl;
    file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    file << "     (     ,-'                  `." << std::endl;
    file << "      `._,'     _   _             ;" << std::endl;
    file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    file << "                \"Hb HH dF" << std::endl;
    file << "                 \"HbHHdF" << std::endl;
    file << "                  |HHHF" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  dHHHb" << std::endl;
    file << "                .dFd|bHb.               o" << std::endl;
    file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    file << "##########################################" << std::endl;

    file.close();
}