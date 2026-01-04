/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:21:47 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/04 12:43:46 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "window.h" 
# include "map.h"
# include "ft_printf.h"

typedef enum e_key
{
	ESC = 41,
	h = 11,
	c = 6,
	q = 20,
	a = 4,
	w = 26,
	d = 7,
	s = 22
}	t_key;

void	init_event(t_data *data);
char	is_player_ending_game(t_data *data);

#endif