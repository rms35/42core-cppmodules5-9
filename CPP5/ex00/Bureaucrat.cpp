#include "Bureaucrat.hpp"

#include <iostream>
#include <stdexcept>

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {}
Bureaucrat::Bureaucrat(const std::string& n) : name(n), grade(0) {}
Bureaucrat::Bureaucrat(const int g) : grade(g)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string& n, const int g) : name(n), grade(g)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.getName()),
		grade(b.getGrade()) {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& b)
{
	this->grade = b.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}



std::string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<(std::ostream& os, Bureaucrat const& b)
{
	std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << "." <<
			std::endl;
	return (os);
}
