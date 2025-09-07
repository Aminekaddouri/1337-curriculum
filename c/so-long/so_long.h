/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:10:25 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 20:44:12 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <mlx.h>
# include "printf/ft_printf.h"

/* -------- KEY VALUES -------- */
# define RIGHT_KEY 2
# define LEFT_KEY 0
# define DOWN_KEY 1
# define UP_KEY 13
# define ESC_KEY 53
# define WIN_CLOSE 17

/* -------- MAP -------- */
# define BUFF_SIZE 256
# define WALL '1'
# define EMPTY '0'
# define COL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'X'
# define SQUARE 38

/* -------- ERRORS -------- */
# define MALLOC_ERROR "so_long: Malloc failed to allocate enough memory."
# define DIR_ERROR "Error no such file or directory.!."
# define EXT_ERROR "Error empty or wrong map file!."
# define MAP_ERROR "cannot collect all collectibles and reach the exit."

/* -------- STRUCTURES -------- */

// all info needed for the map
typedef struct s_map
{
	char		**map;
	int			col;
	int			row;
	int			collectibles;
	int			x;
	int			y;
	int			dx;
	int			dy;
	void		*mlx;
	void		*win;
	void		*img_ptr;
	int			img_size;
	int			fd;
	int			can_exit;
	int			mv_count;
	char		player_direction;
}				t_map;

typedef struct s_fill_data
{
	int	collected;
	int	reached_exit;
	int	**visited;
}		t_fill_data;

/* -------- COLORS -------- */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define LIGHT_YELLOW "\033[1;33m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define END "\033[0m"

void	display_banner(void);
void	inspect_file(char *file);
int		inspect_file_extension(char *file, char *extention);
void	inspect_map(char *file, t_map *map);
void	load_map(char *file, t_map *map);
int		map_size(int fd);
void	free_map(t_map *map);
int		inspect_rectangular_form(t_map *map);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
void	invalid_file_extension(char *file);
void	invalid_map_form(t_map *map);
void	invalid_map_walls(t_map *map);
int		inspect_wall_boundaries(t_map *map);
int		inspect_map_chars(t_map *map);
void	invalid_map_chars(t_map *map);
int		inspect_player_count(t_map *map);
void	invalid_map_player(t_map *map);
int		inspect_collectibles_count(t_map *map);
void	invalid_map_collectibles(t_map *map);
int		inspect_exit_count(t_map *map);
void	invalid_map_exit(t_map *map);
void	count_collectibles(t_map *map);
void	get_player_position(t_map *map);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_new_window(t_map *map);
int		ft_close(t_map *map);
void	ft_free(t_map *map, char *msg);
void	ft_render_images(t_map map);
void	render_images_action(t_map map, int x, int y);
char	*ft_get_image(t_map *map, char c, int can_exit);
int		ft_input(int key, void *param);
void	ft_move_right(t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_down(t_map *map);
void	ft_swap(char *a, char *b);
int		is_map_valid(t_map *map, char *file);
void	flood_fill(t_map *map, int x, int y);
void	get_exit_position(t_map *map);

#endif