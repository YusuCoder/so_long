/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:57:09 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/31 14:31:05 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

size_t ft_arrlen(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void map_is_empty (char *str)
{
	if (str[0] == '\0')
		{
			ft_printf(COLOR_RED"Oops! file is empty! 🙊\n"RESET);
			free(str);
			exit(EXIT_FAILURE);
		}
}

int is_component(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if ((c[i] == 'P' || c[i] == 'E' || c[i] == 'C'))
			return (1);
	}
	return (0);
}

int	not_component(char c)
{
	return !(c == 'C' || c == 'P' || c == 'E'|| c == '\n' || c == '1' || c == '0');
}
int	count_check(char *str, char component)
{
	int	i;
	int	counted;

	i = 0;
	counted = 0;
	while (str[i])
	{
		if (str[i] == component)
			counted++;
		i++;
	}
	return (counted);
}
