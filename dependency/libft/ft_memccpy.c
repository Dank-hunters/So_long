/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:50:32 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/17 14:28:07 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	rt;
	unsigned char	*s;
	unsigned char	*d;

	rt = (unsigned char)c;
	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n > 0)
	{
		d[i] = s[i];
		if (s[i] == rt)
			return (&d[i + 1]);
		i++;
		n--;
	}
	return (NULL);
}
