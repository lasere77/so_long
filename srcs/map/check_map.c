/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:01:32 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/04 18:15:04 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	is_surrounded_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (!i || !map[i + 1])
		{
			while (map[i][j])
			{
				if (map[i][j] != '1' && map[i][j] != '\n')
					return (0);
				j++;
			}
		}
		else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

static void	flood_fill(char **map, size_t x, size_t y)
{
	if (map[y][x] == '1' || map[y][x] == 'Z' ||map[y][x] == '~')
		return ;
	map[y][x] = '~';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	get_entity_position(char **map, char entity, size_t *entity_pos)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == entity)
			{
				entity_pos[0] = x;
				entity_pos[1] = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static char	check_flood_fill(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (ft_check_chrs(map[i], "10Z~\n"))
			return (1);
		i++;
	}
	return (0);
}

char	is_valid_path(char **map)
{
	char	**map_cpy;
	size_t	player_pos[2];
	char	result;

	player_pos[0] = 0;
	player_pos[1] = 0;
	map_cpy = ft_tab_strdup(map);
	if (!map_cpy)
		exit_error(MSG_MALLOC_ERROR, map, FAIL);
	get_entity_position(map, 'P', player_pos);
	if (player_pos[0] == 0 && player_pos[1] == 0)
	{
		ft_free_split(map_cpy);
		exit_error(MSG_ERROR_PLAYER_NOT_FOUND, map, FAIL);
	}
	flood_fill(map_cpy, player_pos[0], player_pos[1]);
	result = check_flood_fill(map_cpy);
	ft_free_split(map_cpy);
	return (!result);
}
