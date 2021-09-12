/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:19:58 by cguiot            #+#    #+#             */
/*   Updated: 2020/12/17 14:20:04 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nvl_list;
	t_list	*nvl_content;

	nvl_content = NULL;
	nvl_list = NULL;
	while (lst)
	{
		if (!(nvl_content = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&nvl_list, del);
			return (NULL);
		}
		ft_lstadd_back(&nvl_list, nvl_content);
		lst = lst->next;
	}
	return (nvl_list);
}
