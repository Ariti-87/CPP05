#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat tan("Tan", 1);
	Bureaucrat cos("Cos", 150);
	Bureaucrat cos2 = cos;

	std::cout << tan << std::endl;
	std::cout << cos << std::endl;
	std::cout << cos2 << std::endl;

	try
	{
		Bureaucrat sin("Sin", 155);
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat sin("Sin", 0);
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		tan.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		cos.decrementGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}
