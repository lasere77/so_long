/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:31:05 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/05 15:01:47 by mcolin           ###   ########.fr       */
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

char	set_texture(t_data *data);
int		enemy_animation();

#endif