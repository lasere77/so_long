/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:49:09 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/15 12:02:36 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (check_map(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}