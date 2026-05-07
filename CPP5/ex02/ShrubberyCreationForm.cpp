#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() :
		AForm("ShrubberyCreationForm", "Default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t) :
		AForm("ShrubberyCreationForm", t, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) :
		AForm(s) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=
		(const ShrubberyCreationForm& s)
{
	(void)s;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSigned();
	printTree(this->getTarget());
}

void	ShrubberyCreationForm::printTree(const std::string &target)
{
	std::ofstream	file((target + "_shrubbery").c_str());

	if (!file.is_open())
		throw std::exception();
	const int trees = 3;
	for (int ind = 0; ind < trees; ind++)
	{
		const int max_width = 10;
		int	width = 4;
		int triangle = ind;
		for (int j = 0; j < max_width; j++)
		{
			const int height = 20;
			for (int i = triangle; i < height - triangle; i++)
			{
				const int	start = width / 2 - i + 1;
				if (start < 0)
					break ;
				for (int in = 0; in < (max_width - triangle); in ++)
					file << " ";
				for (int in = 0; in < start; in++)
					file << " ";
				for (int in = -i; in < i; in++)
				{
					if (in < 0)
						file << "/";
					else
						file << "\\";
				}
				file << "\n";
			}
			triangle++;
			width += 2;
		}
		for (int i = ind; i < 3; i++)
		{
			for (int in = 0; in < max_width - ind + 1; in ++)
				file << " ";
			file << "|  |\n";
		}
		file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
	}
	file.close();
}
