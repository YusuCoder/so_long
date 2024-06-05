/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:53:32 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/05 05:04:17 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	init_map(t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(game->fd);
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
	map->map.C = 0;
	map->map.E = 0;
	map->map.P = 0;
	map->map.wall = 0;
	map->map.ground = 0;
	map->count = 0;
	map->finish_game = 0;
	map->map.fill = NULL;
}
