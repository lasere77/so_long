/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:59:38 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/19 12:01:41 by mcolin           ###   ########.fr       */
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
	info.width = WINDOW_SIZE_PER_SPRITE * (ft_strlen(data->map[0]) - 1);
	info.height = WINDOW_SIZE_PER_SPRITE * get_ideal_window_height(data->map);
	data->window = mlx_new_window(data->mlx, &info);	
}

void	destroy_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->player.sprite);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_context(data->mlx);
	ft_free_split(data->map);
}