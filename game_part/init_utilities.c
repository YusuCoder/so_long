/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:55:04 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/06 19:21:34 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	no_c_left(t_game *map, int x, int y)
{
	int	tile_x;
	int	tile_y;

	if (map->count == map->map.C && map->finish_game != 1)
	{
		mlx_delete_image(map->mlx, map->img.E[0].img);
		mlx_image_to_window(map->mlx, map->img.E[1].img, map->img.E[0].x
				* IMG_W, map->img.E[0].y * IMG_H);
		map->finish_game = 1;
		map->level++;
	}
	if (map->finish_game == 1)
	{
		tile_x = x / IMG_W;
		tile_y = y / IMG_H;
		if (map->map.map[tile_y][tile_x] == 'E')
		{
			mlx_close_window(map->mlx);
		}
	}
}

void	c_collect_and_finish(t_game *map, int x, int y)
{
	if (check_and_update_map(map, x, y))
	{
		process_collectible(map, x, y);
	}
	no_c_left(map, x, y);
}

void	map_length(t_game *map, char *line, int i)
{
	int	len;

	len = ft_arrlen(line);
	if (i == 0)
		map->map.width = len;
	if (len >= WIDTH / IMG_W)
		free_map_data("Error! File is too large!\n", map);
	return ;
}

void	allocate_mem(t_game *game)
{
	if (!game->map.map)
	{
		game->map.map = (char **)malloc(sizeof(char *) * 270);
		if (!game->map.map)
		{
			ft_printf("Error!\n");
			exit(EXIT_FAILURE);
		}
		ft_memset(game->map.map, 0, 270);
	}
}

void	game_init(t_game *map)
{
	init_values(map);
	init_map(map);
	init_layer(map);
	mlx_window_init(map);
	set_textures(map);
}
