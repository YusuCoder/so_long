/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:04:59 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/07 05:05:23 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	return (fd);
}

int	read_file_content(int fd, int *total_size)
{
	char	*mem;
	int		size;

	*total_size = 0;
	mem = malloc(1024);
	if (!mem)
	{
		close(fd);
		return (0);
	}
	while (1)
	{
		size = read(fd, mem, 1024);
		if (size < 0)
		{
			free(mem);
			close(fd);
			return (0);
		}
		if (size == 0)
			break ;
		*total_size += size;
	}
	free(mem);
	return (1);
}

int	get_map_content_size(char *str)
{
	int	total_size;
	int	fd;

	fd = open_file(str);
	if (fd == -1)
		return (0);
	if (read_file_content(fd, &total_size))
	{
		close(fd);
		return (total_size);
	}
	close(fd);
	return (0);
}

char	*check_map_contetns(char *str)
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
