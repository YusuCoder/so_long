/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_c_not_reachable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rustam <rustam@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-30 12:54:22 by rustam            #+#    #+#             */
/*   Updated: 2024-05-30 12:54:22 by rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void step_back(t_map_data **str)
{
    t_ryusupov *temp;

    ft_lstadd_front(&(*str)->already_visited_index, ft_lstnew((*str)->P));
    if (!(*str)->visiting_info)
    {
        (*str)->map_loop = 1;
        return ;
    }
    temp = (*str)->visiting_info;
    (*str)->P = (*str)->visiting_info->position;
    (*str)->visiting_info = (*str)->visiting_info->next;
    temp->next = NULL;
    free(temp);
}

static void way_check(t_map_data *str)
{
    int i;
    t_ryusupov new_pos;

    i = 0;
    set_map(str);
    while (str->map_loop == 0)
    {
        while (str->movements[i])
        {
            str->movements[i] = 0;
            new_pos = calculated_way(str->P, str->movements[i++]);
            if (valid_way(new_pos, str))
            {
                move_player(&new_pos, str);
                break;
            }
        }
        if (!str->p_move)
            step_back(str);
        i = 0;
    }
}

int e_c_not_reachable(t_map_data *str)
{
    int i;

    way_check(str);
    ft_lstclear(&str->already_visited_index, free_content);

    i = 0;
    while (str->map[++i])
    {
        if (is_component(str->map[i]))
            return (1);
    }

    return (0);
}


