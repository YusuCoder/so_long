/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 04:48:51 by ryusupov          #+#    #+#             */
/*   Updated: 2024/06/06 00:15:57 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

void	game_init(t_game *map)
{
	init_values(map);
	init_map(map);
	init_layer(map);
	mlx_window_init(map);
	set_textures(map);
}
