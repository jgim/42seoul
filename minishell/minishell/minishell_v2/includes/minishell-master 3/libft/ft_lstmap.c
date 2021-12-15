/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:12:18 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:44:45 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp_lst;
	t_list	*op;
	t_list	*new_elm;

	if (!f)
		return (NULL);
	tmp_lst = lst;
	op = NULL;
	while (tmp_lst)
	{
		new_elm = ft_lstnew(f(tmp_lst->content));
		if (!new_elm)
		{
			ft_lstclear(&op, del);
			return (NULL);
		}
		ft_lstadd_back(&op, new_elm);
		tmp_lst = tmp_lst->next;
	}
	return (op);
}
