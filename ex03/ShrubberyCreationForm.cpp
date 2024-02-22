#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << YELLOW << "Default ShrubberyCreationForm" << RESET << " has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << YELLOW << target << "'s shrubbery" << RESET << " has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) : AForm(src.getName(), 145, 137)
{
	std::cout << YELLOW << "Copy ShrubberyCreationForm " << src.getName() << RESET << " has been created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << YELLOW << "ShrubberyCreationForm" << RESET << " has been destroyed" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(!this->getSigned())
		throw MissingSignExeception();
	if(!this->checkExecute(executor))
	{
		std::cout << RED << "For execution : " << RESET;
		throw GradeTooLowException();
	}
	if(this->getSigned() && this->checkExecute(executor))
	{
		std::string filename = _target + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (!file)
		{
			std::cerr << "Error opening file : " << filename << std::endl;
			return ;
		}
		file << "                                                         .\n"
                 "                                              .         ;\n"
                 "                 .              .              ;%     ;;\n"
                 "                   ,           ,                :;%  %;\n"
                 "                    :         ;                   :;%;'     .,\n"
                 "           ,.        %;     %;            ;        %;'    ,;\n"
                 "             ;       ;%;  %%;        ,     %;    ;%;    ,'%\n"
                 "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
                 "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
                 "                `%;.     ;%;     %;'         `;%%;.%;'\n"
                 "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
                 "                    `:%;.  :;bd%;          %;@%;'\n"
                 "                      `@%:.  :;%.         ;@@%;'\n"
                 "                        `@%.  `;@%.      ;@@%;\n"
                 "                          `@%%. `@%%    ;@@%;\n"
                 "                            ;@%. :@%%  %@@%;\n"
                 "                              %@bd%%%bd%%:;\n"
                 "                                #@%%%%%:;;\n"
                 "                                %@@%%%::;\n"
                 "                                %@@@%(o);  . '\n"
                 "                                %@@@o%;:(.,'\n"
                 "                            `.. %@@@o%::;'\n"
                 "                               `)@@@o%::;'\n"
                 "                                %@@(o)::;'\n"
                 "                               .%@@@@%::;'\n"
                 "                               ;%@@@@%::;. '\n"
                 "                              ;%@@@@%%:;;;. '\n"
                 "                         ...;%@@@@@%%:;;;;,..";

		file.close();
		std::cout << "File " << YELLOW << filename << RESET << " has been created successfully." << std::endl;
	}
}
