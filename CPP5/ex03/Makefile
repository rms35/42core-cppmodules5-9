NAME		= intern
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address,leak
RM			= rm -f

SRCS		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS		= $(SRCS:.cpp=.o)
INC			= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
	RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *_shrubbery

re: fclean all

.PHONY: all clean fclean re
