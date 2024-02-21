#ifndef DEF_INTERN
#define DEF_INTERN

#include "AForm.hpp"

class Intern
{
	public:

	Intern();
	Intern(Intern const& src);
	~Intern();
	Intern &operator=(Intern const& src);
	AForm *makeForm(std::string const& formName, std::string const& target);

	private:

	AForm *newPresidentialPardon(std::string formName);
	AForm *newRobotomyRequest(std::string formName);
	AForm *newShrubberyCreation(std::string formName);
};


#endif
