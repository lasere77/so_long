/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:19:37 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/05 15:03:44 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "event.h"

void	display_exit(t_data *data);
void	display_collectible(t_data *data);
void	display_map(t_data *data);
void	display_enemy(t_data *data, int sprite_index);

#endif