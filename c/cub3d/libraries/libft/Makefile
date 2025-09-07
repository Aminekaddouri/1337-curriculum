# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 18:15:22 by akaddour          #+#    #+#              #
#    Updated: 2024/08/11 17:11:27 by akaddour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = 	ft_strncmp.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strdup.c \
		ft_substr.c ft_atoi.c ft_split.c ft_strcmp.c ft_split_set.c \
		ft_isspace.c ft_strndup.c ft_strtrim.c ft_strlcpy.c is_whitespace_line.c \
		ft_tablen.c ft_count.c
		
OBJS = $(SRCS:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@ar rcs $(NAME) $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJS)