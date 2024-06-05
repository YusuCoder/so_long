/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryusupov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:05:49 by mac               #+#    #+#             */
/*   Updated: 2024/06/05 05:03:29 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 7100
#define HEIGHT 7100
# define IMG_W 71
# define IMG_H 71
# define FRAME 4
# define MAX_SIZE 1024

# define MAP_CONTAINS	"PEC01"
# define COMPONENTS		"CEP"
# define FILL_VALUE		"1X"

/* STANDARD LIBRARIES */
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
/* SUBMODULE LIBRARIES */
#include "../MLX42/include/MLX42/MLX42.h"
#include "./libft/libft.h"
#include "./printf/ft_printf.h"

/*-------STRUCTS--------*/

typedef struct s_position
{
	int				x;
	int				y;
	unsigned int	move;
}				t_position;

typedef struct s_img
{
	mlx_image_t	*ground[2];
	mlx_image_t	*walls;
}				t_img;

typedef struct s_map
{
	char	**map;
	char	**fill;
	int		height;
	int		width;
	int		C;
	int		P;
	int		E;
	int		wall;
	int		ground;
}			t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	int			fd;
	t_img		img;
	t_map		map;
	t_position	pos;
	int			count;
	int			level;
	int			finish_game;
}				t_game;


/*-------------validations-------------*/
void					map_is_empty(char *str);
int						not_component(char c);
int						count_check(char *str, char component);
char					*check_map_contetns(char *str);
void					error_exit(const char *error_message);
int						map_validation(char *input);
void					free_map_data(const char *error_message, t_game *map);
void					free_map_contents(char **map, int height);
void					free_map(char **map);
void					error_exit(const char *error_message);
size_t					ft_arrlen(char *str);
int 					is_component(char *c);
/*-------------game_initialization---------------*/
void					init_values(t_game *map);
void					init_map(t_game *game);
size_t 					ft_arrlength(char *str);
void					game_init(const char **argv);
void					init_values(t_game *map);
void					allocate_mem(t_game *game);
void					map_length(t_game *map, char *line, int i);

