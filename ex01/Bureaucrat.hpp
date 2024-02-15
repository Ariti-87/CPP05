#ifndef DEF_BUREAUCRAT
#define DEF_BUREAUCRAT

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define VIOLET "\033[35m"
#define GREEN "\033[32m"
#define LGREEN "\033[92m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define BLACK "\033[30m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

#include <iostream>

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

	private:

	const std::string _name;
	unsigned int _grade;

	class GradeTooHighException : public std::exception
	{
		public:

		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:

		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const& source);

#endif
