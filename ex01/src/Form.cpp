#include "Form.hpp"
#include "Bureaucrat.hpp"

//===============CONSTRUCTORS======================
Form::Form() : _name("DefaultFormA1"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150)
{

};

Form::Form(const std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute) : 
    _name(name), _is_signed(false), 
    _grade_to_sign(grade_to_sign),
    _grade_to_execute(grade_to_execute)
{
    if (_grade_to_sign < 1 || _grade_to_execute < 1)
        throw Form::GradeTooHighException();
    if (_grade_to_sign > 150 || _grade_to_execute > 150)
        throw Form::GradeTooLowException();
};

Form::Form(const Form& other) :
    _name(other._name), _is_signed(other._is_signed),
    _grade_to_sign(other._grade_to_sign),
    _grade_to_execute(other._grade_to_execute)
{
    if (_grade_to_sign < 1 || _grade_to_execute < 1)
        throw Form::GradeTooHighException();
    if (_grade_to_sign > 150 || _grade_to_execute > 150)
        throw Form::GradeTooLowException();
};

Form&  Form::operator=(const Form& other)
{
    if (other._grade_to_sign < 1 || other._grade_to_execute < 1)
        throw Form::GradeTooHighException();
    if (other._grade_to_sign > 150 || other._grade_to_execute > 150)
        throw Form::GradeTooLowException();
    
    //copy params that we can modify (name is const)
    _is_signed = other._is_signed;
    _grade_to_sign = other._grade_to_sign;
    _grade_to_execute = other._grade_to_execute;

    return *this;
};

Form::~Form()
{

};

//===============GETTERS======================
const std::string& Form::getFormName() const
{
    return _name;
};

bool Form::isSigned() const
{
    return _is_signed;
};

unsigned int Form::getGradetoExec() const
{
    return _grade_to_execute;  
};

unsigned int Form::getGradetoSign() const
{
    return _grade_to_sign;  
};

std::ostream& operator<<(std::ostream& o, const Form& obj)
{   
    o << "=========FORM INFO=================" << std::endl;
    o << "FORM: " << obj.getFormName() << std::endl;
    o << "SIGNED: " << obj.isSigned() << std::endl;
    o << "Minimal Grade to Sign: " << obj.getGradetoSign() << std::endl;
    o << "Minimal Grade to Execute: " << obj.getGradetoSign() << std::endl;

    return o;
};


//=================FORM EXCEPTIONS==========================
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Exception: Grade TOO HIGH!\n";
};

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Exception: Grade TOO LOW!!\n";
};


void    Form::beSigned(const Bureaucrat& bur)
{
    if (bur.getGrade() > _grade_to_sign)
        throw Form::GradeTooLowException();
    _is_signed = true;

};