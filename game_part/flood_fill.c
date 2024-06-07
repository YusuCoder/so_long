/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 05:26:31 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/07 04:27:04 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	prepare_map_to_fill(t_game *str)
{
	int	y;
	int	i;

	i = 0;
	if (str->map.fill == NULL)
	{
		y = str->map.height + 1;
		str->map.fill = (char **)malloc(sizeof(char *) * y);
		if (!str->map.fill)
			free_map_data(COLOR_RED "Allocation failed!\n" RESET, str);
		while (i < str->map.height)
		{
			str->map.fill[i] = (char *)ft_calloc(str->map.width + 1,
					sizeof(char));
			if (!str->map.fill[i])
				free_map_data(COLOR_RED "Allocation failed!\n" RESET, str);
			ft_strlcpy(str->map.fill[i], str->map.map[i], str->map.width + 1);
			i++;
		}
		str->map.fill[i] = NULL;
	}
}

void	flood_fill(t_game *map, int x, int y, char c)
{
	if (x < 0 || x >= map->map.width || y < 0 || y >= map->map.height)
		return ;
	if (map->map.fill[y][x] == c || map->map.fill[y][x] == '1')
		return ;
	map->map.fill[y][x] = c;
	flood_fill(map, x - 1, y, c);
	flood_fill(map, x + 1, y, c);
	flood_fill(map, x, y - 1, c);
	flood_fill(map, x, y + 1, c);
}

void	find_not_filled_target(t_game *map, int width, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map->map.fill[y][x] != '1' && map->map.fill[y][x] != 'X')
			{
				ft_printf("Index: [%d][%d]: Component: [%c]. ", y, x,
					map->map.fill[y][x]);
				free_map_data(COLOR_RED "Error!" RESET, map);
			}
			x++;
		}
		y++;
	}
	free_map_contents(map->map.fill, map->map.height);
}

void	flood_loop(t_game *map, char c)
{
	int	width;
	int	height;

	if (map == NULL)
	{
		ft_printf("Map is NULL!\n");
		exit(EXIT_FAILURE);
	}
	width = map->map.width;
	height = map->map.height;
	flood_fill(map, map->pos.x, map->pos.y, c);
	find_not_filled_target(map, width, height);
}
