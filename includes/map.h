/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:56:32 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/03 17:55:13 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define FAIL EXIT_FAILURE

# define MSG_INVALID_FMT "Error\nuse the format: ./so_long <map_path>\n"

# define MSG_INVALID_EXTENTION "Error\nthe file must be a .ber file.\n"

# define MSG_INVALIDE_PATH "Error\ninvalid file path.\n"

# define MSG_EMPTY_FILE "Error\nempty map file...\n"

# define MSG_RECTANGULAR_MAP "Error\nThe map must be rectangular.\n\
with a maximum dimension of: 50x50\n"

# define MSG_SURROU_MAP "Error\nThe map must be surrounded by walls.\n"

# define MSG_VALID_PATH "Error\nThe map do not have a valid path.\n"

# define MSG_ERROR_MAP_CONTENT "Error\ninvalid map content, \
map must contain 1 exit, 1 starting position and at least 1 collectible\n"

# define MSG_ERROR_PLAYER_NOT_FOUND "Error\nIf you receive this error message, \
you can open a ticket at: https://github.com/lasere77/so_long\n"

# define MSG_MALLOC_ERROR "Error\nMemory failure... \
Please check that your pc is not on fire.\n"

# define MSG_ERROR_TEXTURES_NOT_FOUND "Error\ntexture not found...\n"

# include "error.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

char	**get_map(int argc, char **argv);

char	is_surrounded_map(char **map);
char	is_valid_path(char **map);
void	get_entity_position(char **map, char entity, size_t *entity_pos);

#endif