#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Form"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << BLUE << "Default Form" << RESET << " has been created" << std::endl;
}

Form::Form(std::string const name, unsigned int gradeSign, unsigned int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << BLUE << "Form " << this->_name << RESET << " has been created" << std::endl;
	if (gradeSign > 150 || gradeExec > 150)
	{
		std::cout << RED;
		throw Form::GradeTooLowException();
		std::cout << std::endl;
	}
	else if (gradeSign < 1 || gradeExec < 1)
	{
		std::cout << RED;
		throw Form::GradeTooHighException();
		std::cout << std::endl;
	}
}

Form::Form(Form const& source) : _name(source._name), _signed(source._signed), _gradeSign(source._gradeSign), _gradeExec(source._gradeExec)
{
	std::cout << BLUE << "Copy Form " << this->_name << RESET << " has been created" << std::endl;
}

Form::~Form()
{
	std::cout << BLUE << "Form " << this->_name << RESET << " has been destroyed" << std::endl;
}

Form & Form::operator=(Form const& src)
{
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return *this;
}

std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::getSigned(void) const
{
	return this->_signed;
}

unsigned int Form::getGradeExec(void) const
{
	return this->_gradeExec;
}

unsigned int Form::getGradeSign(void) const
{
	return this->_gradeSign;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void Form::beSigned(Bureaucrat const& Bur)
{
	if (this->_gradeSign < Bur.getGrade())
	{
		std::cout << RED << "Bureaucrat " << Bur.getName() << ": " ;
		throw Form::GradeTooLowException();
		std::cout << std::endl;
	}
	else
	{
		std::cout << LGREEN << "Bureaucrat " << Bur.getName() << RESET << " signed " << this->getName() << std::endl;
		this->_signed = true;
	}
}

std::ostream &operator<<(std::ostream &o, Form const& source)
{
	o << BLUE << "Form " << source.getName() << RESET << " has a grade for sign of : " << source.getGradeSign();
	o << ", and a grade for exec of : " << source.getGradeExec();
	if (!source.getSigned())
		o << " this form is no signed";
	else
		o << " this form is signed";
	return o;
}


// std::ostream &operator<<(std::ostream &o, Form const& source)
// {
// 	o << BLUE << "Form " << source.getName() << RESET << " has a grade for sign of : " << source.getGradeSign();
// 	o << ", and a grade for exec of : " << source.getGradeExec() << ", This form is " << (source.getSigned() ? "" : "no") << " signed";
// 	return o;
// }
