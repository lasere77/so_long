/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:14:51 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/18 10:19:40 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

void	exit_error(char *str, char **map, int exit_code)
{
	if (map)
		ft_free_split(map);
	if (str)
		write(2, str, ft_strlen(str));
	exit(exit_code);
}
