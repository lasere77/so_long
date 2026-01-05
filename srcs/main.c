/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:49:09 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/05 19:20:34 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "textures.h"
#include "mlx.h"
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

static void	init_player(t_player *player, char **map)
{
	size_t	player_pos[2];

	player_pos[0] = 0;
	player_pos[1] = 0;
	get_entity_position(map, 'P', player_pos);
	player->nb_item = get_nb_total_collectible(map);
	player->x = player_pos[0];
	player->y = player_pos[1];
}

static void	update(void *param)
{
	t_data	*data;
	char	*str;

	data = (t_data *)param;
	if (is_player_ending_game(data))
		mlx_loop_end(((t_data *)param)->mlx);
	mlx_clear_window(data->mlx, data->window, (mlx_color){.rgba = 0});
	display_map(data);
	display_collectible(data);
	display_exit(data);
	display_enemy(data, enemy_animation());
	str = ft_itoa(data->player.nb_move);
	if (str)
		mlx_string_put(data->mlx, data->window, 20, 20,
			(mlx_color){.rgba = 0x0020FFFF}, str);
	free(str);
	mlx_put_image_to_window(data->mlx, data->window,
		data->sprites[sprite_player], data->width / 2, data->height / 2);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.map = get_map(argc, argv);
	if (!data.map || !data.map[0])
	{
		free(data.map);
		return (1);
	}
	init_window(&data);
	mlx_set_fps_goal(data.mlx, FPS_GOAL);
	if (set_texture(&data))
	{
		destroy_window(&data);
		exit_error(MSG_ERROR_TEXTURES_NOT_FOUND, NULL, FAIL);
	}
	init_event(&data);
	init_player(&(data.player), data.map);
	mlx_set_font_scale(data.mlx, "default", 16.f);
	mlx_add_loop_hook(data.mlx, update, &data);
	mlx_loop(data.mlx);
	destroy_window(&data);
	return (0);
}
