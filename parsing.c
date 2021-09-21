/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:34:09 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/21 17:20:51 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

/*
void    free_map(t_info *map)
{
    int i;

    i = 0;
    while (map->map && map->map[i])
    {
        free(map->map[i]);
        map->map[i] = NULL;
        i++;
    }
}*/

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
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				i++;
				map->pos_x = x;
				map->pos_y = y;
			}
			if (map->map[y][x] == 'C')
				map->nb_seed++;
			x++;
		}
		x = 0;
		y++;
	}
//	dprintf(1, "%i et %i\n %i et %i\n", map->pos_x, map->mapx, map->pos_y, map->mapy);;
	if (map->pos_x >= map->mapx - 1 || map->pos_y >= map->mapy - 1)
		return (error(map, 1));
	dprintf(1, "%i\n", map->nb_seed);
	y = 0;
	if (cut2(map, i, y) > 0)
		return (1);
	return (0);
}

void	get_map_size(t_info *map)
{
	int		fd;
	char	*tmp;

	map->mapy = 0;
    fd = open(map->filename, O_RDONLY);
	if (get_next_line(fd, &tmp) == 1)
		map->mapx = (int)ft_strlen(tmp);
	free(tmp);
	while (get_next_line(fd, &tmp) == 1)
	{
		if ((int)ft_strlen(tmp) != map->mapx)
			map->error = 1;
		free(tmp);
		map->mapy++;
	}
	free(tmp);
	close(fd);
	if (map->error == 1)
		error(map, 5);
}

int		get_map(t_info *map)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	get_map_size(map);
	map->map = malloc(sizeof(char *) * (map->mapy + 1)); //protection
    if (map->map == NULL)
		return (error(map, 4));
	fd = open(map->filename, O_RDONLY);
	while (get_next_line(fd, &tmp) == 1)
	{
		map->map[i] = ft_strdup(tmp); //protection
		free(tmp);
		i++;
	}
    map->map[i] = NULL;
	free(tmp);
	close(fd);
	return (1);
}

int	ft_ischar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}


int	fill_flood_map(t_info *map, int x, int y)
{
	if (x < 0 || x > map->mapx - 1 || y < 0 || y > map->mapy - 1)
		return (0);
	if (map->map[y][x] == ' ')
		return (0);
	if (map->map[y][x] == '.' || map->map[y][x] == '1')
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

int parse_map(t_info *map)
{
	if (fill_flood_map(map, map->pos_x, map->pos_y) == 0)
		return (error(map, 6));
	return (0);
}

int parse(t_info *map)
{
    int i;

    i = 0;
    get_map(map);
    while(map->map[i])
    {
		dprintf(1, "%s\n", map->map[i]);
    	i++;
    }
    if (found_pos(map, 0, 0) == 1)
        return(1);
    if (parse_map(map) == 1)
	{
		return (1);
	}
	return (0);

}
