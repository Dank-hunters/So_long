/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:16:52 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/21 17:21:04 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	somthing_happend(t_info *map)
{
	char	*obj;
	char	*objs;

	objs = ft_itoa(map->nb_seed);
	obj = NULL;
	seed_hitbox(map);
	obj = ft_itoa(map->compt_recup);
	mlx_put_image_to_window(map->img.mlx, map->img.mlx_win,
		map->xpm[3].img, 40, 10);
	if (obj == NULL)
		mlx_string_put(map->img.mlx, map->img.mlx_win, 10, 64, 0xAAAAAA, "0 :");
	else
	{
		mlx_string_put(map->img.mlx, map->img.mlx_win, 10, 64, 0xAAAAAA, obj);
		mlx_string_put(map->img.mlx, map->img.mlx_win, 20, 64, 0xAAAAAA, "/");
		mlx_string_put(map->img.mlx, map->img.mlx_win, 30, 64, 0xAAAAAA, objs);
	}
	free(obj);
	free(objs);
}

int	collision(t_info *map, int x, int y, int m)
{
	m = 0;
	if (x < 0 || y < 0 || x > map->mapx || y > map->mapy - 1)
		return (1);	
	if (map->map[y][x] == '1')
		return (0);
	else if (y + 1 >= 0 && y + 1 < map->mapy && y + 1 >= 0 && y + 1 < map->mapy)
	{
		if (map->map[y][x] == '1')
			return (0);
		if (map->map[y + 1][x] == '1')
			return (0);
	}
	return (1);
}

int	keypress(int key, t_info *map)
{
	map->moov++;
	if (key == EXIT_WIN)
		map->exit = 1;
	if (key == KEY_LEFT)
		map->goleft = 1;
	if (key == KEY_RIGHT)
		map->goright = 1;
	if (key == KEY_UP)
		map->up = 1;
	if (key == KEY_DOWN)
		map->down = 1;
	return (0);
}

int	keyrelease(int key, t_info *map)
{
	if (key == EXIT_WIN)
		map->exit = 0;
	if (key == KEY_LEFT)
		map->goleft = 0;
	if (key == KEY_RIGHT)
		map->goright = 0;
	if (key == KEY_UP)
		map->up = 0;
	if (key == KEY_DOWN)
		map->down = 0;
	return (0);
}

void	event(t_info *map)
{
	if (map->exit == 1 || (((map->map[map->pos_y][map->pos_x] == 'E'
				|| map->map[map->pos_y + 1][map->pos_x] == 'E')
			&& map->possible == 1) || map->map[map->pos_y][map->pos_x] == 'S'
			|| map->map[map->pos_y + 1][map->pos_x] == 'S'
			|| map->exit == 1))
		exit_games(map);
	if (map->goleft == 1 || map->goright == 1 || map->down == 1 || map->up == 1)
		map->nb++;
	if (map->goleft == 1 && collision(map, map->pos_x - 1, map->pos_y, 2))
		map->pos_x -= 1;
	if (map->goright == 1 && collision(map, map->pos_x + 1, map->pos_y, 2))
		map->pos_x += 1;
	if (map->down == 1 && collision(map, map->pos_x, map->pos_y + 2, 1))
		map->pos_y += 1;
	if (map->up == 1 && collision(map, map->pos_x, map->pos_y - 1, 1))
		map->pos_y -= 1;
}
