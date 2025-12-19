/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:49:16 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/19 15:11:54 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stddef.h>
# include "mlx.h"
# include "libft.h"

# define SPRITE_SIZE 16
# define WINDOW_SIZE_PER_SPRITE 16

typedef struct s_player
{
	mlx_image	sprite;
	size_t		x;
	size_t		y;
	size_t		nb_item;
	int			nb_move;
}				t_player;

typedef struct s_data
{
	mlx_context	mlx;
	mlx_window	window;
	mlx_image	floor;
	mlx_image	wall;
	mlx_image	collectible;
	mlx_image	exit;
	t_player	player;
	char		**map;
}				t_data;

size_t	get_ideal_window_height(char **map);
void	init_window(t_data *data);
void	destroy_window(t_data *data);

#endif