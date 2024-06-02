/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:58:07 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/02 14:59:25 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	draw_P(t_game **info)
{
	int			x;
	int			y;
	t_texture	*P;
	t_move_info	*pos;

	pos = components((*info)->map, 'P');
	x = pos->x * IMG;
	y = pos->y * IMG;
	P = (*info)->texture;
	mlx_image_to_window((*info)->mlx, P->right_img[0], x - 16, y - 24);
	free(pos);
}

void	draw_E(t_game **info)
{
	t_item		*img;
	t_move_info	*E;

	E = components((*info)->map, 'E');
	img = (*info)->item;
	mlx_image_to_window((*info)->mlx, img->exit_img, E->x *IMG, E->y *IMG);

}

void	draw_P_img(t_game **info)
{
	int			x;
	int			y;
	t_move_info	*pos;

	pos = components((*info)->map, 'P');
	x = pos->x * IMG;
	y = pos->y * IMG;
	(*info)->P_img = mlx_new_image((*info)->mlx, IMG, IMG);
	ft_memset((*info)->P->pixels, 0, IMG * IMG * 4);
	mlx_image_to_window((*info)->mlx, (*info)->P_img, x, y);
	free(pos);
}

void	draw_C(t_game **info)
{
	int	x;
	int	y;

	y = 0;
	while ((*info)->map[y])
	{
		x = 0;
		while ((*info)->map[y][x])
		{
			set_C(info, x, y);
		}

		y++;
	}

}

void		draw_item(t_game **info)
{
	int	x;
	int	y;

	y = 0;
	while((*info)->map[y])
	{
		x = 0;
		while ((*info)->map[x])
		{
			set_ground(info, (*info)->map[y][x], x * IMG, y * IMG);
			x++;
		}
		y++;
	}
}
