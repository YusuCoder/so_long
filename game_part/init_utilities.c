/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:55:04 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/05 05:03:11 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

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
