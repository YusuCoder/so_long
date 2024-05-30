/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:22:57 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/28 16:02:28 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

int	free_array(void *str)
{
	free(str);
	return (0);
}

void	free_content(void *node)
{
	t_ryusupov	*temp;

	temp = (t_ryusupov *)node;
	free(temp);
}

void	error_exit(const char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}

void	free_map_data(t_map_data *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(map->movements[i]);
		i++;
	}
	free(map->map);
	free(map);
}
