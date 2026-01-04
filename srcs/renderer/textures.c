/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:30:23 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/04 12:32:29 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

#include <stddef.h>
#include <unistd.h>

static char	check_texture()
{
	if (access(TEXTURE_FLOOR, R_OK) || access(TEXTURE_WALL, R_OK)
		|| access(TEXTURE_EXIT, R_OK) || access(TEXTURE_COLLECTIBLE, R_OK)
		|| access(TEXTURE_PLAYER, R_OK) || access(TEXTURE_ENEMY0, R_OK)
		|| access(TEXTURE_ENEMY1, R_OK) || access(TEXTURE_ENEMY2, R_OK))
		return (1);
	return (0);
}

char	set_texture(t_data *data)
{
	if (check_texture())
		return (1);
	data->floor = mlx_new_image_from_file(data->mlx, TEXTURE_FLOOR, NULL, NULL);
	data->wall = mlx_new_image_from_file(data->mlx, TEXTURE_WALL, NULL, NULL);
	data->exit = mlx_new_image_from_file(data->mlx, TEXTURE_EXIT, NULL, NULL);
	data->collectible = mlx_new_image_from_file(data->mlx,
			TEXTURE_COLLECTIBLE, NULL, NULL);
	data->enemy = mlx_new_image_from_file(data->mlx, TEXTURE_ENEMY0, NULL, NULL);
	data->player.sprite = mlx_new_image_from_file(data->mlx,
			TEXTURE_PLAYER, NULL, NULL);

	return (0);
}