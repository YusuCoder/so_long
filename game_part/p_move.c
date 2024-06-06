/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:26:10 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/06 18:05:39 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

static void	move_up(t_game *map, int y, int x, int *moved)
{
	if (map->map.map[(y - IMG_H) / IMG_H][x / IMG_W] != '1')
	{
		map->img.P.img->instances[0].y -= IMG_H;
		*moved = 1;
	}
}

static void	move_down(t_game *map, int y, int x, int *moved)
{
	if (map->map.map[(y + IMG_H) / IMG_H][x / IMG_W] != '1')
	{
		map->img.P.img->instances[0].y += IMG_H;
		*moved = 1;
	}
}

static void	move_right(t_game *map, int y, int x, int *moved)
{
	if (map->map.map[y / IMG_H][(x + IMG_H) / IMG_H] != '1')
	{
		map->img.P.img->instances[0].x += IMG_H;
		*moved = 1;
	}
}

static void	move_left(t_game *map, int y, int x, int *moved)
{
	if (map->map.map[y / IMG_H][(x - IMG_H) / IMG_H] != '1')
	{
		map->img.P.img->instances[0].x -= IMG_H;
		*moved = 1;
	}
}

void	p_move(mlx_key_data_t key, int y, int x, t_game *map)
{
	int	moved;

	moved = 0;
	if (key.action == MLX_PRESS)
	{
		if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
			move_up(map, y, x, &moved);
		else if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
			move_down(map, y, x, &moved);
		else if (key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
			move_right(map, y, x, &moved);
		else if (key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
			move_left(map, y, x, &moved);
		else if (key.key == MLX_KEY_ESCAPE)
			mlx_close_window(map->mlx);
		else
			return ;
		if (moved)
		{
			map->move_count++;
			ft_printf(COLOR_GREEN"Current move count is: %d\n"RESET, map->move_count);
		}
	}
}
