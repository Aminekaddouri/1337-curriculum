CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = mutantstack

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean: clean	
		rm -rf $(NAME)

re: fclean all

.PHONEY: all clean fclean re