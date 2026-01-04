/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:27:25 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/04 12:54:59 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

static char	is_valid_extention(char *name_file)
{
	size_t	len;

	if (!name_file)
		return (0);
	len = ft_strlen(name_file);
	write(1, &name_file[len], 1);
	if (len <= 3)
		return (0);
	return (name_file[len - 1] == 'r' && name_file[len - 2] == 'e'
		&& name_file[len - 3] == 'b' && name_file[len - 4] == '.');
}

static char	check_map_shape(char **map)
{
	size_t	nb_line;
	size_t	len_line;

	len_line = ft_strlen(map[0]);
	nb_line = 0;
	while (map[nb_line])
	{
		if (len_line != ft_strlen(map[nb_line]) + !map[nb_line + 1])
			return (1);
		len_line = ft_strlen(map[nb_line]);
		nb_line++;
	}
	if (len_line > 50 || nb_line > 50)
		return (1);
	return (0);
}

static char	check_map_content(char **map)
{
	size_t	i;
	size_t	j;
	size_t	nb_char[3];

	nb_char[0] = 0;
	nb_char[1] = 0;
	nb_char[2] = 0;
	i = 0;
	while (map[i])
	{
		if (ft_check_chrs(map[i], CHAR_MAP_ACCEPT))
			return (1);
		j = 0;
		while (map[i][j])
		{
			nb_char[0] += map[i][j] == 'C';
			nb_char[1] += map[i][j] == 'E';
			nb_char[2] += map[i][j] == 'P';
			j++;
		}
		i++;
	}
	return (nb_char[0] == 0 || nb_char[1] != 1 || nb_char[2] != 1);
}

static char	**set_map(int fd, ssize_t map_line)
{
	char	**map;
	size_t	i;

	map = malloc(sizeof(char *) * (map_line + 1));
	if (!map || map_line <= 0)
	{
		close(fd);
		exit_error(MSG_MALLOC_ERROR, map, FAIL);
	}
	i = 0;
	while (i < (size_t)map_line)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			close(fd);
			exit_error(MSG_MALLOC_ERROR, map, FAIL);
		}
		i++;
	}
	map[i] = get_next_line(fd);
	return (map);
}

char	**get_map(int argc, char **argv)
{
	int		fd_map_file;
	char	**map;

	if (argc != 2)
		exit_error(MSG_INVALID_FMT, NULL, FAIL);
	if (!is_valid_extention(argv[1]))
		exit_error(MSG_INVALID_EXTENTION, NULL, FAIL);
	fd_map_file = open(argv[1], O_RDONLY);
	if (fd_map_file == -1)
		exit_error(MSG_INVALIDE_PATH, NULL, FAIL);
	map = set_map(fd_map_file, get_number_line_file(argv[1]));
	close(fd_map_file);
	if (!map)
		exit_error(MSG_EMPTY_FILE, map, FAIL);
	if (check_map_shape(map))
		exit_error(MSG_RECTANGULAR_MAP, map, FAIL);
	if (check_map_content(map))
		exit_error(MSG_ERROR_MAP_CONTENT, map, FAIL);
	if (!is_surrounded_map(map))
		exit_error(MSG_SURROU_MAP, map, FAIL);
	if (!is_valid_path(map))
		exit_error(MSG_VALID_PATH, map, FAIL);
	return (map);
}
