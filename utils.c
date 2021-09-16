/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:35:33 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/15 16:59:11 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void    init_struct(t_info *map, char **av)
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
}
