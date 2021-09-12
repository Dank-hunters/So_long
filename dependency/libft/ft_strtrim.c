/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:21:59 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/17 14:27:30 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		u;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	u = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]) != 0)
		i++;
	while (u > 0 && s1[u] && ft_strchr(set, s1[u]) != 0)
		u--;
	if (u < i)
		return (ft_strdup("\0"));
	dest = ft_substr(s1, (unsigned int)i, (u - i + 1));
	return (dest);
}
