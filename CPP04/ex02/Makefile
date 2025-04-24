NAME =  aanimal

SRC =  main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
HDR = AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp

CC_FLAGS = c++ -std=c++98 -Wall -Wextra -Werror -g

OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC_FLAGS) -o $@ $^

%.o: %.cpp $(HDR) Makefile
	$(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re