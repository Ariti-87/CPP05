#ifndef DEF_SHRUBBERYCREATIONFORM
#define DEF_SHRUBBERYCREATIONFORM

#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const& source);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const&);

	void execute(Bureaucrat const & executor) const;
};


#endif
