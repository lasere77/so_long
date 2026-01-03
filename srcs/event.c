/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:19:41 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/03 15:06:26 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	check_player_move(t_data *data, char is_x, char move)
{
	char	next_pos;

	next_pos = data->map[data->player.y + move - (is_x * move)]
	[data->player.x + (is_x * move)];
	if (next_pos != '1')
	{
		if (is_x)
			data->player.x += move;
		else
			data->player.y += move;
		data->player.nb_move++;
		ft_printf("%d\n", data->player.nb_move);
	}
	if (next_pos == 'C')
	{
		data->player.nb_item--;
		data->map[data->player.y][data->player.x] = '0';
	}
}

static void	key_hook(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC)
		mlx_loop_end(data->mlx);
	else if (key == a)
		check_player_move(data, 1, -1);
	else if (key == d)
		check_player_move(data, 1, 1);
	else if (key == w)
		check_player_move(data, 0, -1);
	else if (key == s)
		check_player_move(data, 0, 1);
}

static void	window_hook(int event, void *param)
{
	if (!event)
		mlx_loop_end(((t_data *)param)->mlx);
}

void	init_event(t_data *data)
{
	mlx_on_event(data->mlx, data->window,
		MLX_KEYDOWN, key_hook, data);
	mlx_on_event(data->mlx, data->window,
		MLX_WINDOW_EVENT, window_hook, data);
}
