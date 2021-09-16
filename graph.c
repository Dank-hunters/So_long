/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:52:39 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/16 16:14:07 by cguiot           ###   ########lyon.fr   */
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

void	somthing_happend(t_info *map)
{
	char *obj;
	char *objs;
	int i;

	i  = 0;
	objs = ft_itoa(map->nb_seed);
	obj = NULL;
	while(i < 3 && map->pos_y + i < map->mapy - 1)
	{
		if (map->map[map->pos_y + i][map->pos_x] == 'C')
		{
			map->compt_recup ++;
			map->map[map->pos_y + i][map->pos_x] = '0';
		}
		i++;
	}
	obj = ft_itoa(map->compt_recup);
	mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[3].img, 40, 10);
	if (obj == NULL)
		mlx_string_put(map->img.mlx, map->img.mlx_win, 10, 64, 0xAAAAAA, "0 :");
	else 
	{
		mlx_string_put(map->img.mlx, map->img.mlx_win, 10, 64, 0xAAAAAA, obj);
		mlx_string_put(map->img.mlx, map->img.mlx_win, 20, 64, 0xAAAAAA, "/");
		mlx_string_put(map->img.mlx, map->img.mlx_win, 30, 64, 0xAAAAAA, objs);
	}
	free(obj);
}

void refresh(t_info *map)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (y < Y_WIN)
	{
		while(x < X_WIN)
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
	char *moov;

	moov = ft_itoa(map->moov);
	mlx_string_put(map->img.mlx, map->img.mlx_win, 0, 150, 0xAAAAAA, "You do :");
	mlx_string_put(map->img.mlx, map->img.mlx_win, 10, 160, 0xAAAAAA, moov);
	mlx_string_put(map->img.mlx, map->img.mlx_win, 0, 170, 0xAAAAAA, "moovement");
	if (map->moov > 0)
		mlx_string_put(map->img.mlx, map->img.mlx_win, 63, 170, 0xAAAAAA, "s");
	free(moov);

}

void	print_exit(t_info *map)
{
	int	x;
	int	y;
	int	prx;
	int pry;

	if (map->compt_recup >= map->nb_seed)
	{
		y = new_ternaire(map->pos_y - 15 < 0 , map->pos_y - 15, -1);
		while (++y < map->mapy && y < map->pos_y + 13)
		{
			pry = (Y_WIN * 0.5) + 64 * (y - map->pos_y);
			x = new_ternaire(map->pos_x - 17 < 0 , map->pos_x - 17, -1);
			while (++x < map->mapx && x < map->pos_x + 15)
			{
				prx = (X_WIN * 0.5) - 64 * (map->pos_x - x);
				if (map->map[y][x] == 'E')
					mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[6].img, prx, pry);
			}

		}
	}
}
void	print_sprite(t_info *map)
{
	int x;
	int y;

	x = X_WIN * 0.5;
	y = Y_WIN * 0.5;
	if ((map->nb % 3) == 0)
		mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[0].img, x, y);
	else
		mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[5].img, x, y);
	print_exit(map);
	somthing_happend(map);
	print_moov(map);

}

void    print_ennemy(t_info *map)
{
	int x;
	int y;
	int prx;
	int pry;
	int max;

	max = 0;
	y = new_ternaire(map->pos_y - 15 < 0 , map->pos_y - 15, -1);
	while (++y < map->mapy && y < map->pos_y + 13)
	{
		pry = (Y_WIN * 0.5) + 64 * (y - map->pos_y);
		x = new_ternaire(map->pos_x - 17 < 0 , map->pos_x - 17, -1);
		while (++x < map->mapx && x < map->pos_x + 15)
		{
			prx = (X_WIN * 0.5) - 64 * (map->pos_x - x);
			if (map->map[y][x] == 'S')
			{	
				mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[7].img, prx, pry);
			}
		}
	}

}
void	ennemy_fuck_me(t_info *map)
{
	int y = 0;
	int x = 0;

	while (y < map->mapy)
	{
		x = 0;
		while (x < map->mapx)
		{
			if (map->map[y][x] == 'S'/* && map->time % 3 == 0*/)
			{
				if (map->max == 0 && y + 1 < map->mapy && map->map[y + 1][x] != '1')
				{
					if (map->map[y + 1][x] == '1')
						map->max = 1;
					map->map[y][x] = '0';
					map->map[y + 1][x] = 'S';
				}
				if (map->max == 1)
				{
					dprintf(1, "DSHUBD\n");
					map->map[y][x] = '0';
					map->map[y - 1][x] = 'S';
				//	if (map->map[y - 1][x] == '1')
				//		map->max = 0;
				}	
			}	
			x++;	
		}
		y++;
	}
}
void	print_map(t_info *map)
{
	int	x;
	int	y;
	int	prx;
	int pry;

	y = new_ternaire(map->pos_y - 15 < 0 , map->pos_y - 15, 0);
	while (y >= 0 && y < map->mapy && y < map->pos_y + 13)
	{
		pry = (Y_WIN * 0.5) + 64 * (y - map->pos_y);
		x = new_ternaire(map->pos_x - 17 < 0 , map->pos_x - 17, 0);
		while (x >= 0 && x < map->mapx && x < map->pos_x + 15)
		{
			prx = (X_WIN * 0.5) - (64 * (map->pos_x - x));
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[4].img, prx, pry);
			else
			{
				mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[1].img, prx, pry);
			}
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[3].img, prx, pry);
			x++;
		}
		y++;

	}

	print_sprite(map);
	print_ennemy(map);
}

int creat_img(t_info *map)
{
	map->time++;
	event(map);
	ennemy_fuck_me(map);
	if (map->nb_seed <= map->compt_recup)
		map->possible = 1;
	refresh(map);
	print_map(map);
	return(0);
}

int init_img(t_info *map)
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


int graph(t_info *map)
{
	mlx_hook(map->img.mlx_win, 2, 1L << 0, keypress, map);
	mlx_hook(map->img.mlx_win, 3, 1L << 1, keyrelease, map);
	//	mlx_hook(map->img.mlx_win, 17, 1L << 17, exit_games, map);
	if (mlx_loop_hook(map->img.mlx, &creat_img, map) == 1)
		return (0);
	mlx_loop(map->img.mlx);
	return (0);


}
