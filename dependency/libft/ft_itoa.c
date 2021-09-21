/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:16:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/09/20 14:51:33 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(long int nb)
{
	int		si;

	si = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		si++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		si++;
	}
	return (si);
}

static char	*nbzero(void)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[0] = 48;
	str[1] = 0;
	return (str);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	i = size(n);
	if (nb == 0)
		return (nbzero());
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i--] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (str);
}
