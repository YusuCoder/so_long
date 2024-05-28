/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:01:10 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/28 16:01:35 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

t_ryusupov	*p_and_e_index(char **str, char target)
{
	t_ryusupov	*index;

	index = (t_ryusupov *)malloc(sizeof(t_ryusupov));
	if (!index)
		return (NULL);
	index->y = 0;
	index->x = 0;
	while (str[index->x] != NULL)
	{
		index->y = 0;
		while (str[index->x][index->y] != 0)
		{
			if (str[index->x][index->y] == target)
				return (index);
			index->y++;
		}
		index->x++;
	}
	free(index);
	return (NULL);
}
