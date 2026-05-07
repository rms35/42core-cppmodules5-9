#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeSign(1),
		gradeExec(1) {}

AForm::AForm(const std::string& n) : name(n), isSigned(false), gradeSign(1),
		gradeExec(1) {}

AForm::AForm(const int g) : name("Default"), isSigned(false), gradeSign(g),
		gradeExec(g)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
}

AForm::AForm(const std::string& n, const int g) : name(n),
		isSigned(false), gradeSign(g), gradeExec(g)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
}

AForm::AForm(const std::string& n, const int gs, const int ge) : name(n),
		isSigned(false), gradeSign(gs), gradeExec(ge)
{
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& f) : name(f.getName()), isSigned(f.getIsSigned()),
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
