/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:27:59 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/05 17:28:30 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *str, char c)
{
	int		i;
	int		find;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		find = 0;
		while ((str[i] == c) && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			i++;
			find = 1;
		}
		count = count + find;
	}
	return (count);
}

static int	get_word_length(char *str, char c, int i)
{
	int		len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	**ft_free(int i, char **res)
{
	while (i != 0)
	{
		free(res[i]);
		res[i] = NULL;
		i--;
	}
	res = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	int		i;
	int		j;
	int		l;
	char	**res;

	j = 0;
	l = 0;
	word = count_word((char *)s, c);
	if (!s || new_malloc((void *)&res, sizeof(char *), word + 1) == 0)
		return (0);
	while (l < word)
	{
		i = 0;
		while (s[j] == c)
			j++;
		if (new_malloc((void *)&res[l], sizeof(char),
				(get_word_length((char *)s, c, j) + 1)) == 0)
			return (ft_free(l, res));
		while (s[j] != c && s[j])
			res[l][i++] = s[j++];
		res[l++][i] = '\0';
	}
	res[l] = NULL;
	return (res);
}
