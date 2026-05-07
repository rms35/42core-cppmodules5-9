
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
		AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& t) :
		AForm("RobotomyRequestForm", 72, 45), target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) :
		AForm(s), target(s.target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& s)
{
	(void)s;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	static int count;

	if (count == 0)
	{
		std::srand(time(NULL));
		count++;
	}
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSigned();
	for (int i = 0; i < 5; i++)
		std::cout << "Drill!! Drill!!" << std::endl;
	if (std::rand() % 2)
		std::cout << this->target << " robotomy failed" << std::endl;
	else
		std::cout << this->target << " has been robotomized successfully"
				<< std::endl;
}