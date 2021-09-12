/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 19:32:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/24 20:34:49 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(int ac, char **av)
{
	t_info map;
	
	init_struct(&map, av);
	if (ac != 2)
	{
		ft_putstr("usage : \"./so_long [your map].ber\" \n");
	}
	if (parse(&map) == 1)
	{
			exit(0);
	}
	map.sve_x = map.pos_x;
	map.sve_y = map.pos_y;
	if (init_img(&map) == 1)
	{
		dprintf(1, "ici");
		//free_map;
		//exit;
	}
	dprintf(1, "la?");
	if (graph(&map) == 1)
	{
		//free exit
	}
	return (0);
}
