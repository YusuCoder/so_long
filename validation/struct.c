#include "../ryusupov_h/ryusupov.h"

void	map_length(t_game *map, char *line, int i)
{
	int	len;

	len = ft_arrlength(line);
	if (i == 0)
		map->map.width = len;
	if (len >= WIDTH / IMG_W)
		free_map_data("Error! File is too large!\n", map);
	return ;
}

void	allocate_mem(t_game *game)
{
	if (!game->map.map)
	{
		game->map.map = (char **)malloc(sizeof(char *) * 270);
		if (!game->map.map)
		{
			ft_printf("Error!\n");
			exit(EXIT_FAILURE);
		}
		ft_memset(game->map.map, 0, 270);
	}
}

