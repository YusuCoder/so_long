/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:10:04 by mac               #+#    #+#             */
/*   Updated: 2024/05/31 20:28:13 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

static void	check_components(char *str)
{
	int	C;
	int	E;
	int	P;
	int	i;

	C = count_check(str, 'C');
	E = count_check(str, 'E');
	P = count_check(str, 'P');
	if (P == 1 && E == 1 && C > 0)
	{
		i = 0;
		while (str[i])
		{
			if (not_component(str[i]) == 1)
				error_exit(COLOR_RED"Error! Invalid component found!"RESET);
			i++;
		}
	}
	else
		error_exit(COLOR_RED"There are missing component!"RESET);
}

static void	wrong_file_error(char *name)
{
	int	fd;
	int	size;

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_printf(COLOR_RED"Error! No such file! 🤨\n"RESET);
		exit(EXIT_FAILURE);
	}
	close(fd);
	size = ft_strlen(name);
	if (size < 4 || ft_strcmp(name + size - 4, ".ber") != 0)
	{
		ft_printf("Error! Wrong filename!\n");
		exit(EXIT_FAILURE);
	}
}

int	map_validation(char *input)
{
	char	*map_contents;
	t_map_data *map;

	map_contents = NULL;
	map = NULL;
	wrong_file_error(input);
	map_contents = check_map_contetns(input);
	map_is_empty(map_contents);
	check_components(map_contents);
	map = initialize_map(map_contents);
	if (map_not_valid(map->map))
		return(1);
	e_c_not_reachable(map);
	return (0);
}
