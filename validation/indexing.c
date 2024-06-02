/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:01:10 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/02 15:33:33 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

t_move_info	*p_and_e_index(char **str, char target)
{
	t_move_info	*index;

	index = (t_move_info *)malloc(sizeof(t_move_info));
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
