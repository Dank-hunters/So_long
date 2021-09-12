/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:27:31 by cguiot            #+#    #+#             */
/*   Updated: 2020/11/26 18:24:28 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	u;
	size_t	y;

	i = 0;
	u = 0;
	y = 0;
	while (dest[i])
		i++;
	while (src[y])
		y++;
	if (size == 0 || i > size)
		return (y + size);
	if (y == 0)
		return (i);
	while (src[u] && (i + u < size - 1))
	{
		dest[i + u] = src[u];
		u++;
	}
	dest[i + u] = '\0';
	return (y + i);
}
