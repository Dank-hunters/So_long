/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:09:18 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/21 17:20:59 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	refresh(t_info *map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < Y_WIN)
	{
		while (x < X_WIN)
		{
			if (x < X_WIN && y < Y_WIN)
				*get_pixel_loc(map, x, y) = 0x012540;
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->img.img, 0, 0);
}

void	print_moov(t_info *map)
{
	char	*moov;

	moov = ft_itoa(map->moov);
	mlx_string_put(map->img.mlx, map->img.mlx_win,
		   0, 150, 0xAAAAAA, "You do :");
	mlx_string_put(map->img.mlx, map->img.mlx_win, 10, 160, 0xAAAAAA, moov);
	mlx_string_put(map->img.mlx, map->img.mlx_win,
		   0, 170, 0xAAAAAA, "moovement");
	if (map->moov > 0)
		mlx_string_put(map->img.mlx, map->img.mlx_win, 63, 170, 0xAAAAAA, "s");
	free(moov);
}
