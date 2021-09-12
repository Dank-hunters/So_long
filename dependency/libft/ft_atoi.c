/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:51:14 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/17 14:16:11 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int tmp, long int nb, long int pn)
{
	if ((nb < tmp) && (pn == -1))
		return (0);
	else if (nb < tmp && pn == 1)
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	long int	nb;
	int			pn;
	long int	tmp;

	tmp = 0;
	pn = 1;
	nb = 0;
	while ((*str == ' ') || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pn = pn * -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nb = (nb * 10) + *str++ - 48;
		if (check(tmp, nb, pn) == -1)
			return (-1);
		if (check(tmp, nb, pn) == 0)
			return (0);
		tmp = nb;
	}
	return ((int)(nb * pn));
}
