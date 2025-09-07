NAME = so_long
BNAME = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRINTF = libftprintf.a
SRC = so_long.c inspect_file.c inspect_file_extension.c inspect_map.c inspect_rectangular_form.c ft_strlen.c load_map.c \
	  get_next_line.c inspect_wall_boundaries.c inspect_map_chars.c inspect_player_count.c inspect_collectibles_count.c \
	  inspect_exit_count.c free_map.c count_collectibles.c display_banner.c get_player_position.c \
	  ft_strcmp.c ft_new_window.c ft_free.c rendering.c player_moves.c moves.c is_map_valid.c get_exit_position.c
SRCB = bonus/so_long_bonus.c bonus/inspect_map_chars_bonus.c bonus/inspect_collectibles_count_bonus.c bonus/inspect_file_bonus.c bonus/inspect_exit_count_bonus.c \
	   bonus/inspect_file_extension_bonus.c bonus/inspect_map_bonus.c bonus/inspect_player_count_bonus.c bonus/inspect_rectangular_form_bonus.c bonus/inspect_wall_boundaries_bonus.c \
	   bonus/count_collectibles_bonus.c bonus/display_banner_bonus.c bonus/enemy_moves_bonus.c bonus/free_map_bonus.c \
	   bonus/ft_free_bonus.c bonus/ft_get_image_bonus.c bonus/ft_itoa_bonus.c bonus/ft_new_window_bonus.c bonus/ft_strcmp_bonus.c bonus/ft_strjoin_bonus.c \
	   bonus/ft_strlen_bonus.c bonus/get_enemy_position_bonus.c bonus/get_exit_position_bonus.c bonus/load_map_bonus.c bonus/get_next_line_bonus.c \
	   bonus/get_player_position_bonus.c bonus/is_map_valid_bonus.c bonus/load_enemy_frames_bonus.c bonus/load_player_frames_bonus.c bonus/moves_bonus.c \
	   bonus/player_moves_bonus.c bonus/rendering_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@make -C printf
	$(CC) $(OBJ) printf/$(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(OBJB)
	@make -C bonus/printf
	$(CC) $(OBJB) bonus/printf/$(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

clean:
	@make clean -C printf
	rm -f $(OBJ) $(OBJB)

fclean: clean
	@make fclean -C printf
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: clean fclean all re