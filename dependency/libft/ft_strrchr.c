/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:52:00 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/17 14:21:29 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	c1 = (unsigned char)c;
	i = ft_strlen(s);
	if (c1 == '\0')
		return (ft_strchr(s, '\0'));
	while (i >= 0)
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
