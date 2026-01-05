/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:59:38 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/05 15:14:29 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

size_t	get_ideal_window_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	init_window(t_data *data)
{
	mlx_window_create_info	info;

	data->mlx = mlx_init();
	ft_bzero(&info, sizeof(mlx_window_create_info));
	info.title = "so_longggggggggggggggggg";
	info.width = 1920;
	info.height = 1080;
	data->width = info.width;
	data->height = info.height;
	data->window = mlx_new_window(data->mlx, &info);
}

void	destroy_window(t_data *data)
{
	if (data->sprites[sprite_floor])
		mlx_destroy_image(data->mlx, data->sprites[sprite_floor]);
	if (data->sprites[sprite_wall])
		mlx_destroy_image(data->mlx, data->sprites[sprite_wall]);
	if (data->sprites[sprite_exit])
		mlx_destroy_image(data->mlx, data->sprites[sprite_exit]);
	if (data->sprites[sprite_collectible])
		mlx_destroy_image(data->mlx, data->sprites[sprite_collectible]);
	if (data->sprites[sprite_enemy0])
		mlx_destroy_image(data->mlx, data->sprites[sprite_enemy0]);
	if (data->sprites[sprite_enemy1])
		mlx_destroy_image(data->mlx, data->sprites[sprite_enemy1]);
	if (data->sprites[sprite_enemy2])
		mlx_destroy_image(data->mlx, data->sprites[sprite_enemy2]);
	if (data->sprites[sprite_player])
		mlx_destroy_image(data->mlx, data->sprites[sprite_player]);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_context(data->mlx);
	ft_free_split(data->map);
}
