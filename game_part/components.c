/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:27:14 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/06 18:43:49 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

static void	player_pos(t_multi *data, t_position *pos)
{
	data->x = pos->x;
	data->y = pos->y;
	ft_printf(COLOR_GREEN "P-position: from [%d] to [%d]\n" RESET, data->x,
			data->y);
}

void	player(t_game *map, int x, int y)
{
	set_img(map, &map->img.P.img, PLAYER);
	player_pos(&map->img.P, &map->pos);
	map->map.map[y][x] = '0';
	mlx_image_to_window(map->mlx, map->img.P.img, x * IMG_W, y * IMG_H);
}

void	collectable(t_game *map, int x, int y, int *count)
{
	set_img(map, &map->img.C[*count].img, COLLECTABLE);
	map->img.C[*count].x = x;
	map->img.C[*count].y = y;
	mlx_image_to_window(map->mlx, map->img.C[*count].img, x * IMG_W, y * IMG_H);
	(*count)++;
}

void	exit_exit(t_game *map, int x, int y)
{
	set_img(map, &map->img.E[0].img, EXIT_START);
	map->img.E[0].x = x;
	map->img.E[0].y = y;
	set_img(map, &map->img.E[1].img, EXIT_FINAL);
	map->img.E[1].x = x;
	map->img.E[1].y = y;
	mlx_image_to_window(map->mlx, map->img.E[0].img, x * IMG_W, y * IMG_H);
}
int check_and_update_map(t_game *map, int x, int y)
{
	if (map->map.map && map->map.map[y / IMG_H][x / IMG_W] == 'C')
	{
		map->map.map[y / IMG_H][x / IMG_W] = '0';
		return 1;
	}
	return 0;
}

void process_collectible(t_game *map, int x, int y)
{
	int c_raw;
	int c_column;
	int i;

	i = 0;
	while (i < map->map.C && map->count < map->map.C)
	{
		if (map->count >= map->map.C)
			break ;
		c_raw = map->img.C[i].x;
		c_column = map->img.C[i].y;
		if (c_raw == x / IMG_W && c_column == y / IMG_H)
		{
			mlx_delete_image(map->mlx, map->img.C[i].img);
			map->count++;
		}
		i++;
	}
}
