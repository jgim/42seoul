/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:08:25 by jgim              #+#    #+#             */
/*   Updated: 2020/11/08 20:23:30 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *new_list;
	t_list *curr_list;

	if (!lst)
		return (0);
	if (!(new = ft_lstnew((*f)(lst->content))))
		return (0);
	new_list = new;
	curr_list = lst->next;
	while (curr_list)
	{
		if (!(new_list->next = ft_lstnew((*f)(curr_list->content))))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		new_list = new_list->next;
		curr_list = curr_list->next;
	}
	return (new);
}
