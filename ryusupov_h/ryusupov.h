/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryusupov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:05:49 by mac               #+#    #+#             */
/*   Updated: 2024/06/02 17:09:54 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 256
#define HEIGHT 256
# define IMG 32

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

typedef struct s_item
{
	mlx_texture_t	*ground;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_image_t		*ground_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*exit_img;
}				t_item;
typedef struct s_textures
{
	mlx_texture_t	*left[2];
	mlx_texture_t	*right[2];
	mlx_image_t		*right_img[2];
	mlx_image_t		*left_img[2];
	mlx_image_t		*img;
}				t_texture;
typedef struct s_move_info
{
	void				*position;
	int					x;
	int					y;
	void				*content;
	struct s_move_info	*next;
}						t_move_info;
typedef struct s_map_data
{
	char				**map;
    int					width;
    int					height;
	struct s_move_info	*movements[5];
	struct s_move_info	*P;
	struct s_move_info	*E;
	struct s_move_info	*visiting_info;
	struct s_move_info	*already_visited_index;
	int					map_loop;
	char				p_move;

}						t_map_data;

typedef struct s_game
{
	mlx_image_t			*P_img;
	mlx_image_t			*point;
	mlx_texture_t		*P;
	mlx_t				*mlx;
	mlx_image_t			*img;
	t_item				*item;
	t_texture			*texture;
	t_move_info			*C_list;
	char				*map_str;
	char				**map;
	char				*C;
	int					width;
	int					height;

}						t_game;

/*-------------Function declarations-------------*/
int						free_array(void *str);
void					map_is_empty(char *str);
int						not_component(char c);
int						count_check(char *str, char component);
char					*check_map_contetns(char *str);
void					error_exit(const char *error_message);
int						map_validation(char *input);
int						map_not_valid(char **str);
void					free_map_data(t_map_data *map);
void					free_content(void *node);
size_t					ft_arrlen(char **str);
t_move_info				*p_and_e_index(char **str, char target);
t_map_data				*initialize_map(char *str);
t_move_info 			calculated_way(t_move_info *p, t_move_info *way);
int 					valid_way(t_move_info pos, t_map_data **str);
int 					e_c_not_reachable(t_map_data *str);
/* void 					set_map(t_map_data **str); */
int 					is_component(char *c);
void 					move_player(t_move_info *pos, t_map_data **str);
void					free_list(t_move_info **lst, void (*del)(void *));
void					init_game(t_game **info, char *str);
void					create_map(t_game **info);
void					start_game(char *str);
void					texture_init(t_game **info);
void					item_init(t_game **info);
void					draw_item(t_game **info);
void					draw_C(t_game **info);
void					draw_P_img(t_game **info);
void					draw_E(t_game **info);
void					draw_P(t_game **info);
t_move_info				*components(char **map, char smth);
void					set_ground(t_game **info, char c, int width, int height);
void					set_C(t_game **info, int width, int height);
void					free_ma(char	**str);
void					free_texture(t_game **info);
void					free_struct(t_game **info);
void					free_map(t_game **info);
