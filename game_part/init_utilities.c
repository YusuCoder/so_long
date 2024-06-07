/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:55:04 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/07 17:52:16 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	no_c_left(t_game *map, int x, int y)
{
	int	tile_x;
	int	tile_y;

	if (map->count == map->map.c && map->finish_game != 1)
	{
		mlx_delete_image(map->mlx, map->img.e[0].img);
		mlx_image_to_window(map->mlx, map->img.e[1].img, map->img.e[0].x
			* IMG_W, map->img.e[0].y * IMG_H);
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

void	process_collectible(t_game *map, int x, int y)
{
	int	c_raw;
	int	c_column;
	int	i;

	i = 0;
	while (i < map->map.c && map->count < map->map.c)
	{
		if (map->count >= map->map.c)
			break ;
		c_raw = map->img.c[i].x;
		c_column = map->img.c[i].y;
		if (c_raw == x / IMG_W && c_column == y / IMG_H)
		{
			mlx_delete_image(map->mlx, map->img.c[i].img);
			map->count++;
		}
		i++;
	}
}
