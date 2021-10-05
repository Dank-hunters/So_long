/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:14:08 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/05 17:34:05 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	if (!((d) || (s)))
		return (0);
	if (d < s)
	{
		while (n-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{		
		while (n-- >= 1)
			d[n - 1] = s[n - 1];
	}
	return (dest);
}
