/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:27:14 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/05 23:14:52 by ryusupov         ###   ########.fr       */
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
