/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:04:59 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/07 00:46:35 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

static int	get_map_content_size(char *str)
{
	int		fd;
	char	*mem;
	int		size;
	int		total_size;

	total_size = 0;
	fd = open(str, O_RDONLY);
	mem = malloc(100);
	if (!mem)
	{
		ft_printf("Malloc error! map_content_size");
		close(fd);
		return (0);
	}
	while ((size = read(fd, mem, 100)) > 0)
		total_size = total_size + size;
	if (size < 0)
		return (0);
	close(fd);
	free(mem);
	if (size < 0)
		return (0);
	return (total_size);
}

char *check_map_contetns(char *str)
{
	int		fd;
	int		content_size;
	char	*map;

	content_size = get_map_content_size(str) + 1;
	map = malloc(content_size);
	if (!map)
	{
		printf("Malloc error! check_map_contents\n");
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_RDONLY);
	if (read(fd, map, content_size) < 0)
	{
		ft_printf("Read error! check_map_contents\n");
		free(map);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (map);
}
