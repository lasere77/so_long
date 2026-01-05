/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:31:05 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/05 17:57:21 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "window.h"

# define TEXTURE_FLOOR "assets/textures/floor.png"
# define TEXTURE_WALL "assets/textures/wall.png"
# define TEXTURE_EXIT "assets/textures/exit.png"
# define TEXTURE_COLLECTIBLE "assets/textures/collectible.png"
# define TEXTURE_PLAYER "assets/textures/player/player.png"

# define TEXTURE_ENEMY0 "assets/textures/enemy/enemy0.png"
# define TEXTURE_ENEMY1 "assets/textures/enemy/enemy1.png"
# define TEXTURE_ENEMY2 "assets/textures/enemy/enemy2.png"

/**
 * @warning: This table must follow the same order as g_index_textures
 * located in the textures.c file.
 */
typedef enum e_sprite
{
	sprite_floor,
	sprite_wall,
	sprite_exit,
	sprite_collectible,
	sprite_player,
	sprite_enemy0,
	sprite_enemy1,
	sprite_enemy2,
}	t_sprite;

char	set_texture(t_data *data);
int		enemy_animation();

#endif