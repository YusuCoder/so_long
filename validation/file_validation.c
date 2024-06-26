/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:10:04 by mac               #+#    #+#             */
/*   Updated: 2024/06/07 19:59:41 by ryusupov         ###   ########.fr       */
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
		map->map.p++;
	}
	if (c == 'C')
		map->map.c++;
	if (c == '0')
		map->map.ground++;
	if (c == 'E')
		map->map.e++;
	if (ft_strchr("CP10E", c) == NULL)
		free_map_data(COLOR_RED"Error! invalid component!"RESET, map);
}

void	check_walls(int x, int y, t_game *map)
{
	if (map->map.map == NULL || map->map.height == 0)
		free_map_data(COLOR_RED "Ivalid map!\n" RESET, map);
	if (map->map.map[0][x] != '1' || map->map.map[y][0] != '1')
		free_map_data("Invalid map!\n", map);
	if (map->map.height - 1 >= 0)
	{
		if (map->map.map[map->map.height - 1][x] != '1')
			free_map_data(COLOR_RED "Invalid map!\n" RESET, map);
	}
	if (map->map.width - 1 >= 0)
	{
		if (map->map.map[y][map->map.width - 1] != '1')
			free_map_data(COLOR_RED "Invalid map!\n" RESET, map);
	}
}

static void	check_components(char *str)
{
	int	c;
	int	e;
	int	p;

	c = count_check(str, 'C');
	e = count_check(str, 'E');
	p = count_check(str, 'P');
	if (p == 1 && e == 1 && c > 0 && c < 500)
		return ;
	else
		error_exit(COLOR_RED "Something wrong with components!" RESET);
}

static void	wrong_file_error(char *name)
{
	int	fd;
	int	size;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(COLOR_RED "Error! No such file! 🤨\n" RESET);
		exit(EXIT_FAILURE);
	}
	close(fd);
	size = ft_strlen(name);
	if (size < 4 || ft_strcmp(name + size - 4, ".ber") != 0)
	{
		ft_printf(COLOR_RED "Error! Wrong filename!\n" RESET);
		exit(EXIT_FAILURE);
	}
}

int	map_validation(char *input)
{
	char	*map_contents;

	wrong_file_error(input);
	map_contents = check_map_contetns(input);
	map_is_empty(map_contents);
	check_components(map_contents);
	free(map_contents);
	return (0);
}
