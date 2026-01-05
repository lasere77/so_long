/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:30:23 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/05 18:08:31 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "mlx.h"
#include "window.h"

#include <stdio.h>

#include <stddef.h>
#include <unistd.h>
#include <sys/time.h>

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

/**
 * @warning: This table must follow the same order as that of e_sprite
 * located in the textures.h file.
 */
static const char *g_index_textures[] = {
	TEXTURE_FLOOR,
	TEXTURE_WALL,
	TEXTURE_EXIT,
	TEXTURE_COLLECTIBLE,
	TEXTURE_PLAYER,
	TEXTURE_ENEMY0,
	TEXTURE_ENEMY1,
	TEXTURE_ENEMY2
};

char	set_texture(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < NB_TOTAL_TEXTRE)
	{
		data->sprites[i] = mlx_new_image_from_file(data->mlx, (char *)g_index_textures[i], NULL, NULL);
		if (!data->sprites[i])
			return (1);
		i++;
	}
	return (0);
}
