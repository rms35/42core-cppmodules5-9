#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <ostream>

class	Bureaucrat
{
	private:
		const std::string	name;
		int			grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& n);
		Bureaucrat(int g);
		Bureaucrat(const std::string& n, int g);
		Bureaucrat(const Bureaucrat& b);
		Bureaucrat&	operator=(Bureaucrat const& b);
		~Bureaucrat();

		std::string getName() const;
		int			getGrade() const;

		void		incrementGrade();
		void		decrementGrade();
};

class GradeTooLowException : public std::exception
{
	public:
		~GradeTooLowException() throw() {}
		const char* what() const throw()
		{
			return ("Bureaucrat Grade Too Low");
		}
};

class GradeTooHighException : public std::exception
{
	public:
		~GradeTooHighException() throw() {}
		const char* what() const throw()
		{
			return ("Bureaucrat Grade Too High");
		}
};

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& b);

#endif
