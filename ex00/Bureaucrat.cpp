#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anonyme"), _grade(150)
{
	std::cout << LGREEN << "Default Bureaucrat" << RESET << " has been created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name)
{
	std::cout << LGREEN << "Bureaucrat " << this->_name << RESET << " has been created" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& source) : _name(source._name), _grade(source._grade)
{
	// *this = source;
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
	return ("Highest possibe grade : 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Lowest possibe grade : 150");
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
