#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), target("Default"), isSigned(false), gradeSign(1),
		gradeExec(1) {}

AForm::AForm(const std::string& n) : name(n), target("Default"), isSigned(false), gradeSign(1),
		gradeExec(1) {}

AForm::AForm(const int g) : name("Default"), target("Default"), isSigned(false), gradeSign(g),
		gradeExec(g)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
}

AForm::AForm(const std::string& n, const std::string& t, const int g) : name(n),
		target(t), isSigned(false), gradeSign(g), gradeExec(g)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
}

AForm::AForm(const std::string& n, const std::string& t, const int gs, const int ge) : name(n),
		target(t), isSigned(false), gradeSign(gs), gradeExec(ge)
{
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& f) : name(f.getName()), target(f.getTarget()), isSigned(f.getIsSigned()),
		gradeSign(f.getGradeSign()), gradeExec(f.getGradeExec()) {}

AForm& AForm::operator=(const AForm& f)
{
	if (this != &f)
		this->isSigned = f.isSigned;
	return (*this);
}

AForm::~AForm() {}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->gradeSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::string AForm::getName() const
{
	return (this->name);
}

std::string AForm::getTarget() const
{
	return (this->target);
}

int	AForm::getGradeSign() const
{
	return (this->gradeSign);
}

int	AForm::getGradeExec() const
{
	return (this->gradeExec);
}

bool	AForm::getIsSigned() const
{
	return (this->isSigned);
}

std::ostream &operator<<(std::ostream& os, AForm const& f)
{
	os << f.getName() << ", form grade sign " << f.getGradeSign()
			<< ", grade exec " << f.getGradeExec()
			<< ", is signed "<< (f.getIsSigned() ? "true." : "false.");
	return (os);
}
