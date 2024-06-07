/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:27:14 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/07 17:49:37 by ryusupov         ###   ########.fr       */
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
	set_img(map, &map->img.p.img, PLAYER);
	player_pos(&map->img.p, &map->pos);
	map->map.map[y][x] = '0';
	mlx_image_to_window(map->mlx, map->img.p.img, x * IMG_W, y * IMG_H);
}

void	collectable(t_game *map, int x, int y, int *count)
{
	set_img(map, &map->img.c[*count].img, COLLECTABLE);
	map->img.c[*count].x = x;
	map->img.c[*count].y = y;
	mlx_image_to_window(map->mlx, map->img.c[*count].img, x * IMG_W, y * IMG_H);
	(*count)++;
}

void	exit_exit(t_game *map, int x, int y)
{
	set_img(map, &map->img.e[0].img, EXIT_START);
	map->img.e[0].x = x;
	map->img.e[0].y = y;
	set_img(map, &map->img.e[1].img, EXIT_FINAL);
	map->img.e[1].x = x;
	map->img.e[1].y = y;
	mlx_image_to_window(map->mlx, map->img.e[0].img, x * IMG_W, y * IMG_H);
}

int	check_and_update_map(t_game *map, int x, int y)
{
	if (map->map.map && map->map.map[y / IMG_H][x / IMG_W] == 'C')
	{
		map->map.map[y / IMG_H][x / IMG_W] = '0';
		return (1);
	}
	return (0);
}
