#ifndef DEF_AFORM
#define DEF_AFORM

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
#include <fstream>
#include <cstdlib>

class Bureaucrat;

class AForm
{
	public:

	AForm();
	AForm(std::string const name, unsigned int gradeSign, unsigned int gradeExec);
	AForm(AForm const& src);
	virtual ~AForm();
	AForm &operator=(AForm const& src);

	std::string getName(void) const;
	bool getSigned(void) const;
	unsigned int getGradeExec(void) const;
	unsigned int getGradeSign(void) const;
	void beSigned(Bureaucrat const& Bur);

	virtual void execute(Bureaucrat const & executor) const = 0;
	bool checkExecute(Bureaucrat const& executor) const;

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

	class MissingSignExeception : public std::exception
	{
		public:

		virtual const char *what() const throw();
	};

	private:

	const std::string _name;
	bool _signed;
	const unsigned int _gradeSign;
	const unsigned int _gradeExec;
};

std::ostream &operator<<(std::ostream &o, AForm const& source);

#endif
