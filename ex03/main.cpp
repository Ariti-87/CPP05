#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat cos("Cos", 150);
	Bureaucrat sin("Sin", 1);
	Intern someRandomIntern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm* invalid;

	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	rrf->beSigned(sin);
	rrf->execute(sin);

	std::cout << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Sin");
	std::cout << *ppf << std::endl;
	try
	{
		ppf->beSigned(cos);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "Cos");
	std::cout << *scf << std::endl;
	sin.signForm(*scf);
	sin.executeForm(*scf);

	std::cout << std::endl;
	invalid = someRandomIntern.makeForm("Invalid", "Tan");

	std::cout << std::endl;
	delete rrf;
	delete ppf;
	delete scf;
}

