/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:54:23 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:26 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <sys/errno.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <ctype.h>
# include <mlx.h>
# include "get_next_line.h"
# include "../libraries/libft/libft.h"

/* -------- COLORS -------- */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define LIGHT_YELLOW "\033[1;33m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define END "\033[0m"

/* -------- TEXTURES -------- */
# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"
# define EQUAL 0

/* -------- EVENTS -------- */
# define ON_KEYDOWN 2
# define ON_MOUSEMOVE 6
# define ON_DESTROY 17

/* -------- KEYS -------- */
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307
# define SPACE 32

/* -------- GAME SETTINGS -------- */
# define WALL_SIZE 64
# define P_SPEED 8
# define P_ROTATION_SPEED 2
# define P_SIZE 20
# define FOV_ANGLE 1.0472 //60 in rad
# define COLUMN_W 1
# define MINI_MAP_SCALE 0.25
# define MINI_MAP_W 6
# define MINI_MAP_H 4
# define SENSITIVITY 0.5
# define SCREEN_W 1000
# define SCREEN_H 600

typedef struct s_cast_ray
{
	double	x_step;
	double	y_step;
	double	x_intercept;
	double	y_intercept;
	double	wall_hit_x;
	double	wall_hit_y;
	double	next_touch_x;
	double	next_touch_y;
	double	distance;
	t_bool	is_door;
}	t_cast_ray;

typedef struct s_texture
{
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_render
{
	int			distance_from_top;
	t_texture	texture;
	int			texur_x;
	int			texur_y;
	int			color;
}	t_render;

typedef struct s_rec
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_rec;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_ray
{
	int		index;
	double	ray_angle;
	double	distance;
	int		wall_hit_x;
	int		wall_hit_y;
	int		is_facing_down;
	int		is_facing_up;
	int		is_facing_right;
	int		is_facing_left;
	int		is_hit_vert;
	t_bool	is_door;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	angle;
}	t_player;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char		*filename;
	char		**map_content;
	char		**map_only;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			height;
	int			width;
	int			x[2];
	int			y[2];
	t_color		floor_color;
	t_color		ceiling_color;
}	t_map;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	int			screen_h;
	int			screen_w;
	int			prev_mouse_x;
	int			prev_mouse_y;
	int			nbr_rays;
	double		wall_h;
	t_map		map;
	t_data		img;
	t_player	player;
	t_texture	textures[4];
	t_texture	door[8];
	int			current_frame;
	int			animation_timer;
	int			frame_delay;
	int			number_of_fire_frames;
}	t_cub;

int				key_press(int keycode, t_cub *cub);
void			draw_player(t_cub *cube, int x, int y);
void			cast_all_rays(t_cub *cub);
void			draw_mini_map(t_cub cub);
void			cast_ray(t_cub cub, t_ray *ray);
t_bool			cast_horiz_ray(t_cub cub, t_ray *ray, t_cast_ray *horiz);
t_bool			cast_vert_ray(t_cub cub, t_ray *ray, t_cast_ray *vert);
void			my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int				mouse_move(int x, int y, t_cub *cub);
void			key_press_arrow_right(t_cub *cub);
void			key_press_arrow_left(t_cub *cub);
int				close_window(t_cub *cub);
int				is_wall(int x, int y, t_cub *cub);
double			get_distance(double x0, double y0, double x1, double y1);
void			draw_rec(t_cub *cub, t_rec rec);
unsigned int	create_color(int alpha, int red, int green, int blue);
void			render_wall(t_cub *cub, t_ray ray, int i);
t_texture		load_xpm(t_cub *cub, char *path);
void			ft_free_map_content(char **map_content);
void			open_door(t_cub *cub);

// parsing
void			ft_puterror(t_cub *cub, char *msg);
void			parse_map(t_cub *cub);
void			inspect_file_content(t_cub *cub, char **content);
void			check_empty_file(t_cub *cub, char **content);
void			check_cub_texture(t_cub *cub, char **content);
void			check_cub_colors(t_cub *cub, char **content);
void			load_map(t_cub *cub);
void			get_map_textures(t_cub *cub);
void			free_split(char **split);
void			get_map_colors(t_cub *cub);
int				parse_color_value(t_cub *cub, char *str,
					char **colors, char *new_line);
void			initialize_map(t_cub *cub);
int				get_map_len(char **content);
int				check_new_line(char *str);
void			get_player_position(t_cub *cub);
int				count_nbr_of_lines(t_cub *cub, char *filename);
t_bool			is_whitespace_line(char *line);
t_bool			is_valid_map_char(char c);
t_bool			is_valid_map_line(const char *line);
void			validate_map(t_cub *cub);
void			check_map_boundaries(t_cub *cub);
void			free_split(char **split);

#endif