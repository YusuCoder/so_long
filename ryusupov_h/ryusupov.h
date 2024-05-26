/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryusupov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:05:49 by mac               #+#    #+#             */
/*   Updated: 2024/05/25 16:17:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 256
#define HEIGHT 256

/* STANDARD LIBRARIES */
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
/* SUBMODULE LIBRARIES */
#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include "../MLX42/include/MLX42/MLX42.h"

typedef struct	s_map_data
{
	char	**map;
}				t_map_data;
