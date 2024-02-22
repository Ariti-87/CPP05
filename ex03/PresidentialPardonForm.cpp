#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5)
{
	std::cout << CYAN << "Default PresidentialPardonForm" << RESET << " has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << CYAN << target << "'s pardon" << RESET << " has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src.getName(), 25, 5)
{
	std::cout << CYAN << "Copy PresidentialPardonForm " << src.getName() << RESET << " has been created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CYAN << "PresidentialPardonForm" << RESET << " has been destroyed" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(!this->getSigned())
		throw MissingSignExeception();
	if(!this->checkExecute(executor))
	{
		std::cout << RED << "For execution : " << RESET;
		throw GradeTooLowException();
	}
	std::cout << CYAN << this->_target << " has been pardoned by Zaphod BeeBlerox" << std::endl;
}
