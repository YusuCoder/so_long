/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:10:04 by mac               #+#    #+#             */
/*   Updated: 2024/06/06 18:20:55 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	map_struct(char c, t_game *map, int x, int y)
{
	if (c == '1')
		map->map.wall++;
	if (c == 'P')
	{
		map->pos.x = x;
		map->pos.y = y;
		map->map.P++;
	}
	if (c == 'C')
		map->map.C++;
	if (c == '0')
		map->map.ground++;
	if (c == 'E')
		map->map.E++;
}

void	check_walls(int x, int y, t_game *map)
{
	if (map->map.map == NULL || map->map.height == 0)
		free_map_data(COLOR_RED"Ivalid map!\n"RESET, map);
	if (map->map.map[0][x] != '1' || map->map.map[y][0] != '1')
		free_map_data("Invalid map!\n", map);
	if (map->map.height - 1 >= 0)
	{
		if (map->map.map[map->map.height - 1][x] != '1')
			free_map_data(COLOR_RED"Invalid map!\n"RESET, map);
	}
	if (map->map.width - 1 >= 0)
	{
		if (map->map.map[y][map->map.width - 1] != '1')
			free_map_data(COLOR_RED"Invalid map!\n"RESET, map);
	}
}

static void	check_components(char *str)
{
	int	C;
	int	E;
	int	P;
	int	i;

	C = count_check(str, 'C');
	E = count_check(str, 'E');
	P = count_check(str, 'P');
	if (P == 1 && E == 1 && C > 0 && C < 500)
	{
		i = 0;
		while (str[i])
		{
			if (not_component(str[i]) == 1)
				error_exit(COLOR_RED "Error! Invalid component found!" RESET);
			i++;
		}
	}
	else
		error_exit(COLOR_RED "There are missing component!" RESET);
}

static void	wrong_file_error(char *name)
{
	int	fd;
	int	size;

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_printf(COLOR_RED "Error! No such file! 🤨\n" RESET);
		exit(EXIT_FAILURE);
	}
	close(fd);
	size = ft_strlen(name);
	if (size < 4 || ft_strcmp(name + size - 4, ".ber") != 0)
	{
		ft_printf(COLOR_RED"Error! Wrong filename!\n"RESET);
		exit(EXIT_FAILURE);
	}
}

int	map_validation(char *input)
{
	char			*map_contents;

	wrong_file_error(input);
	map_contents = check_map_contetns(input);
	map_is_empty(map_contents);
	check_components(map_contents);
	// map_not_valid(input);
	return (0);
}
