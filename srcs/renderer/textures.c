/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:30:23 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/05 15:13:46 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "mlx.h"
#include "window.h"

#include <stdio.h>

#include <stddef.h>
#include <unistd.h>
#include <sys/time.h>

static char	check_texture()
{
	if (access(TEXTURE_FLOOR, R_OK) || access(TEXTURE_WALL, R_OK)
		|| access(TEXTURE_EXIT, R_OK) || access(TEXTURE_COLLECTIBLE, R_OK)
		|| access(TEXTURE_PLAYER, R_OK) || access(TEXTURE_ENEMY0, R_OK)
		|| access(TEXTURE_ENEMY1, R_OK) || access(TEXTURE_ENEMY2, R_OK))
		return (1);
	return (0);
}

int	enemy_animation()
{
	static size_t			i = 0;
	static unsigned char	j = 0;

	if (i > FPS_GOAl / 2)
	{
		j++;
		i = 0;
	}
	if (j > NB_TEXTURE_ENEMY - 1)
		j = 0;
	i++;
	if (j == 0)
		return (sprite_enemy0);
	else if (j == 1)
		return (sprite_enemy1);
	else if (j == 2)
		return (sprite_enemy2);
	return (sprite_enemy0);
}

char	set_texture(t_data *data)
{
	if (check_texture())
		return (1);
	data->sprites[sprite_floor] = mlx_new_image_from_file(data->mlx, TEXTURE_FLOOR, NULL, NULL);
	data->sprites[sprite_wall] = mlx_new_image_from_file(data->mlx, TEXTURE_WALL, NULL, NULL);
	data->sprites[sprite_exit] = mlx_new_image_from_file(data->mlx, TEXTURE_EXIT, NULL, NULL);
	data->sprites[sprite_collectible] = mlx_new_image_from_file(data->mlx,
			TEXTURE_COLLECTIBLE, NULL, NULL);
	data->sprites[sprite_enemy0] = mlx_new_image_from_file(data->mlx, TEXTURE_ENEMY0, NULL, NULL);
	data->sprites[sprite_enemy1] = mlx_new_image_from_file(data->mlx, TEXTURE_ENEMY1, NULL, NULL);
	data->sprites[sprite_enemy2] = mlx_new_image_from_file(data->mlx, TEXTURE_ENEMY2, NULL, NULL);
	data->sprites[sprite_player] = mlx_new_image_from_file(data->mlx,
			TEXTURE_PLAYER, NULL, NULL);

	return (0);
}