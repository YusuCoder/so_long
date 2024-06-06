/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:47:00 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/07 01:45:17 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	c_delete(t_game *map)
{
	int	img_index;

	int x, y;
	img_index = 0;
	y = 0;
	while (y < map->map.height)
	{
		x = 0;
		while (x < map->map.width)
		{
			if (map->map.map[y][x] == 'C')
			{
				if (img_index < 100 && map->img.C[img_index].img != NULL)
					mlx_delete_image(map->mlx, map->img.C[img_index].img);
				else
					ft_printf("Error: Attempt to delete invalid image at (%d, \
							%d)\n",
								y,
								x);
				img_index++;
			}
			x++;
		}
		y++;
	}
	if (map->count != map->map.cc)
		return ;
}

void	p_g_delete(t_game *map)
{
	int	i;

	if (!map->img.P.img)
		return ;
	mlx_delete_image(map->mlx, map->img.P.img);
	i = 0;
	while (i < 10)
	{
		mlx_delete_image(map->mlx, map->img.ground[i]);
		i++;
	}
}

void	delete_all_images(t_game *map)
{
	c_delete(map);;
	p_g_delete(map);
	mlx_delete_image(map->mlx, map->img.E[0].img);
	mlx_delete_image(map->mlx, map->img.E[1].img);
	mlx_delete_image(map->mlx, map->img.walls);
}
