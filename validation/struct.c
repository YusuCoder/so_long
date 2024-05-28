#include "../ryusupov_h/ryusupov.h"

int	initialize_P_and_E(t_map_data *map)
{
	map->P = p_and_e_index(map->map, 'P');
	if (!map->P)
	{
		return (0);
	}
	map->E = p_and_e_index(map->map, 'E');
	if (!map->E)
	{
		return (0);
	}
	return (1);
}

void	initialize_movements(t_map_data *map)
{
	map->movements[0]->x = 0;
	map->movements[0]->y = -1;
	map->movements[1]->x = 0;
	map->movements[1]->y = 1;
	map->movements[2]->x = 1;
	map->movements[2]->y = 0;
	map->movements[3]->x = -1;
	map->movements[3]->y = 0;
}

int	allocate_movements(t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		map->movements[i] = (t_ryusupov *)malloc(sizeof(t_ryusupov));
		if (!map->movements[i])
		{
			j = 0;
			while (j < i)
			{
				free(map->movements[j]);
				j++;
			}
			return (0);
		}
		i++;
	}
	map->movements[4] = NULL;
	return (1);
}

// Function to initialize map
t_map_data	*initialize_map(char *str)
{
	t_map_data	*map;

	map = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map)
		return (NULL);
	if (!allocate_movements(map))
	{
		free(map);
		return (NULL);
	}
	initialize_movements(map);
	map->visiting_info = NULL;
	map->already_visited_index = NULL;
	map->map = ft_split(str, '\n');
	if (!map->map)
	{
		free_map_data(map);
		return (NULL);
	}
	if (!initialize_P_and_E(map))
	{
		free_map_data(map);
		return (NULL);
	}
	map->map_loop = 0;
	return (map);
}

