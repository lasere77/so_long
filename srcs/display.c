/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:19:14 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/03 16:24:46 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_exit(t_data *data)
{
	size_t	exit_pos[2];
	int		sprite_offset_x;
	int		sprite_offset_y;

	exit_pos[0] = 0;
	exit_pos[1] = 0;
	get_entity_position(data->map, 'E', exit_pos);
	sprite_offset_x = data->width / 2 - data->player.x * SPRITE_SIZE
		+ exit_pos[0] * SPRITE_SIZE;
	sprite_offset_y = data->height / 2 - data->player.y * SPRITE_SIZE
		+ exit_pos[1] * SPRITE_SIZE;
	mlx_put_image_to_window(data->mlx, data->window, data->exit,
		sprite_offset_x, sprite_offset_y);
}

void	display_collectible(t_data *data)
{
	size_t	i;
	size_t	j;
	int		sprite_offset_x;
	int		sprite_offset_y;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			sprite_offset_x = data->width / 2 - data->player.x * SPRITE_SIZE
				+ j * SPRITE_SIZE;
			sprite_offset_y = data->height / 2 - data->player.y * SPRITE_SIZE
				+ i * SPRITE_SIZE;
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window,
					data->collectible, sprite_offset_x, sprite_offset_y);
			j++;
		}
		i++;
	}
}

static void	tkt(char c, t_data *data, int sprite_offset_x, int sprite_offset_y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->wall,
			sprite_offset_x, sprite_offset_y);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->window, data->floor,
			sprite_offset_x, sprite_offset_y);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->window, data->floor,
			sprite_offset_x, sprite_offset_y);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->floor,
			sprite_offset_x, sprite_offset_y);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->window, data->floor,
			sprite_offset_x, sprite_offset_y);
}

void	display_map(t_data *data)
{
	size_t	i;
	size_t	j;
	int		sprite_offset_x;
	int		sprite_offset_y;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			sprite_offset_x = data->width / 2 - data->player.x * SPRITE_SIZE
				+ j * SPRITE_SIZE;
			sprite_offset_y = data->height / 2 - data->player.y * SPRITE_SIZE
				+ i * SPRITE_SIZE;
			tkt(data->map[i][j], data, sprite_offset_x, sprite_offset_y);
			j++;
		}
		i++;
	}
}
