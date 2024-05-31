/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_c_not_reachable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:54:22 by rustam            #+#    #+#             */
/*   Updated: 2024/05/31 20:12:04 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

static void	back(t_map_data **str)
{
	t_ryusupov	*temp;

	ft_lstadd_front((t_ryusupov **)&(*str)->already_visited_index,
			ft_lstnew((*str)->P));
	if (!(*str)->visiting_info)
	{
		(*str)->map_loop = 1;
		return ;
	}
	temp = (t_ryusupov *)(*str)->visiting_info;
	(*str)->P = (*str)->visiting_info->position;
	(*str)->visiting_info = (*str)->visiting_info->next;
	temp->next = NULL;
	free(temp);
}

static void	way_check(t_map_data *str)
{
	int			i;
	t_ryusupov	new_pos;

	i = 0;
	if (str->P)
	{
		str->map[str->P->x][str->P->y] = 'X';
	}
	str->p_move = 1;
	while (str->map_loop == 0)
	{
		while (str->movements[i])
		{
			str->p_move = 0;
			new_pos = calculated_way(str->P, str->movements[i++]);
			if (valid_way(new_pos, &str))
			{
				move_player(&new_pos, &str);
				break ;
			}
		}
		if (!str->p_move)
			back(&str);
		i = 0;
	}
}

// static void	way_check(t_map_data *str)
// {
// 	int			i;
// 	t_ryusupov	new_pos;

// 	i = 0;
// 	str->map[str->P->x][str->P->y] = 'X';
// 	str->p_move = 1;
// 	while (str->map_loop == 0)
// 	{
// 		while (str->movements[i])
// 		{
// 			str->p_move = 0;
// 			new_pos = calculated_way(str->P, str->movements[i++]);
// 			if (valid_way(new_pos, &str))
// 			{
// 				move_player(&new_pos, &str);
// 				break ;
// 			}
// 		}
// 		if (!str->p_move)
// 			back(&str);
// 		i = 0;
// 	}
// }

int	e_c_not_reachable(t_map_data *str)
{
	int	i;

	way_check(str);
	free_list(&str->already_visited_index, free_content);
	i = 0;
	while (str->map[++i])
	{
		if (is_component(str->map[i]))
			return (1);
	}
	return (0);
}
