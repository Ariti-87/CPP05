#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45)
{
	std::cout << MAGENTA << "Default RobotomyRequestForm" << RESET << " has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Robotomy Request", 72, 45), _target(target)
{
	std::cout << MAGENTA << target << "'s robotomy" << RESET << " has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src.getName(), 72, 45)
{
	std::cout << MAGENTA << "Copy RobotomyRequestForm " << src.getName() << RESET << " has been created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << MAGENTA << "RobotomyRequestForm" << RESET << " has been destroyed" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(!this->getSigned())
		throw MissingSignExeception();
	if(!this->checkExecute(executor))
	{
		std::cout << RED << "For execution : " << RESET;
		throw GradeTooLowException();
	}
	if(this->getSigned() && this->checkExecute(executor))
	{
		srand (time(NULL));
		std::cout << MAGENTA << "Brrrr... Brrrr... Brrrr... " << RESET;
		if(rand() % 2 == 1)
			std::cout << MAGENTA << this->_target << " has been robotomized" << RESET << std::endl;
		else
			std::cout << MAGENTA << "Robotomy has failed" << RESET << std::endl;
	}
}
