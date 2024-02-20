#ifndef DEF_PRESIDENTIALPARDONFORM
#define DEF_PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const name);
	PresidentialPardonForm(PresidentialPardonForm const& source);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const&);

	void execute(Bureaucrat const & executor) const;

};


#endif
