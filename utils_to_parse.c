/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:11:24 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/27 17:53:09 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	error(t_info *map, int i)
{
	ft_putstr("Error\n");
	if (i == 1)
		ft_putstr("Bad spawn point.");
	if (i == 2)
		ft_putstr("No spawn point");
	if (i == 3)
		ft_putstr("Too much player in game");
	if (i == 4)
		ft_putstr("Malloc error");
	if (i == 5)
		ft_putstr("The map MUST BE rectangular");
	if (i == 6)
		ft_putstr("Wrong caracteres in map");
	if (i == 8)
		ft_putstr("Missing caractere");
	if (i == 9)
		ft_putstr("Map not close");
	if (i <= 5)
		exit(0);
	else
	{
		freed(map);
		exit(0);
	}
	return (1);

}
