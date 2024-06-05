/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:22:57 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/05 00:55:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	error_exit(const char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
void	free_map(char	**map)
{
	int	i;

	if (!map || !*map)
		return ;
	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_data(const char *error_message, t_game *map)
{
	ft_printf("%s\n", error_message);
	free_map(map->map.map);
	if (map->map.fill != NULL)
		free_map_contents(map->map.fill, map->map.height);
	exit(EXIT_FAILURE);
}



void	free_map_contents(char **map, int height)
{
	int	i;

	if (!map || !*map)
		return ;
	i = 0;
	while (i < height && map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
