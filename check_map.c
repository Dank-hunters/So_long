/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:18:42 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/28 18:21:47 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	check_char(t_info *map)
{
	int		y;
	t_sp	nb;

	nb.e = 0;
	nb.c = 0;
	nb.p = 0;
	y = 0;
	while (y <= map->mapy)
	{
		if (ft_ischar(map->map[y], 'E') == 1)
			nb.e = 1;
		if (ft_ischar(map->map[y], 'P') == 1)
			nb.p = 1;
		if (ft_ischar(map->map[y], 'C') == 1)
			nb.c = 1;
		y++;
	}
	if ((nb.c + nb.p + nb.e) != 3)
		error(map, 8);
}

void	check_rectangle(t_info *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->mapy - 1)
	{
		x = 0;
		while (x < map->mapx - 1)
		{
			if (ft_ischar("10PCES", map->map[y][x]) != 1)
				error(map, 6);
			x++;
		}
		y++;
	}
	check_char(map);
}

int	cut2(t_info *map, int i, int y)
{
	if (i == 0)
	{
		while (y < map->mapy)
		{
			free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (error(map, 2));
	}
	if (i >= 2)
	{
		while (y < map->mapy)
		{
			free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (error(map, 3));
	}
	return (0);
}

int	found_pos(t_info *map, int i, int y)
{
	int	x;

	x = 0;
	while (y < map->mapy || map->map[y] != NULL)
	{
		while (x++ < map->mapx)
		{
			if (map->map[y][x] == 'P')
			{
				i++;
				map->pos_x = x;
				map->pos_y = y;
			}
			if (map->map[y][x] == 'C')
				map->nb_seed++;
		}
		x = 0;
		y++;
	}
	if (map->pos_x >= map->mapx - 1 || map->pos_y >= map->mapy)
		return (error(map, 1));
	y = 0;
	if (cut2(map, i, y) > 0)
		return (1);
	return (0);
}
