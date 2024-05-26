/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:10:04 by mac               #+#    #+#             */
/*   Updated: 2024/05/25 21:45:32 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

int	map_validation(char *input)
{
	char		*map_contents;
	t_map_data	*map;

	if (wrond_file(input))
		return (wrong_file_error);
	map_contents = open_map(input);
	if (map_is_empty(map_contents))
		return (empty_map_error(map_contents));
	if (invalid_map(map->map))
		return (map_error(map));
	return (0);
}
