/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:05:31 by mac               #+#    #+#             */
/*   Updated: 2024/06/07 01:47:19 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ryusupov_h/ryusupov.h"

void	check_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	map;

	atexit(check_leaks);
	if (argc == 2)
	{
		map.fd = open(argv[1], O_RDONLY);
		if (!map_validation(argv[1]))
		{
			game_init(&map);
			mlx_key_hook(map.mlx, &move_hook, &map.mlx);
			mlx_loop(map.mlx);
			delete_all_images(&map);
			mlx_terminate(map.mlx);
		}
		else
			ft_printf(COLOR_RED "Error!\n" RESET);
	}
	else
		ft_printf(COLOR_GREEN "manual: ./so_long <map_name>\n" RESET);
	exit(EXIT_SUCCESS);
}
