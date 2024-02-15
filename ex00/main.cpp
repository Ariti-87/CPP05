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
		tan.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		cos.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}
