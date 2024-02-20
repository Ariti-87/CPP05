#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5)
{
	std::cout << CYAN << "Default PresidentialPardonForm" << RESET << " has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const name) : AForm(name, 25, 5)
{
	std::cout << CYAN << name << RESET << " has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& source) : AForm(source.getName(), 25, 5)
{
	std::cout << CYAN << "Copy PresidentialPardonForm " << source.getName() << RESET << " has been created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CYAN << "Default PresidentialPardonForm" << RESET << " has been destroyed" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const&)
{
	return (*this);
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{}
