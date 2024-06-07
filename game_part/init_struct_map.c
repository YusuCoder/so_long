/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:53:32 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/07 17:51:20 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	init_layer(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			map_struct(game->map.map[y][x], game, x, y);
			check_walls(x, y, game);
			x++;
		}
		y++;
	}
	prepare_map_to_fill(game);
	flood_loop(game, 'X');
}

void	init_map(t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(game->fd);
	map_is_empty(line);
	i = 0;
	while (line && !(line[0] == '\n'))
	{
		if (i >= HEIGHT / IMG_H)
			free_map_data("Error! File is too big!\n", game);
		if (game->map.map == NULL)
			allocate_mem(game);
		game->map.map[i] = malloc(sizeof(char) * (ft_arrlen(line) + 1));
		if (!game->map.map[i])
			free_map_data("Error!\n", game);
		map_length(game, line, i);
		ft_strlcpy(game->map.map[i], line, game->map.width + 1);
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->map.height = i;
	free(line);
	close(game->fd);
}

void	init_values(t_game *map)
{
	map->pos.x = 0;
	map->pos.y = 0;
	map->pos.move = 0;
	map->map.width = 0;
	map->map.height = 0;
	map->map.c = 0;
	map->map.e = 0;
	map->map.p = 0;
	map->map.wall = 0;
	map->map.ground = 0;
	map->count = 0;
	map->finish_game = 0;
	map->map.fill = NULL;
}
