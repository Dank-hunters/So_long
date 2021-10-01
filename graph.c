/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:52:39 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/30 15:56:11 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	new_ternaire(int condition, int res1, int res2)
{
	if (condition == 0)
		return (res1);
	return (res2);
}

unsigned int	*get_pixel_loc(t_info *map, int x, int y)
{
	char	*dst;

	dst = (char *)map->img.addr + (y * map->img.line_len + x
			* (map->img.bpp / 8));
	return ((unsigned int *)dst);
}

int	creat_img(t_info *map)
{
	map->time++;
	event(map);
	if (map->nb_seed <= map->compt_recup)
		map->possible = 1;
	refresh(map);
	print_map(map, 0, 0);
	return (0);
}

int	init_img(t_info *map)
{
	map->img.mlx = mlx_init();
	map->img.mlx_win = mlx_new_window(map->img.mlx, 1920,
			1080, "So_long");
	if (map->img.mlx_win == NULL)
		return (1);
	map->img.img = mlx_new_image(map->img.mlx, 1920, 1080);
	if (map->img.img == NULL)
		return (1);
	map->img.addr = (int *)mlx_get_data_addr(map->img.img, &map->img.bpp,
			&map->img.line_len, &map->img.endian);
	if (map->img.addr == NULL)
		return (1);
	file_to_img(map);
	if (init_text(map, 0, 0) >= 1)
		return (1);
	return (0);
}

int	graph(t_info *map)
{
	mlx_hook(map->img.mlx_win, 2, 1L << 0, keypress, map);
	mlx_hook(map->img.mlx_win, 3, 1L << 1, keyrelease, map);
	mlx_hook(map->img.mlx_win, 17, 1L << 17, exit_games, map);
	if (mlx_loop_hook(map->img.mlx, &creat_img, map) == 1)
		return (0);
	mlx_loop(map->img.mlx);
	return (0);
}
