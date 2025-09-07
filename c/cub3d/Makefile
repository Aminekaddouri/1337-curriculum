NAME = cub3d
BONUS = cub3d_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address 

LIBFT = libft.a
LIBFT_PATH = libraries/libft
MLX = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm

GET_NEXT_LINE = libraries/get_next_line/get_next_line.c \
                libraries/get_next_line/get_next_line_utils.c

PARSER = srcs/parser/get_player_position.c \
         srcs/parser/get_map_colors.c \
         srcs/parser/initialize_map.c \
         srcs/parser/inspect_file_content.c \
         srcs/parser/parse_map.c \
         srcs/parser/parser_utils.c \
         srcs/parser/validate_map.c \
         srcs/parser/check_map_boundaries.c \
         srcs/parser/get_map_textures.c

PARSER_BONUS = srcs_bonus/parser/get_player_position_bonus.c \
         srcs_bonus/parser/get_map_colors_bonus.c \
         srcs_bonus/parser/initialize_map_bonus.c \
         srcs_bonus/parser/inspect_file_content_bonus.c \
         srcs_bonus/parser/parse_map_bonus.c \
         srcs_bonus/parser/parser_utils_bonus.c \
         srcs_bonus/parser/validate_map_bonus.c \
         srcs_bonus/parser/check_map_boundaries_bonus.c \
         srcs_bonus/parser/get_map_textures_bonus.c

SRCS = srcs/main.c \
       srcs/move_player/key_press.c \
       srcs/move_player/move_player_utils.c \
       srcs/casting/rendering_utils.c \
       srcs/casting/render.c \
       srcs/casting/cast_horiz_ray.c \
       srcs/casting/cast_vert_ray.c \
       srcs/casting/cast_all_rays.c \
       srcs/utils.c \
       $(GET_NEXT_LINE) \
       $(PARSER)

SRCS_BONUS = srcs_bonus/main_bonus.c \
       srcs_bonus/mini_map/mini_map_bonus.c \
       srcs_bonus/mini_map/draw_player_bonus.c \
       srcs_bonus/move_player/key_press_bonus.c \
       srcs_bonus/move_player/mouse_move_bonus.c \
       srcs_bonus/move_player/move_player_utils_bonus.c \
       srcs_bonus/casting/rendering_utils_bonus.c \
       srcs_bonus/casting/render_bonus.c \
       srcs_bonus/casting/cast_horiz_ray_bonus.c \
       srcs_bonus/casting/cast_vert_ray_bonus.c \
       srcs_bonus/casting/cast_all_rays_bonus.c \
       srcs_bonus/utils_bonus.c \
       $(GET_NEXT_LINE) \
       $(PARSER_BONUS)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/$(LIBFT) $(MLX) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS)
	@make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_PATH)/$(LIBFT) $(MLX) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -o $@ -c $<

clean:
	@make -C $(LIBFT_PATH) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean bonus re
.SECONDARY: $(OBJS) $(OBJS_BONUS)

