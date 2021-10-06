/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:35:33 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/06 17:26:10 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	seed_hitbox(t_info *map)
{
	int	i;

	i = 0;
	while (i < 2 && map->pos_y + i < map->mapy - 1)
	{
		if (map->map[map->pos_y + i][map->pos_x] == 'C')
		{
			map->compt_recup ++;
			map->map[map->pos_y + i][map->pos_x] = '0';
		}
		i++;
	}
}

void	init_struct(t_info *map, char **av)
{
	map->filename = av[1];
	map->compt_recup = 0;
	map->down = 0;
	map->exit = 0;
	map->goleft = 0;
	map->goright = 0;
	map->pos_x = 0;
	map->pos_y = 0;
	map->up = 0;
	map->nb = 0;
	map->compt_recup = 0;
	map->moov = 0;
	map->nb_seed = 0;
	map->possible = 0;
	map->time = 0;
	map->max = 0;
	map->error = 0;
}

void	*free_line(char *str)
{
	if (str != NULL)
		free(str);
	str = NULL;
	return (str);
}

int	exit_games(t_info *map, int cdt)
{
	if (cdt == 1)
		ft_putstr("Error\ntoo much moovs");
	if (cdt > 150)
		ft_putstr("Error\nXPM got a probleme");
	free_map(map, 1);
	exit (0);
}
