/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:27:28 by jgim              #+#    #+#             */
/*   Updated: 2020/11/05 12:06:59 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *list;

	tmp = *lst;
	while (tmp)
	{
		list = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = list;
	}
	*lst = 0;
}
