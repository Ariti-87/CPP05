#ifndef DEF_PRESIDENTIALPARDONFORM
#define DEF_PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
	public :

	PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const& src);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const& src);

	void execute(Bureaucrat const & executor) const;

	private:

	std::string _target;
};


#endif
