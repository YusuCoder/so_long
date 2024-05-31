/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:05:34 by rustam            #+#    #+#             */
/*   Updated: 2024/05/31 20:20:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

// int valid_way(t_ryusupov *pos, t_map_data **str)
// {
//     if (first_time(&pos, (*str)->already_visited_index) || first_time(&pos,
// (*str)->visiting_info))
//     {
//         return (0);
//     }
//     if (!not_wall((*str)->map[pos->y][pos->x]))
//     {
//         return (0);
//     }
//     if ((*str)->map[pos->y][pos->x] == 0)
//     {
//         return (0);
//     }
//     return (1);
// }

// void set_map(t_map_data **str)
// {
//     (*str)->map[(*str)->P->x][(*str)->P->y] = 'X';
//     (*str)->p_move = 1;
// }

// void copy_coords(t_ryusupov **dst, t_ryusupov **src)
// {
//     (*dst)->x = (*src)->x;
//     (*dst)->y = (*src)->y;
// }

// static int	same_index(t_ryusupov *p, t_ryusupov *e)
// {
// 	if (p == NULL || e == NULL)
// 	{
// 		return (0);
// 	}
// 	if (p->x == e->x && p->y == e->y)
// 	{
// 		return (1);
// 	}
// 	return (0);
// }

static int	not_wall(char c)
{
	if (c != '1')
		return (1);
	return (0);
}

void	move_player(t_ryusupov *pos, t_map_data **str)
{
	t_ryusupov	*lst;

	lst = (t_ryusupov *)malloc(sizeof(t_ryusupov));
	lst->x = (*str)->P->x;
	lst->y = (*str)->P->y;
	ft_lstadd_front((t_ryusupov **)&(*str)->visiting_info, ft_lstnew(lst));
	(*str)->P->x = pos->x;
	(*str)->P->y = pos->y;
	(*str)->map[(*str)->P->x][(*str)->P->y] = 'X';
	(*str)->p_move = 1;
}

static int same_index(t_ryusupov *p, t_ryusupov *e)
{
    if (p == NULL || e == NULL)
    {
        return (0);
    }
    if (p->x == e->x && p->y == e->y)
    {
        return (1);
    }
    return (0);
}

static int first_time(t_ryusupov *pos, t_move_info *node)
{
    t_move_info *index;

    if (node == NULL)
    {
        return (0);
    }
    index = node;
    while (index != NULL)
    {
        // Debug print statements to check the values of index->position and pos
        printf("Checking index->position (%p) and pos (%p)\n", index->position, pos);
        if (index->position == NULL)
        {
            fprintf(stderr, "Error: index->position is NULL\n");
            return (0);
        }
        if (pos == NULL)
        {
            fprintf(stderr, "Error: pos is NULL\n");
            return (0);
        }
        if (same_index(index->position, pos))
            return 1;
        index = index->next;
    }
    return (0);
}
// static int	first_time(t_ryusupov *pos, t_move_info *node)
// {
// 	t_move_info	*index;

// 	if (node == NULL)
// 	{
// 		return (0);
// 	}
// 	index = node;
// 	while (index != NULL)
// 	{
// 		if (same_index(index->position, pos))
// 			return 1;
// 		index = index->next;
// 	}
// 	return (0);
// }

int	valid_way(t_ryusupov pos, t_map_data **str)
{
	if (!first_time(&pos, (*str)->already_visited_index) && !first_time(&pos, (*str)->visiting_info))
	{
		if (not_wall((*str)->map[pos.y][pos.x]) && (*str)->map[pos.y][pos.x])
			return 1;
	}
	return 0;
}

t_ryusupov	calculated_way(t_ryusupov *p, t_ryusupov *way)
{
	t_ryusupov	result;

	result.x = p->x + way->x;
	result.y = p->y + way->y;
	return (result);
}
