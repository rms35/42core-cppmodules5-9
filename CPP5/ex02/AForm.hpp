
#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	name;
		const std::string	target;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;

	public:
		AForm();
		AForm(const std::string &n);
		AForm(int g);
		AForm(const std::string &n, const std::string &t, int g);
		AForm(const std::string &n, const std::string &t, int gs, int ge);
		AForm(const AForm& f);
		AForm&	operator=(const AForm& f);

		virtual ~AForm();

		std::string getName() const;
		std::string getTarget() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		bool		getIsSigned() const;

		void		beSigned(const Bureaucrat& b);

		virtual void	execute(Bureaucrat const& executor) const = 0;

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

		class	FormNotSigned : public std::exception
		{
			public:
				const char*	what() const throw()
			{
				return ("Form Not Signed");
			}
		};
};

std::ostream&	operator<<(std::ostream& os, AForm const& f);

#endif // AFORM_HPP
