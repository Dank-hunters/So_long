/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:11:24 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/01 18:54:45 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	error(t_info *map, int i)
{
	ft_putstr("Error\n");
	if (i == 1)
		ft_putstr("Bad spawn point.");
	if (i == 2)
		ft_putstr("No spawn point");
	if (i == 3)
		ft_putstr("Too much player in game");
	if (i == 4)
		ft_putstr("Malloc error");
	if (i == 5)
		ft_putstr("The map MUST BE rectangular");
	if (i == 6)
		ft_putstr("Wrong caracteres in map");
	if (i == 8)
		ft_putstr("Missing caractere");
	if (i == 9)
		ft_putstr("Map not close");
	if (i == 42)
		ft_putstr("Need Map to continue");
	if (i == 45)
		ft_putstr("Can't read map");
	if (i == 60)
		ft_putstr("Wrong file descriptor");
	if (i > 5 && i < 30)
		freed(map);
	exit(0);
	return (1);
}

void	freed(t_info *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y <= map->mapy)
	{
		free(map->map[y]);
		y++;
	}
	free(map->map);
}

void	free_map(t_info *map, int cdt)
{
	int	i;

	i = 0;
	while (i <= map->mapy)
	{
		map->map[i] = free_line(map->map[i]);
		i++;
	}
	free(map->map);
	if (cdt == 1)
	{
		mlx_destroy_image(map->img.mlx, map->img.img);
		mlx_destroy_window(map->img.mlx, map->img.mlx_win);
	}
}

int	fill_flood_map(t_info *map, int x, int y)
{
	if (x < 0 || x > map->mapx || y < 0 || y > map->mapy)
		return (0);
	if (map->map[y][x] == ' ')
		return (0);
	if (map->map[y][x] == '.' || map->map[y][x] == '1' ||
		   	map->map[y][x] == 'C' || map->map[y][x] == 'E')
		return (1);
	if (ft_ischar("0", map->map[y][x]) == 1)
		map->map[y][x] = '.';
	if (fill_flood_map(map, x + 1, y) == 1
		&& fill_flood_map(map, x - 1, y) == 1
		&& fill_flood_map(map, x, y + 1) == 1
		&& fill_flood_map(map, x, y - 1) == 1)
		return (1);
	else
		return (0);
}
