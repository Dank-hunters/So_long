/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:24:34 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/18 14:32:09 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	nextl;

	nextl = 0;
	if (!(src) || !(dest))
		return (0);
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	if (len >= size)
		nextl = size - 1;
	else
		nextl = len;
	ft_memcpy(dest, src, nextl);
	dest[nextl] = '\0';
	return (len);
}
