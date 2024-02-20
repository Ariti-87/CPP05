#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << BLUE << "Default AForm" << RESET << " has been created" << std::endl;
}

AForm::AForm(std::string const name, unsigned int gradeSign, unsigned int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << BLUE << "AForm " << this->_name << RESET << " has been created" << std::endl;
	if (gradeSign > 150 || gradeExec > 150)
	{
		std::cout << RED;
		throw AForm::GradeTooLowException();
		std::cout << std::endl;
	}
	else if (gradeSign < 1 || gradeExec < 1)
	{
		std::cout << RED;
		throw AForm::GradeTooHighException();
		std::cout << std::endl;
	}
}

AForm::AForm(AForm const& source) : _name(source._name), _signed(source._signed), _gradeSign(source._gradeSign), _gradeExec(source._gradeExec)
{
	std::cout << BLUE << "Copy AForm " << this->_name << RESET << " has been created" << std::endl;
}

AForm::~AForm()
{
	std::cout << BLUE << "AForm " << this->_name << RESET << " has been destroyed" << std::endl;
}

AForm & AForm::operator=(AForm const&)
{
	return *this;
}

std::string AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getSigned(void) const
{
	return this->_signed;
}

unsigned int AForm::getGradeExec(void) const
{
	return this->_gradeExec;
}

unsigned int AForm::getGradeSign(void) const
{
	return this->_gradeSign;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void AForm::beSigned(Bureaucrat const& Bur)
{
	if (this->_gradeSign < Bur.getGrade())
	{
		std::cout << RED << "Bureaucrat " << Bur.getName() << ": " ;
		throw AForm::GradeTooLowException();
		std::cout << std::endl;
	}
	else
	{
		std::cout << LGREEN << "Bureaucrat " << Bur.getName() << RESET << " signed " << this->getName() << std::endl;
		this->_signed = true;
	}
}

std::ostream &operator<<(std::ostream &o, AForm const& source)
{
	o << BLUE << "AForm " << source.getName() << RESET << " has a grade for sign of : " << source.getGradeSign();
	o << ", and a grade for exec of : " << source.getGradeExec();
	if (!source.getSigned())
		o << " this Aform is no signed";
	else
		o << " this Aform is signed";
	return o;
}


// std::ostream &operator<<(std::ostream &o, Form const& source)
// {
// 	o << BLUE << "Form " << source.getName() << RESET << " has a grade for sign of : " << source.getGradeSign();
// 	o << ", and a grade for exec of : " << source.getGradeExec() << ", This form is " << (source.getSigned() ? "" : "no") << " signed";
// 	return o;
// }