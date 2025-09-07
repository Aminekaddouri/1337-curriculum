CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = push_swap.c ft_split.c sort.c utils_functions.c quicksort.c ft_substr.c ft_strlen.c \
		reverse.c push.c rotate.c swap.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re