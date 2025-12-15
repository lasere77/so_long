/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:01:32 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/15 19:50:33 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include <fcntl.h>

static char	is_valid_extention(char *name_file)
{
	size_t	len;

	if (!name_file)
		return (0);
	len = ft_strlen(name_file);
	write(1, &name_file[len], 1);
	if (len <= 3)
		return (0);
	if (name_file[len - 1] == 'r' && name_file[len - 2] == 'e'
		&& name_file[len - 3] == 'b' && name_file[len - 4] == '.')
		return (1);
	return (0);
}

char	check_map(int argc, char **argv)
{
	int	fd_map_file;

	if (argc != 2 || !is_valid_extention(argv[1]))
		return (1);
	fd_map_file = open(argv[1], O_RDONLY);
	if (fd_map_file == -1)
		return (1);
	
	return (0);
}
