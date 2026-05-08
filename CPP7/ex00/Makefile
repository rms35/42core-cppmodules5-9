NAME		= swpcmp
CC		= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM		= rm -f

SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
INC		= Swpcmp.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
