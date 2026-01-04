/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:30:23 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/04 14:08:27 by mcolin           ###   ########.fr       */
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

void	enemy_animation(t_data *data)
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
	if (data->enemy)
		mlx_destroy_image(data->mlx, data->enemy);
	if (j == 0)
		data->enemy = mlx_new_image_from_file(data->mlx, TEXTURE_ENEMY0, NULL, NULL);
	else if (j == 1)
		data->enemy = mlx_new_image_from_file(data->mlx, TEXTURE_ENEMY1, NULL, NULL);
	else if (j == 2)
		data->enemy = mlx_new_image_from_file(data->mlx, TEXTURE_ENEMY2, NULL, NULL);
	i++;
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