CXX = g++
CXXFLAGS = -Wall -Wextra -Werror  -std=c++98
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp GarbageCollector.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Materia

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
