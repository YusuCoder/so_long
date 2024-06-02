/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:38:55 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/02 14:34:34 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	load_item(t_game **info)
{
	t_item	*items;
	mlx_t	*mlx;

	mlx = (*info)->mlx;
	items = (*info)->item;
	items->ground_img = mlx_texture_to_image(mlx, items->ground);
	items->wall_img = (mlx_texture_to_image(mlx, items->wall));
	items->exit_img = (mlx_texture_to_image(mlx, items->exit));
}

void	load_img(t_game **info)
{
	t_texture	*img;

	img = (*info)->texture;
	img->right_img[0] = mlx_texture_to_image((*info)->mlx, img->right[0]);
	img->right_img[1] = NULL;
	img->img = mlx_texture_to_image((*info)->mlx, img->right[0]);
}

void	item_init(t_game **info)
{
	t_item	*item;

	(*info)->item = (t_item *)malloc(sizeof(t_item));
	item = (*info)->item;
	item->ground = mlx_load_png("assets/area/water.png");
	item->wall = mlx_load_png("assets/area/iceberg.png");
	item->exit = mlx_load_png("assets/exit/exit.png");
	load_item(info);
}

void	texture_init(t_game **info)
{
	t_texture	*img;

	(*info)->texture = (t_texture *)malloc(sizeof(t_texture));
	img = (*info)->texture;
	img->right[0] = mlx_load_png("assets/player/player_right.png");
	img->right[1] = NULL;
	load_img(info);
}
