/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:58:56 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/04 18:27:12 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define WALL "textures/wall(1).xpm"
# define SEED "textures/mega_seed.xpm"
# define MORTY "textures/classic_morty(1).xpm"
# define GRASS "textures/grass.xpm"
# define NEWMORTY "textures/ouch_morty.xpm"
# define MORTYW "textures/walking_morty(1).xpm"
# define PORTAL "textures/portal3.xpm"
# define NYMBUS "textures/trash_rick.xpm"
# define ULOOSE "textures/ULOOSE.xpm"

# define X_WIN 2560
# define Y_WIN 1440

# define KEY_DOWN 1
# define KEY_UP 13
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define EXIT_WIN 53

# include <unistd.h>
# include "../dependency/libft/libft.h"
# include <../dependency/mlx/mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_text
{
	void	*img;
	int		width;
	int		height;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_text;

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

typedef struct s_sp
{
	int	p;
	int	c;
	int	e;
}			t_sp;

typedef struct s_info
{
	t_text		xpm[9];
	t_data		img;
	int			error;
	char		**map;
	int			exit;
	char		*filename;
	int			mapx;
	int			mapy;
	int			pos_x;
	int			pos_y;
	int			up;
	int			down;
	int			goleft;
	int			goright;
	int			compt_recup;
	int			nb;
	int			sve_x;
	int			sve_y;
	int			moov;
	int			nb_seed;
	int			possible;
	int			time;
	int			max;
}				t_info;

int				found_pos(t_info *map, int i, int y);
void			check_rectangle(t_info *map);
void			check_char(t_info *map);
int				ft_ischar(char *str, char c);
int				fill_flood_map(t_info *map, int x, int y);
void			freed(t_info *map);
int				error(t_info *map, int i);
int				errors(t_info *map, int i);
void			*free_line(char *str);
void			seed_hitbox(t_info *map);
void			refresh(t_info *map);
int				init_img(t_info *map);
int				graph(t_info *map);
int				keypress(int key, t_info *map);
int				keyrelease(int key, t_info *map);
void			event(t_info *map);
void			file_to_img(t_info *map);
int				init_text(t_info *map, int i, int errror);
void			init_struct(t_info *map, char **av);
int				parse(t_info *map);
void			print_map(t_info *map, int x, int y);
int				get_next_line(int fd, char **line);
size_t			ft_strrlen(const char *str);
char			*ft_strdupp(const char *s1, int leaks);
char			*ft_strjoin(char const *s1, char const *s2);
void			somthing_happend(t_info *map);
void			ennemy_fuck_me(t_info *map);
unsigned int	*get_pixel_loc(t_info *map, int x, int y);
void			print_ennemy(t_info *map);
int				exit_games(t_info *map, int cdt);
void			print_sprite(t_info *map);
void			print_exit(t_info *map);
void			print_moov(t_info *map);
void			free_map(t_info *map, int cdt);

#endif
