#include <solong.h>

unsigned int	*get_pixel_loc(t_info *map, int x, int y)
{
	char	*dst;

	dst = (char *)map->img.addr + (y * map->img.line_len + x
			* (map->img.bpp / 8));
	return ((unsigned int *)dst);
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

void print_sprite(t_info *map)
{
	int x;
	int y;
	int posaffx;
	int posafy;

	posaffx = 
	posafy = 
	x = map->pos_x;
	y = map->pos_y;
	while(y )
	{
		x = 0;
		while (x < map->mapx)
		{
			if (x == map->pos_x && y == map->pos_y)
				{
					if ((map->nb % 3) == 0)
						mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[0].img, X_WIN/2, Y_WIN/2);
					else 
						mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[5].img, X_WIN/2, Y_WIN/2);
				}
			else if (map->map[y][x] == 'C')
				{
					mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[3].img, 64 * x + 50, 64 * y + 50);
				}
			else if (map->map[y][x] == 'E')
				mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[2].img, 64 * x + 50, 64 * y + 50);
			x++;
		}
		y++;
	}
}

void	print_map(t_info *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < map->mapy)
	{
		x = 0;
		while (x < map->mapx)
		{
			if (map->map[y][x] == '1')
					mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[4].img, 64 * x + 50, 64 * y + 50);
			else
					mlx_put_image_to_window(map->img.mlx, map->img.mlx_win, map->xpm[1].img, 64 * x + 50, 64 * y + 50);
			x++;
		}
		y++;
	}
	print_sprite(map);
}
void	somthing_happend(t_info *map)
{
	char *obj;

	obj = NULL;
	map->compt_recup ++;
	map->map[map->pos_y][map->pos_x] = '0';
	obj = ft_itoa(map->compt_recup);
	refresh(map);
	mlx_string_put(map->img.mlx, map->img.mlx_win, 50, 50, 0xAAAAAA, obj);
	free(obj);
}

int creat_img(t_info *map)
{
	event(map);
	if (map->map[map->pos_y][map->pos_x] == 'C')
		somthing_happend(map);
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
	dprintf(1, "ddd");
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