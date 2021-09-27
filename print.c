/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:06:41 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/27 16:11:09 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	print_map(t_info *map, int x, int y)
{
	int	prx;
	int	pry;

	y = new_ternaire(map->pos_y - 15 < 0, map->pos_y - 15, 0);
	while (y >= 0 && y <= map->mapy && y < map->pos_y + 13)
	{
		pry = (Y_WIN * 0.5) + 64 * (y - map->pos_y);
		x = new_ternaire(map->pos_x - 17 < 0, map->pos_x - 17, 0);
		while (x >= 0 && x < map->mapx && x < map->pos_x + 15)
		{
			prx = (X_WIN * 0.5) - (64 * (map->pos_x - x));
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(map->img.mlx, map->img.mlx_win,
					map->xpm[4].img, prx, pry);
			else
				mlx_put_image_to_window(map->img.mlx, map->img.mlx_win,
					map->xpm[1].img, prx, pry);
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(map->img.mlx, map->img.mlx_win,
					map->xpm[3].img, prx, pry);
			x++;
		}
		y++;
	}
	print_sprite(map);
	print_ennemy(map);
}

void	print_ennemy(t_info *map)
{
	int	x;
	int	y;
	int	prx;
	int	pry;

	y = new_ternaire(map->pos_y - 15 < 0, map->pos_y - 15, -1);
	while (++y <= map->mapy && y < map->pos_y + 13)
	{
		pry = (Y_WIN * 0.5) + 64 * (y - map->pos_y);
		x = new_ternaire(map->pos_x - 17 < 0, map->pos_x - 17, -1);
		while (++x < map->mapx && x < map->pos_x + 15)
		{
			prx = (X_WIN * 0.5) - 64 * (map->pos_x - x);
			if (map->map[y][x] == 'S')
				mlx_put_image_to_window(map->img.mlx, map->img.mlx_win,
					map->xpm[7].img, prx, pry);
		}
	}
}

void	print_sprite(t_info *map)
{
	int	x;
	int	y;

	x = X_WIN * 0.5;
	y = Y_WIN * 0.5;
	if ((map->nb % 3) == 0)
		mlx_put_image_to_window(map->img.mlx, map->img.mlx_win,
			map->xpm[0].img, x, y);
	else
		mlx_put_image_to_window(map->img.mlx, map->img.mlx_win,
			map->xpm[5].img, x, y);
	print_exit(map);
	somthing_happend(map);
	print_moov(map);
}

void	print_exit(t_info *map)
{
	int	x;
	int	y;
	int	prx;
	int	pry;

	if (map->compt_recup >= map->nb_seed)
	{
		y = new_ternaire(map->pos_y - 15 < 0, map->pos_y - 15, -1);
		while (++y < map->mapy && y < map->pos_y + 13)
		{
			pry = (Y_WIN * 0.5) + 64 * (y - map->pos_y);
			x = new_ternaire(map->pos_x - 17 < 0, map->pos_x - 17, -1);
			while (++x < map->mapx && x < map->pos_x + 15)
			{
				prx = (X_WIN * 0.5) - 64 * (map->pos_x - x);
				if (map->map[y][x] == 'E')
					mlx_put_image_to_window(map->img.mlx, map->img.mlx_win,
						map->xpm[6].img, prx, pry);
			}
		}
	}
}
