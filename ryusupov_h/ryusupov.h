/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryusupov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:05:49 by mac               #+#    #+#             */
/*   Updated: 2024/05/26 14:30:00 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 256
#define HEIGHT 256

/* STANDARD LIBRARIES */
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <fcntl.h>
/* SUBMODULE LIBRARIES */
#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include "../MLX42/include/MLX42/MLX42.h"

typedef struct	s_map_data
{
	char	**map;
}				t_map_data;

/*-------------Function declarations-------------*/
int		free_array(void *str);
int		map_is_empty (char *str);
int		not_component(char c);
int		count_check(char *str, char component);
char	*check_map_contetns(char *str);
void	error_exit(const char *error_message);
int		map_validation(char *input);
