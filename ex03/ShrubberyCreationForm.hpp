#ifndef DEF_SHRUBBERYCREATIONFORM
#define DEF_SHRUBBERYCREATIONFORM

#include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
	public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const& source);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const&);

	void execute(Bureaucrat const & executor) const;

	private:

	std::string _target;
};


#endif
