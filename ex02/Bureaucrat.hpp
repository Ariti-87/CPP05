#ifndef DEF_BUREAUCRAT
#define DEF_BUREAUCRAT

#include "AForm.hpp"

class Bureaucrat
{
	public:

	Bureaucrat();
	Bureaucrat(std::string const name, unsigned int grade);
	Bureaucrat(Bureaucrat const& source);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const& source);

	std::string getName(void) const;
	unsigned int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm & f) const;

	private:

	const std::string _name;
	unsigned int _grade;

	class GradeTooHighException : public std::exception
	{
		public:

		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:

		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const& source);

#endif
