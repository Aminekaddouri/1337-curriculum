/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:53:48 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/26 16:26:31 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	draw_cub3d(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img.img);
	cub->img.img = mlx_new_image(cub->mlx, SCREEN_W, SCREEN_H);
	cub->img.addr = mlx_get_data_addr(cub->img.img,
			&cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	mlx_clear_window(cub->mlx, cub->win);
	cast_all_rays(cub);
	draw_mini_map(*cub);
	if (cub->animation_timer >= cub->frame_delay)
	{
		cub->current_frame
			= (cub->current_frame + 1) % cub->number_of_fire_frames;
		cub->animation_timer = 0;
	}
	else
		cub->animation_timer++;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return (1);
}

void	load_textures(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
		cub->textures[i].img = NULL;
	i = -1;
	while (++i < 8)
		cub->door[i].img = NULL;
	cub->textures[0] = load_xpm(cub, cub->map.north_texture);
	cub->textures[1] = load_xpm(cub, cub->map.south_texture);
	cub->textures[2] = load_xpm(cub, cub->map.west_texture);
	cub->textures[3] = load_xpm(cub, cub->map.east_texture);
	cub->door[0] = load_xpm(cub, "./textures/door_0.xpm");
	cub->door[1] = load_xpm(cub, "./textures/door_1.xpm");
	cub->door[2] = load_xpm(cub, "./textures/door_2.xpm");
	cub->door[3] = load_xpm(cub, "./textures/door_3.xpm");
	cub->door[4] = load_xpm(cub, "./textures/door_4.xpm");
	cub->door[5] = load_xpm(cub, "./textures/door_5.xpm");
	cub->door[6] = load_xpm(cub, "./textures/door_6.xpm");
	cub->door[7] = load_xpm(cub, "./textures/door_7.xpm");
}

// 0 : N | 1 : S | 2 : W | 3 : E
void	init_vars(t_cub *cub)
{
	t_data	img;

	cub->current_frame = 0;
	cub->animation_timer = 0;
	cub->frame_delay = 10;
	cub->number_of_fire_frames = 8;
	cub->player.dx = cos(cub->player.angle) * 5;
	cub->player.dy = sin(cub->player.angle) * 5;
	cub->screen_w = cub->map.width * WALL_SIZE;
	cub->screen_h = cub->map.height * WALL_SIZE;
	cub->nbr_rays = SCREEN_W / COLUMN_W;
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, SCREEN_W, SCREEN_H, "cub3d");
	img.img = mlx_new_image(cub->mlx, SCREEN_W, SCREEN_H);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	cub->img = img;
	cub->prev_mouse_x = 1980 / 2;
	cub->prev_mouse_y = SCREEN_H / 2;
	load_textures(cub);
}

void	init_parsing_vars(t_cub *cub)
{
	cub->map.map_content = NULL;
	cub->map.map_only = NULL;
	cub->map.north_texture = NULL;
	cub->map.south_texture = NULL;
	cub->map.west_texture = NULL;
	cub->map.east_texture = NULL;
	cub->map.filename = NULL;
	cub->map.ceiling_color.r = 0;
	cub->map.ceiling_color.g = 0;
	cub->map.ceiling_color.b = 0;
	cub->map.floor_color.r = 0;
	cub->map.floor_color.g = 0;
	cub->map.floor_color.b = 0;
	cub->map.width = 0;
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	init_parsing_vars(&cub);
	if (argc != 2)
		ft_puterror(&cub, "You forgot the map file\n");
	cub.map.filename = ft_strdup(argv[1]);
	parse_map(&cub);
	if (argc > 1)
	{
		init_vars(&cub);
		draw_cub3d(&cub);
		mlx_hook(cub.win, ON_KEYDOWN, 1, key_press, &cub);
		mlx_hook(cub.win, ON_MOUSEMOVE, 1L << 6, mouse_move, &cub);
		mlx_hook(cub.win, ON_DESTROY, 0, close_window, &cub);
		mlx_loop_hook(cub.mlx, (void *)draw_cub3d, &cub);
		mlx_loop(cub.mlx);
	}
	return (0);
}
