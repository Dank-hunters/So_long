/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:16:52 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/13 17:44:30 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int collision(t_info *map, int x, int y, int m)
{
	if (x < 0 || y < 0 || x > map->mapx || y > map->mapy - 1)
		return (1);
	if (m == 1)
	{	
 	   if (map->map[y][x] == '1')
        	return (0);
	}
	else if (y + 1 >= 0 && y + 1 < map->mapy && y + 2 >= 0 && y + 2 < map->mapy)
	{
 	   if (map->map[y][x] == '1')
        	return (0);
 	   if (map->map[y + 1][x] == '1')
        	return (0);
 	   if (map->map[y + 2][x] == '1')
        	return (0);
	}
  	return (1);
}

int keypress(int key, t_info *map)
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

int keyrelease(int key, t_info *map)
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
    return(0);

}

void	putaim(t_info *map)
{

			mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[7].img, 70, 70);
}

void    event(t_info *map)
{
    if (map->exit == 1 || (((map->map[map->pos_y][map->pos_x] == 'E' || map->map[map->pos_y + 1][map->pos_x] == 'E' || map->map[map->pos_y + 2][map->pos_x] == 'E') && map->possible == 1) || map->map[map->pos_y][map->pos_x] == 'S' || map->map[map->pos_y + 1][map->pos_x] == 'S' || map->map[map->pos_y + 2][map->pos_x] == 'S' || map->exit == 1))
    {
		//free bails
		exit (0);
    }
    if (map->goleft == 1 && collision(map, map->pos_x - 1, map->pos_y, 2))
        {
            map->nb++;
            map->pos_x -= 1;
        }
    if (map->goright == 1  && collision(map, map->pos_x + 1, map->pos_y, 2))
        {
            map->nb++;
            map->pos_x += 1;
        }
    if (map->down == 1 && collision(map, map->pos_x, map->pos_y + 3, 1))
        {
            map->nb++;
            map->pos_y += 1;
        }
    if (map->up == 1 && collision(map, map->pos_x, map->pos_y - 1, 1))
        {
            map->nb++;
            map->pos_y -= 1;
        }
}
