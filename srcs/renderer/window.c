/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:59:38 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/04 10:40:52 by mcolin           ###   ########.fr       */
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
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->collectible)
		mlx_destroy_image(data->mlx, data->collectible);
	if (data->enemy)
		mlx_destroy_image(data->mlx, data->enemy);
	if (data->player.sprite)
		mlx_destroy_image(data->mlx, data->player.sprite);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_context(data->mlx);
	ft_free_split(data->map);
}
