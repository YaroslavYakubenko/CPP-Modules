NAME =  zombie

SRC =  main.cpp zombieHorde.cpp Zombie.cpp
HDR = Zombie.hpp

CC_FLAGS = c++ -std=c++98 -Wall -Wextra -Werror -O3 -g

OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	@$(CC_FLAGS) -o $@ $^

%.o: %.cpp $(HDR) Makefile
	@$(CC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re