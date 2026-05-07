#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat b("Albert", 150);
	ShrubberyCreationForm s("Garden");
	RobotomyRequestForm r("Monkey");
	PresidentialPardonForm p(b.getName());

	std::cout << "-------- Testing exec without grade --------" << std::endl;
	b.executeForm(s);
	b.executeForm(r);
	b.executeForm(p);
	std::cout << std::endl;

	std::cout << "-------- Testing sign without grade --------" << std::endl;

	b.signForm(s);
	b.signForm(r);
	b.signForm(p);
	std::cout << std::endl;

	for (int i = 0; i < 149; i++)
		b.incrementGrade();

	std::cout << "-------- Testing exec without sign --------" << std::endl;
	b.executeForm(s);
	b.executeForm(r);
	b.executeForm(p);
	std::cout << std::endl;

	std::cout << "-------- Testing sign with grade --------" << std::endl;

	b.signForm(s);
	b.signForm(r);
	b.signForm(p);
	std::cout << std::endl;

	std::cout << "-------- Testing exec with grade and sign --------" <<
		std::endl;
	b.executeForm(s);
	b.executeForm(r);
	b.executeForm(p);
}