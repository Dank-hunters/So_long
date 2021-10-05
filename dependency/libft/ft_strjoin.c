/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:27:10 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/05 17:28:50 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*res;

	i = 0;
	c = 0;
	res = NULL;
	if (!s1)
		return (NULL);
	if (new_malloc((void *)&res, sizeof(char),
			ft_strlen(s1) + ft_strlen(s2) + 1) == 0)
		return (NULL);
	while (s1[c])
		res[i++] = s1[c++];
	c = 0;
	while (s2[c])
		res[i++] = s2[c++];
	res[i] = '\0';
	return (res);
}
