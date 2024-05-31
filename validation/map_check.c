/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:31:22 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/29 18:08:21 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

static int	top_and_bottom(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	vertical_walls(char **str, unsigned int len)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = ft_strlen(*str);
	while (i < len)
	{
		if (str[i][0] != '1' || str[i][size - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	incorrect_struct(char **str, size_t len)
{
	size_t			size;
	unsigned int	i;

	if (len == 0)
		return (0);
	size = ft_strlen(*str);
	// printf("%zu\n", len);
	i = 1;
	while (i < len)
	{
		if (ft_strlen(str[i]) != size)
			return (1);
		i++;
	}
	return (0);
}

int	map_not_valid(char **str)
{
	unsigned int	len;

	if (!*str)
		return (0);
	len = ft_arrlen(str);
    // printf("%u\n", len);
	if (incorrect_struct(str, len))
		return (1);
	if (top_and_bottom(*str))
		return (1);
	if (vertical_walls(str, len))
		return (1);
	if (top_and_bottom(str[len - 1]))
		return (1);
	return (0);
}
