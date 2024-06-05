/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:17:33 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/05 23:04:32 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

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
	map->mlx = mlx_init(IMG_W * map->map.width, IMG_H * map->map.height, "so_long", true);
	if (!map->mlx)
		free_map_data(COLOR_RED"Error! Mlx failure!\n"RESET, map);
}
