#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anonyme"), _grade(150)
{
	std::cout << LGREEN << "Default Bureaucrat" << RESET << " has been created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name)
{
	std::cout << LGREEN << "Bureaucrat " << this->_name << RESET << " has been created" << std::endl;
	if (grade > 150)
	{
		std::cout << RED;
		throw Bureaucrat::GradeTooLowException();
		std::cout << std::endl;
	}
	else if (grade < 1)
	{
		std::cout << RED;
		throw Bureaucrat::GradeTooHighException();
		std::cout << std::endl;
	}
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& source) : _name(source._name), _grade(source._grade)
{
	std::cout << LGREEN << "Copy Bureaucrat " << this->_name << RESET << " has been created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << LGREEN << "Bureaucrat " << this->_name << RESET << " has been destroyed" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const& source)
{
	if (this != &source)
		this->_grade = source._grade;
	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat : Highest possibe grade : 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat : Lowest possibe grade : 150");
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const& source)
{
	o << LGREEN << "Bureaucrat " << source.getName() << RESET << " has a grade of " << source.getGrade();
	return o;
}

void Bureaucrat::signForm(AForm & f) const
{
	try
	{
		if (this->_grade < f.getGradeSign())
			throw AForm::GradeTooLowException();
		else
			f.beSigned(*this);
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << RED << "Bureaucrat " << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
		std::cout <<LGREEN << "Bureaucrat " << this->_name << RESET << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Bureaucrat " << this->_name << " couldn't execute " << form.getName() << std::endl;
	}
}

