
#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class	Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;

	public:
		Form();
		Form(const std::string &n);
		Form(int g);
		Form(const std::string &n, int g);
		Form(const std::string &n, int gs, int ge);
		Form(const Form& f);
		Form&	operator=(const Form& f);
		~Form() = default;;

		std::string getName() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		bool		getIsSigned() const;

		void		beSigned(const Bureaucrat& b);

		class	GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw()
				{
					return ("Grade Too High");
				}
		};

		class	GradeTooLowException : public std::exception
		{
		public:
			const char*	what() const throw()
			{
				return ("Grade Too Low");
			}
		};
};

std::ostream &operator<<(std::ostream& os, Form const& f);

#endif //EX01_FORM_HPP
