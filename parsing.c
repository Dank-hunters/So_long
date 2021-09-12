/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:34:09 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/08 18:08:57 by cguiot           ###   ########lyon.fr   */
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
			//free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (1); //no player
	}
	if (i >= 2)
	{
		while (y < map->mapy)
		{
			//free_line(map->map[y]);
			y++;
		}
		free(map->map);
		return (1); //trop de point de spawn
	}
	return (0);
}

int	found_pos(t_info *map, int i, int y)
{
	int	x;

	x = 0;
	while (map->map[y] != NULL)
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

	map->mapx = 0;
	map->mapy = 0;
    fd = open(map->filename, O_RDONLY);
	while (get_next_line(fd, &tmp) == 1)
	{
		if ((int)ft_strlen(tmp) > map->mapx)
			map->mapx = ft_strlen(tmp);
		free(tmp);
		map->mapy++;
	}
	free(tmp);
	close(fd);
}

int		get_map(t_info *map)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	get_map_size(map);
	map->map = malloc(sizeof(char *) * (map->mapy + 1)); //protection
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

int parse(t_info *map)
{
    int i;

    i = 0;
    get_map(map);
    while(map->map[i])
    {dprintf(1, "%s\n", map->map[i]);
    i++;
    }
    //parse_map(t_info *map);
    if (found_pos(map, 0, 0) == 1)
        return(1); //erreur dans la position
    dprintf(1, "x : %i, y : %i", map->pos_x, map->pos_y);
  /*  map->map = malloc(sizeof(char *) * 6);
    ret = 1;
    fd = open(map->filename, O_RDONLY);
    while (ret == 1)
    {
        ret = get_next_line(fd, &line);
        ft_putstr(line);
       // if (start_parse(map, line) == 1)
        //    free_map(map);    
        map->map[i] = ft_strdup(line);
        //dprintf(1, "%s\n\n\n\n\n\n", map->map[i]);
   
           // free(line);
            //line = NULL;

        i++;
    }
    //map->map[i] = NULL;
*/    return (0);

}
