/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:52 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/17 14:27:56 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*sv;

	i = 0;
	sv = (const unsigned char *)s;
	while (i < n)
	{
		if (sv[i] == (unsigned char)c)
			return ((void *)&sv[i]);
		i++;
	}
	return (NULL);
}
