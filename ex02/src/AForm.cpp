#include "AForm.hpp"
#include "Bureaucrat.hpp"

//===============CONSTRUCTORS======================
AForm::AForm() : _name("DefaultFormA1"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150)
{

}

AForm::AForm(const std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute) : 
    _name(name), _is_signed(false), 
    _grade_to_sign(grade_to_sign),
    _grade_to_execute(grade_to_execute)
{
    if (_grade_to_sign < 1 || _grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    if (_grade_to_sign > 150 || _grade_to_execute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) :
    _name(other._name), _is_signed(other._is_signed),
    _grade_to_sign(other._grade_to_sign),
    _grade_to_execute(other._grade_to_execute)
{
    if (_grade_to_sign < 1 || _grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    if (_grade_to_sign > 150 || _grade_to_execute > 150)
        throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
    if (other._grade_to_sign < 1 || other._grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    if (other._grade_to_sign > 150 || other._grade_to_execute > 150)
        throw AForm::GradeTooLowException();
    
    // copy params that we can modify (name is const)
    _is_signed = other._is_signed;
    _grade_to_sign = other._grade_to_sign;
    _grade_to_execute = other._grade_to_execute;

    return *this;
}

AForm::~AForm()
{

}

//===============GETTERS======================
const std::string& AForm::getFormName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _is_signed;
}

unsigned int AForm::getGradeToExec() const
{
    return _grade_to_execute;  
}

unsigned int AForm::getGradeToSign() const
{
    return _grade_to_sign;  
}

std::ostream& operator<<(std::ostream& o, const AForm& obj)
{   
    o << "=========FORM INFO=================" << std::endl;
    o << "FORM: " << obj.getFormName() << std::endl;
    o << "SIGNED: " << obj.isSigned() << std::endl;
    o << "Minimal Grade to Sign: " << obj.getGradeToSign() << std::endl;
    o << "Minimal Grade to Execute: " << obj.getGradeToSign() << std::endl;

    return o;
}

//=================FORM EXCEPTIONS==========================
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form Exception: Grade TOO HIGH!\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form Exception: Grade TOO LOW!!\n";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Form must be SIGNED before execution!\n";
}

void AForm::beSigned(const Bureaucrat& bur)
{
    if (bur.getGrade() > _grade_to_sign)
        throw AForm::GradeTooLowException();
    
    _is_signed = true;
}
