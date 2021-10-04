/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 19:32:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/04 16:21:13 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_filename(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' \
			|| str[i - 3] != 'b' || str[i - 4] != '.')
	{
		ft_putstr("Error\nWrong map extention");
		exit (0);
	}
	return (0);
}

void	rectif_pos(t_info *map)
{
	if (map->map[map->pos_y + 1][map->pos_x] == '1')
		map->pos_y -= 1;
	if (map->map[map->pos_y + 2][map->pos_x] == '1')
		map->pos_y -= 0;
}

int	main(int ac, char **av)
{
	t_info	map;

	if (ac != 2)
	{
		ft_putstr("Error\nusage : \"./so_long [your map].ber\" \n");
		exit (0);
	}
	check_filename(av[1]);
	init_struct(&map, av);
	if (parse(&map) == 1)
		errors(&map, 101);
	map.sve_x = map.pos_x;
	map.sve_y = map.pos_y;
	rectif_pos(&map);
	if (init_img(&map) == 1)
		exit_games(&map, 0);
	if (graph(&map) == 1)
		exit_games(&map, 0);
	return (0);
}
