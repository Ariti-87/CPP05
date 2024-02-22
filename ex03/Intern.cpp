#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Default Intern" << RESET << " has been created" << std::endl;
}

Intern::Intern(Intern const& src)
{
	(void)src;
}

Intern::~Intern()
{
	std::cout << GREEN << "Intern" << RESET << " has been destroyed" << std::endl;
}

Intern & Intern::operator=(Intern const& src)
{
	(void)src;
	return *this;
}

AForm	*Intern::newShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::newRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::newPresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string const& formName, std::string const& target)
{
	AForm*	(Intern::*ptr[3])(std::string) = {&Intern::newShrubberyCreation, &Intern::newRobotomyRequest, &Intern::newPresidentialPardon};
	std::string	form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (form[i] == formName)
		{
			std::cout << GREEN << "Intern" << RESET << " creates " << target << std::endl;
			return ((this->*ptr[i])(target));
		}
	}
	std::cout << RED << "this form doesn't exist : " << formName << RESET << std::endl;
	return (NULL);
}
