/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:49:09 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/19 14:54:03 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include <stdio.h>
#include <unistd.h>

static size_t	get_nb_total_collectible(char **map)
{
	size_t	i;
	size_t	j;
	size_t	result;

	result = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				result++;
			j++;
		}
		i++;
	}
	return (result);
}

static char	init_player(t_player *player, char **map)
{
	size_t	player_pos[2];

	player_pos[0] = 0;
	player_pos[1] = 0;
	get_entity_position(map, 'P', player_pos);
	player->nb_item = get_nb_total_collectible(map);
	if ((player_pos[0] == 0 && player_pos[1] == 0) || !player->nb_item)
		return (1);
	player->x = player_pos[0];
	player->y = player_pos[1];
	return (0);
}

static void display_exit(t_data *data)
{
	size_t	exit_pos[2];

	exit_pos[0] = 0;
	exit_pos[1] = 0;
	get_entity_position(data->map, 'E', exit_pos);
	mlx_put_image_to_window(data->mlx, data->window, data->exit, exit_pos[0] * SPRITE_SIZE, exit_pos[1] * SPRITE_SIZE);
}

static void display_collectible(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->collectible, j * SPRITE_SIZE, i * SPRITE_SIZE);
			j++;
		}
		i++;
	}
}

static void	display_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->wall, j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->floor, j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->floor, j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->floor, j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->floor, j * SPRITE_SIZE, i * SPRITE_SIZE);
			j++;
		}
		i++;
	}
}

static void update(void *param)
{
	t_data	*data;

	data = (t_data*)param;
	if (!data->player.nb_item && data->map[data->player.y][data->player.x] == 'E')
		mlx_loop_end(((t_data*)param)->mlx);
	mlx_clear_window(data->mlx, data->window, (mlx_color){.rgba = 0x334D4DFF});
	display_map(data);
	display_collectible(data);
	display_exit(data);
	mlx_put_image_to_window(data->mlx, data->window, data->player.sprite, data->player.x * SPRITE_SIZE, data->player.y * SPRITE_SIZE);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.map = get_map(argc, argv);
	if (!data.map || !data.map[0])
		return (1);
	init_window(&data);
	if (init_player(&(data.player), data.map))
	{
		destroy_window(&data);
		exit_error(MSG_ERROR_BLAME_THE_DEV, NULL, FAIL);
	}
	mlx_set_fps_goal(data.mlx, 60);
	init_event(&data);

	data.floor = mlx_new_image_from_file(data.mlx, "assets/textures/floor.png", NULL, NULL);
	data.wall = mlx_new_image_from_file(data.mlx, "assets/textures/wall.png", NULL, NULL);
	data.exit = mlx_new_image_from_file(data.mlx, "assets/textures/exit.png", NULL, NULL);
	data.collectible = mlx_new_image_from_file(data.mlx, "assets/textures/collectible.png", NULL, NULL);
	data.player.sprite = mlx_new_image_from_file(data.mlx, "assets/textures/player.png", NULL, NULL);

	mlx_add_loop_hook(data.mlx, update, &data);
	mlx_loop(data.mlx);

	destroy_window(&data);
	return (0);
}
