/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:38:00 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/02 17:38:48 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	create_map(t_game **info)
{
	// int	width;
	// int	height;

	// width = IMG * ft_strlen(*(*info)->map);
	// height = IMG * ft_arrlen((*info)->map);
	// printf("%d\n", width);
	// printf("%d\n", height);
	// return ;
	texture_init(info);
	item_init(info);
	// ft_memset((*info)->img->pixels, 255, width * height * 4);
	mlx_image_to_window((*info)->mlx, (*info)->img, 0, 0);
	draw_item(info);
	draw_C(info);
	draw_E(info);
	draw_P_img(info);
	draw_P(info);
}

void	init_game(t_game **info, char *str)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*info)->map_str = check_map_contetns(str);
	(*info)->map = ft_split((*info)->map_str, '\n');
	width = IMG * ft_strlen(*(*info)->map);
	height = IMG * ft_arrlen((*info)->map);
	// printf("%s\n", (*info)->map[2]);
	(*info)->mlx = mlx_init(width, height, "so_long", true);
	// printf("%s\n\n", (*info)->map_str);
	(*info)->img = mlx_new_image((*info)->mlx, width, height);
	(*info)->C_list = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);

}
