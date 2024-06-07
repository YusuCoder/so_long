/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryusupov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:05:49 by mac               #+#    #+#             */
/*   Updated: 2024/06/07 05:09:47 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 7000
#define HEIGHT 7000
#define IMG_W 70
#define IMG_H 70
#define FRAME 4
#define MAX_SIZE 1024
#define TOTAL_LEVELS 3
/*-------PNG Images--------*/
#define WALL "./assets/area/wall_4.png"
#define GROUND "./assets/area/water_1.png"
#define GROUND1 "./assets/area/water_1.png"
#define PLAYER "./assets/player/player_right.png"
#define EXIT_START "./assets/exit/exit_3.png"
#define EXIT_FINAL "./assets/exit/final.png"
#define COLLECTABLE "./assets/collectable/collect_1.png"
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
typedef struct s_position
{
	int					x;
	int					y;
	unsigned int		move;
}						t_position;

typedef struct s_multi
{
	mlx_image_t			*img;
	int					x;
	int					y;
}						t_multi;

typedef struct s_img
{
	mlx_image_t			*ground[2];
	mlx_image_t			*walls;
	t_multi				E[2];
	t_multi				P;
	t_multi				C[100];
}						t_img;

typedef struct s_map
{
	char				**map;
	char				**fill;
	int					height;
	int					width;
	int					C;
	int					P;
	int					E;
	int					wall;
	int					ground;
	int					cc;
}						t_map;

typedef struct s_move_info
{
	void				*position;
	int					x;
	int					y;
	void				*content;
	struct s_move_info	*next;
}						t_move_info;

typedef struct s_game
{
	mlx_t				*mlx;
	int					fd;
	t_img				img;
	t_map				map;
	t_position			pos;
	int					count;
	int					move_count;
	int					level;
	int					lvl;
	char				**levels;
	int					total_levels;
	int					finish_game;
}						t_game;

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
int						is_component(char *c);
void					check_walls(int x, int y, t_game *map);
void					delete_all_images(t_game *map);
/*-------------game_initialization---------------*/
void					init_values(t_game *map);
void					init_map(t_game *game);
void					game_init(t_game *map);
void					init_values(t_game *map);
void					allocate_mem(t_game *game);
void					map_length(t_game *map, char *line, int i);
void					init_layer(t_game *game);
void					prepare_map_to_fill(t_game *str);
void					flood_loop(t_game *map, char c);
void					map_struct(char c, t_game *map, int x, int y);
void					map_struct(char c, t_game *map, int x, int y);
void					mlx_window_init(t_game *map);
void					set_textures(t_game *map);
void					set_img(t_game *map, mlx_image_t **img, char *path);
void					set_ground_texture(t_game *map);
void					set_layer_texture(t_game *map);
void					player(t_game *map, int x, int y);
void					collectable(t_game *map, int x, int y, int *count);
void					exit_exit(t_game *map, int x, int y);
/*--------------MLX_MOVEMENT_FUNCTIONS--------------*/
void					move_hook(mlx_key_data_t key, void *act);
void					p_move(mlx_key_data_t key, int y, int x, t_game *map);
int						check_and_update_map(t_game *map, int x, int y);
void					process_collectible(t_game *map, int x, int y);
void					c_collect_and_finish(t_game *map, int x, int y);
void					no_c_left(t_game *map, int x, int y);
