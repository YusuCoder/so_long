/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:22:57 by ryusupov          #+#    #+#             */
/*   Updated: 2024/05/26 16:30:15 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryusupov_h/ryusupov.h"

int	free_array(void *str)
{
	free(str);
	return (0);
}

void	error_exit(const char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
