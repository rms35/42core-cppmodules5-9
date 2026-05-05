#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Form a(-2);
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form b(200);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Form c("Excel", 60);
	std::cout<< c << std::endl;
	Form d("Doc", 75);
	std::cout<< d << std::endl;
	Bureaucrat	b("Albert", 66);
	b.signForm(c);
	b.signForm(d);
	std::cout<< c << std::endl;
	std::cout<< d << std::endl;
	std::cout<< b << std::endl;
}