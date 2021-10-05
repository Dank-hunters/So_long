/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:12:10 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/05 17:41:01 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t ne, size_t size)
{
	void	*res;

	res = malloc(ne * size);
	if (!(res))
		return (0);
	ft_bzero(res, ne * size);
	return (res);
}
