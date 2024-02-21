#ifndef DEF_ROBOTOMYREQUESTFORM
#define DEF_ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
	public:

	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const& source);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const&);

	void execute(Bureaucrat const & executor) const;

	private:

	std::string _target;
};


#endif
