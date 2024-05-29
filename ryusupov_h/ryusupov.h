/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryusupov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:05:49 by mac               #+#    #+#             */
/*   Updated: 2024/05/29 13:27:40 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 256
#define HEIGHT 256

/* STANDARD LIBRARIES */
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* SUBMODULE LIBRARIES */
#include "../MLX42/include/MLX42/MLX42.h"
#include "./libft/libft.h"
#include "./printf/ft_printf.h"

/*-------STRUCTS--------*/

typedef struct s_move_info
{
	void				*position;
	int					x;
	int					y;
	struct s_info		*next;
}						t_move_info;
typedef struct s_map_data
{
	char				**map;
    int					width;
    int					height;
	struct s_ryusupov	*movements[5];
	struct s_ryusupov	*P;
	struct s_ryusupov	*E;
	struct s_move_info	*visiting_info;
	struct s_move_info	*already_visited_index;
	int					map_loop;

}						t_map_data;

typedef struct s_game
{
	mlx_image_t			*pic;
	mlx_image_t			*point;
	mlx_texture_t		*P;
	mlx_t				*mlx;
	mlx_image_t			*img;
	char				*map_str;
	char				**map;
	int					width;
	int					height;

}						t_game;

/*-------------Function declarations-------------*/
int						free_array(void *str);
int						map_is_empty(char *str);
int						not_component(char c);
int						count_check(char *str, char component);
char					*check_map_contetns(char *str);
void					error_exit(const char *error_message);
int						map_validation(char *input);
int						map_not_valid(char **str);
void					free_map_data(t_map_data *map);
size_t					ft_arrlen(char **str);
t_ryusupov				*p_and_e_index(char **str, char target);
t_map_data				*initialize_map(char *str);
