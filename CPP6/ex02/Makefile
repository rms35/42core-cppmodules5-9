NAME		= typeinfo
CC		= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address,leak
RM		= rm -f

SRCS		= main.cpp Base.cpp
OBJS		= $(SRCS:.cpp=.o)
INC		= Base.hpp A.hpp B.hpp C.hpp

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
