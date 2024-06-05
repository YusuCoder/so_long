/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:23:01 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/06 00:03:39 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	set_img(t_game *map, mlx_image_t **img, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		free_map_data("Error with texture!\n", map);
	*img = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	if (!*img)
		free_map_data("Error! Check the texture!\n", map);
}
static void	set_image_to_window(t_game *map, mlx_image_t *img, int x, int y)
{
	mlx_image_to_window(map->mlx, img, x * IMG_W, y * IMG_H);
	if (!img)
	{
		free_map(map->map.map);
		ft_printf("Error! Unable to load the image!\n");
		exit(EXIT_FAILURE);
	}
}

void		set_ground_texture(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->map.height)
	{
		x = 0;
		while (x < map->map.width)
		{
			if ((x % 2 == 1 && y % 2 != 1) || (x % 2 != 1 && y % 2 == 1))
				set_image_to_window(map, map->img.ground[0], x, y);
			else
				set_image_to_window(map, map->img.ground[1], x, y);
			x++;
		}
		y++;
	}
}

void	set_layer_texture(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->map.height)
	{
		x = 0;
		while (x < map->map.width)
		{
			if (map->map.map[y][x] == '1')
				mlx_image_to_window(map->mlx, map->img.walls, x * IMG_W, y * IMG_H);
			else if (map->map.map[y][x] == 'C')
				collectable(map, x, y, &map->count);
			else if (map->map.map[y][x] == 'P')
				player(map, x, y);
			else if (map->map.map[y][x] == 'E')
				exit_exit(map, x, y);
			x++;
		}
		y++;
	}
	map->count = 0;
}
