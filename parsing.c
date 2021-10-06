/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:34:09 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/06 17:25:01 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	get_map_size(t_info *map, int fd, char *tmp)
{
	map->mapy = 0;
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		error(map, 60);
	if (get_next_line(fd, &tmp) == -1)
		errors(map, 45);
	else
		map->mapx = (int)ft_strlen(tmp);
	free(tmp);
	while (get_next_line(fd, &tmp) == 1 && ++map->mapy)
	{
		if ((int)ft_strlen(tmp) != map->mapx)
			map->error = 1;
		free(tmp);
	}
	if ((int)ft_strlen(tmp) != 0)
	{
		if ((int)ft_strlen(tmp) != map->mapx)
			map->error = 1;
		else
			map->mapy++;
	}
	free(tmp);
	close(fd);
}

int	get_map(t_info *map, int i, int fd, char *tmp)
{
	get_map_size(map, fd, tmp);
	map->map = malloc(sizeof(char *) * (map->mapy + 1));
	if (map->map == NULL)
		return (error(map, 4));
	fd = open(map->filename, O_RDONLY);
	while (get_next_line(fd, &tmp) == 1)
	{
		map->map[i] = ft_strdup(tmp);
		if (map->map[i] == NULL)
			map->error = 1;
		free(tmp);
		i++;
	}
	if ((int)ft_strlen(tmp) != 0)
	{
		map->map[i] = ft_strdup(tmp);
		if (map->map[i] == NULL)
			map->error = 1;
		i++;
	}
	free(tmp);
	close(fd);
	return (1);
}

int	ft_ischar(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		error(NULL, 42);
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	parse_map(t_info *map)
{
	if (fill_flood_map(map, map->pos_x, map->pos_y) == 0)
		error(map, 9);
	return (0);
}

int	parse(t_info *map)
{
	int	i;

	i = 0;
	get_map(map, 0, 0, 0);
	if (map->error == 1)
		error(map, 5);
	check_rectangle(map);
	if (found_pos(map, 0, 0) == 1)
		return (1);
	if (parse_map(map) == 1)
	{
		return (1);
	}
	return (0);
}
