/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:46:40 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/02 15:10:56 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	set_C(t_game **info, int width, int height)
{
	mlx_texture_t	*item;
	mlx_image_t		*img;

	item = mlx_load_png("assets/collectable/C.png");
	img = mlx_texture_to_image((*info)->mlx, item);
	if ((*info)->map[height][width] == 'C')
	{
		ft_lstadd_front((t_ryusupov **)&((*info)->C_list), ft_lstnew(img));
		((*info)->C_list)->x = width;
		((*info)->C_list)->y = height;
		mlx_image_to_window((*info)->mlx, ((*info)->C_list)->position, width * IMG, height * IMG);
	}
	mlx_delete_texture(item);
}

void	set_ground(t_game **info, char c, int width, int height)
{
	t_item	*item;

	item = (*info)->item;
	if (c == '1')
		mlx_image_to_window((*info)->mlx, item->wall_img, width, height);
	else
		mlx_image_to_window((*info)->mlx, item->ground_img, width, height);
}

t_move_info	*components(char **map, char smth)
{
	int			x;
	int			y;
	t_move_info	*E;

	y = 0;
	E = (t_move_info *)malloc(sizeof(t_move_info));
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == smth)
			{
				E->x = x;
				E->y = y;
				return (E);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}
