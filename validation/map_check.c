/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:31:22 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/06 18:20:41 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../ryusupov_h/ryusupov.h"

// static int	top_and_bottom(char *str)
// {
// 	int	i;

// 	i = 1;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] != '1')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static int	vertical_walls(char **str, unsigned int len)
// {
// 	unsigned int	i;
// 	unsigned int	size;

// 	i = 0;
// 	size = ft_strlen(*str);
// 	while (i < len)
// 	{
// 		if (str[i][0] != '1' || str[i][size - 1] != '1')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static int	incorrect_struct(char **str, size_t len)
// {
// 	size_t			size;
// 	size_t			i;

// 	if (len == 0)
// 		return (0);
// 	size = ft_strlen(str[0]);
// 	// printf("%zu\n", len);
// 	i = 1;
// 	while (i < len)
// 	{
// 		if (ft_strlen(str[i]) != size)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// size_t ft_arrlenn(char *str)
// {
// 	size_t	i;
// 	size_t	counter;

// 	i = 0;
// 	counter = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 		{
// 			counter++;
// 			str[i] = '\0';
// 		}
// 		i++;
// 	}
// 	return (counter);
// }

// int	map_not_valid(char *map)
// {
// 	int				fd;
// 	unsigned int	len = 0;
// 	char			*str;
// 	ssize_t			bytes_read;

// 	fd = open(map, O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	str = (char *)malloc(MAX_SIZE * sizeof(char));
// 	if (!str)
// 	{
// 		close(fd);
// 		return (1);
// 	}
// 	bytes_read = read(fd, str, MAX_SIZE);
// 	if (bytes_read == -1 || bytes_read == 0)
// 	{
// 		free(str);
// 		close(fd);
// 		return (1);
// 	}
// 	close(fd);
// 	len = ft_arrlenn(str);
// 	// printf("%u\n", len);
// 	if (incorrect_struct(&str, len) || top_and_bottom(str)
// 		|| vertical_walls(&str, len))
// 	{
// 		free(str);
// 		return (1);
// 	}
// 	free(str);
// 	return (0);
// }
