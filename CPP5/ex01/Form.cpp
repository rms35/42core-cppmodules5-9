//
// Created by rafael on 5/4/26.
//

#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeSign(1),
				gradeExec(1) {}

Form::Form(const std::string& n) : name(n), isSigned(false), gradeSign(1),
		gradeExec(1) {}

Form::Form(const int g) : name("Default"), isSigned(false), gradeSign(g),
		gradeExec(g)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
}

Form::Form(const std::string& n, const int g) : name(n),
isSigned(false), gradeSign(g), gradeExec(g)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
}

Form::Form(const std::string& n, const int gs, const int ge) : name(n),
		isSigned(false), gradeSign(gs), gradeExec(ge)
{
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& f) : name(f.getName()), isSigned(f.getIsSigned()),
		gradeSign(f.getGradeSign()), gradeExec(f.getGradeExec()) {}

Form& Form::operator=(const Form& f)
{
	if (this != &f)
		this->isSigned = f.isSigned;
	return (*this);
}

Form::~Form() {}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->gradeSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::string Form::getName() const
{
	return (this->name);
}

int	Form::getGradeSign() const
{
	return (this->gradeSign);
}

int	Form::getGradeExec() const
{
	return (this->gradeExec);
}

bool	Form::getIsSigned() const
{
	return (this->isSigned);
}

std::ostream &operator<<(std::ostream& os, Form const& f)
{
	os << f.getName() << ", form grade sign " << f.getGradeSign()
			<< ", grade exec " << f.getGradeExec()
			<< ", is signed "<< (f.getIsSigned() ? "true." : "false.");
	return (os);
}
