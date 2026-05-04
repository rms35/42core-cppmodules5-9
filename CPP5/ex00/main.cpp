#include <iostream>
#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a(-2);
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b(200);
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat c("Albert", 75);
	for (int i = 0; i < 200; i++)
	{
		try
		{
			c.decrementGrade();
		}
		catch (GradeTooLowException& e)
		{
			std::cout << c.getName() << " grade = " << c.getGrade() <<
				std::endl;
			std::cerr << e.what() << std::endl;
			break ;
		}
	}
	for (int i = 0; i < 200; i++)
	{
		try
		{
			c.incrementGrade();
		}
		catch (std::exception & e)
		{
			std::cout << c.getName() << " grade = " << c.getGrade() <<
				std::endl;
			std::cerr << e.what() << std::endl;
			break ;
		}
	}
	Bureaucrat d("María", 75);
	for (int i = 0; i < 10; i++)
	{
		try
		{
			d.incrementGrade();
			std::cout << "Grade = " << d.getGrade() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout<< d << std::endl;
}