#ifndef DEF_ROBOTOMYREQUESTFORM
#define DEF_ROBOTOMYREQUESTFORM

#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const& source);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const&);

	void execute(Bureaucrat const & executor) const;

};


#endif
