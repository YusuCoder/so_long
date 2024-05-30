/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rustam <rustam@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-30 19:05:34 by rustam            #+#    #+#             */
/*   Updated: 2024-05-30 19:05:34 by rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

// int valid_way(t_ryusupov *pos, t_map_data **str)
// {
//     if (first_time(&pos, (*str)->already_visited_index) || first_time(&pos, (*str)->visiting_info))
//     {
//         return 0;
//     }
//     if (!not_wall((*str)->map[pos->y][pos->x]))
//     {
//         return 0;
//     }
//     if ((*str)->map[pos->y][pos->x] == 0)
//     {
//         return 0;
//     }
//     return 1;
// }

void set_map(t_map_data **str)
{
    (*str)->map[(*str)->P->x][(*str)->P->y] = 'X';
    (*str)->p_move = 1;
}

void copy_coords(t_ryusupov **dst, t_ryusupov **src)
{
    (*dst)->x = (*src)->x;
    (*dst)->y = (*src)->y;
}

void move_player(t_ryusupov *pos, t_map_data **str)
{
    t_ryusupov *lst;

    lst = (t_ryusupov *)malloc(sizeof(t_ryusupov));
    copy_coords(&lst, &(*str)->P);
    ft_lstadd_front(&(*str)->visiting_info, ft_lstnew(lst));
    copy_coords(&(*str)->P, &pos);
    set_map(str);
}

int valid_way(t_ryusupov pos, t_map_data **str)
{
    if (!(fitst_time(&pos, (*str)->already_visited_index)
            || first_time(&pos, (*str)->visiting_info)))
        if (not_wall((*str)->map[pos.y][pos.x]) && (*str)->map[pos.y][pos.x])
            return (1);
        return (0);
}

t_ryusupov calculated_way(t_ryusupov *p, t_ryusupov *way)
{
    t_ryusupov result;

    result.x = p->x + way->x;
    result.y = p->y + way->y;
    return (result);
}