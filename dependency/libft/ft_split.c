/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:21:37 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/17 14:21:38 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_malloc(char const *s, char c)
{
	char	*dest;
	int		u;

	u = 0;
	while (s[u] && (s[u] != c))
		u++;
	if (!(dest = malloc(sizeof(char) * (u + 1))))
		return (0);
	if (!(s))
		return (0);
	ft_memccpy(dest, s, (int)c, u);
	dest[u] = 0;
	return (dest);
}

static int			ft_check(char const *s, char c)
{
	int	i;
	int	u;

	u = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i])
			u++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (u);
}

static const char	*ft_nextword(char const *s, char c)
{
	while ((*s == c) && (*s))
		s++;
	return (s);
}

char				**ft_put_in(char const *s, char **dest, char c, int y)
{
	int	i2;
	int	i;

	i = 0;
	i2 = 0;
	while (i < y)
	{
		s = ft_nextword(s, c);
		if (!(dest[i] = ft_malloc(s, c)))
		{
			while (dest[i2])
				free(dest[i2++]);
			if (dest)
				free(dest);
			return (0);
		}
		while ((*s != c) && (*s))
			s++;
		i++;
	}
	return (dest);
}

char				**ft_split(char const *s, char c)
{
	int		y;
	char	**dest;

	y = 0;
	if (s == 0)
		return (0);
	if (!*s)
	{
		if (!(dest = malloc(sizeof(char *) * 1)))
			return (0);
		dest[y] = NULL;
		return (dest);
	}
	y = ft_check(s, c);
	if (!(dest = malloc(sizeof(char *) * (y + 1))))
		return (0);
	if (ft_put_in(s, dest, c, y) == 0)
		return (0);
	dest[y] = 0;
	return (dest);
}
