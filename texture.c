/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:21:14 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/08 18:34:30 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	file_to_img(t_info *map)
{
	map->xpm[0].img = mlx_xpm_file_to_image(map->img.mlx, MORTY,
			&map->xpm[0].width, &map->xpm[0].height);
	map->xpm[1].img = mlx_xpm_file_to_image(map->img.mlx, GRASS,
			&map->xpm[1].width, &map->xpm[1].height);
	map->xpm[2].img = mlx_xpm_file_to_image(map->img.mlx, NEWMORTY,
			&map->xpm[2].width, &map->xpm[2].height);
	map->xpm[3].img = mlx_xpm_file_to_image(map->img.mlx, SEED,
			&map->xpm[3].width, &map->xpm[3].height);
	map->xpm[4].img = mlx_xpm_file_to_image(map->img.mlx, WALL, &map->xpm[4].width, &map->xpm[4].height);
	map->xpm[5].img = mlx_xpm_file_to_image(map->img.mlx, MORTYW, &map->xpm[5].width, &map->xpm[5].height);
	map->xpm[6].img = mlx_xpm_file_to_image(map->img.mlx, PORTAL, &map->xpm[6].width, &map->xpm[6].height);
	map->xpm[7].img = mlx_xpm_file_to_image(map->img.mlx, NYMBUS, &map->xpm[7].width, &map->xpm[7].height);
	map->xpm[8].img = mlx_xpm_file_to_image(map->img.mlx, ULOOSE, &map->xpm[8].width, &map->xpm[8].height);
}

int	init_text(t_info *map, int i, int errror)
{
	while (i <= 3)
	{
		if (map->xpm[i].img == NULL)
		{
			while (--i >= 0)
				mlx_destroy_image(map->img.mlx, map->xpm[i].img);
			mlx_destroy_image(map->img.mlx, map->img.img);
			mlx_destroy_window(map->img.mlx, map->img.mlx_win);
			//error(17);
		dprintf(1, "capete\n");
			exit (0);
		}
		else
			map->xpm[i].addr = (int *)mlx_get_data_addr(map->xpm[i].img,
					&map->xpm[i].bpp, &map->xpm[i].line_len,
					&map->xpm[i].endian);
		if (map->xpm[i].addr == NULL)
		{
			errror ++;
			break ;
		}
		i++;
	}
	return (errror);
}
