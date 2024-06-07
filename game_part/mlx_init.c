/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:17:33 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/07 18:17:28 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	move_hook(mlx_key_data_t key, void *act)
{
	t_game	*map;
	int		*x;
	int		*y;

	map = act;
	y = &map->img.p.img->instances[0].y;
	x = &map->img.p.img->instances[0].x;
	p_move(key, *y, *x, map);
	c_collect_and_finish(map, *x, *y);
}

void	set_textures(t_game *map)
{
	set_img(map, &map->img.ground[0], GROUND);
	set_img(map, &map->img.ground[1], GROUND1);
	set_img(map, &map->img.walls, WALL);
	set_ground_texture(map);
	set_layer_texture(map);
}

void	mlx_window_init(t_game *map)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	map->mlx = mlx_init(IMG_W * map->map.width, IMG_H \
		* map->map.height, "so_long", true);
	if (!map->mlx)
		free_map_data(COLOR_RED"Error! Mlx failure!\n"RESET, map);
}

void	game_init(t_game *map)
{
	init_values(map);
	init_map(map);
	init_layer(map);
	mlx_window_init(map);
	set_textures(map);
}
