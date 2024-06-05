/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:05:31 by mac               #+#    #+#             */
/*   Updated: 2024/06/06 01:02:25 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}


int main(int argc, char **argv)
{
	t_game	map;

	if (argc == 2)
	{
		map.fd = open(argv[1], O_RDONLY);
		if (map.fd < 0 || map.fd == 0)
		{
			ft_printf("error!\n");
			exit(EXIT_FAILURE);
		}
		if (!map_validation(argv[1]))
		{
			game_init(&map);
			mlx_loop_hook(map.mlx, ft_hook, &map.mlx);
			mlx_loop(map.mlx);
		}
		else
		{
			ft_printf(COLOR_RED"Error!\n"RESET);
		}
	}
	else
		ft_printf(COLOR_GREEN"manual: ./so_long <map_name>\n"RESET);
	exit(EXIT_SUCCESS);
}
