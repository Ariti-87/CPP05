#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat cos("Cos", 150);
	Bureaucrat sin("Sin", 1);
	Bureaucrat pre("Pre", 20);
	PresidentialPardonForm pardon("Tan");

	Bureaucrat robot("Robot", 50);
	RobotomyRequestForm tomy("RobotTan");

	Bureaucrat shru("Shru", 140);
	ShrubberyCreationForm tree("Tree");
	std::cout << std::endl;


	try
	{
		pardon.execute(cos);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try
	{
		pardon.beSigned(sin);
		pardon.execute(sin);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try
	{
		pardon.beSigned(pre);
		pardon.execute(pre);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	try
	{
		tomy.beSigned(robot);
		tomy.execute(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try
	{
		tomy.beSigned(sin);
		tomy.execute(sin);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	try
	{
		tree.beSigned(sin);
		tree.execute(sin);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	try
	{
		tree.beSigned(shru);
		tree.execute(shru);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;


	sin.executeForm(pardon);
	cos.executeForm(pardon);
	std::cout << std::endl;
	sin.executeForm(tomy);
	cos.executeForm(tomy);
	std::cout << std::endl;
	sin.executeForm(tree);
	cos.executeForm(tree);
	std::cout << std::endl;
	return 0;
}

