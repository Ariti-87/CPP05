#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	try
	{
		Form f1("f1", 0, 5);
		std::cout << f1 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f1("f1", 5, 155);
		std::cout << f1 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat cos("Cos", 1);
	std::cout << cos << std::endl;
	Bureaucrat sin("Sin", 150);
	std::cout << sin << std::endl;

	Form fos("fos", 1, 1);
	std::cout << fos << std::endl;


	try
	{
		sin.signForm(fos);
		std::cout << fos << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		cos.signForm(fos);
		std::cout << fos << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form fin("fin", 1, 1);
	try
	{
		fin.beSigned(sin);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		fin.beSigned(cos);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

