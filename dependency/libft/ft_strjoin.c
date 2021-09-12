/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:27:10 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/18 14:29:08 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*d;

	i = 0;
	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	if (!(d = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (*s1)
	{
		d[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		d[i] = *s2++;
		i++;
	}
	d[i] = 0;
	return (d);
}
