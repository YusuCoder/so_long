/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:57:09 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/26 16:30:23 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

int map_is_empty (char *str)
{
	if (str[0] == '\0')
		{
			ft_printf("Oops! file is empty!\n");
			free(str);
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
