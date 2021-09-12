/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:27:02 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/17 14:28:20 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*err(char *d)
{
	if (!(d = malloc(sizeof(char) * 1)))
		return (0);
	d[0] = 0;
	return (d);
}

static int	ft_len(char const *s, unsigned int start)
{
	int				tmp;
	unsigned int	svtart;

	svtart = start;
	tmp = 0;
	while (s[svtart])
	{
		tmp++;
		svtart++;
	}
	return (tmp);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*d;

	i = 0;
	d = 0;
	if (!s || len <= 0 || ((size_t)start >= ft_strlen(s)))
		return (err(d));
	i = ft_len(s, start);
	if (i < len)
	{
		if (!(d = malloc(sizeof(char) * i + 1)))
			return (0);
	}
	else if (!(d = malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (s[start] && (size_t)i < len)
	{
		d[i] = s[start];
		start++;
		i++;
	}
	d[i] = 0;
	return (d);
}
