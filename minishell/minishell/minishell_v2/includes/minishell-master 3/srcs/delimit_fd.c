/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimit_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:11:32 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:44:56 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_stream	*insert_redirect_stream(t_stream *cur,
			char *redirect, t_special_c type)
{
	t_stream	*new;

	new = (t_stream *)ft_custom_calloc(1, sizeof(*new));
	new->str = redirect;
	new->quot = get_quot_flag(new->str);
	new->open_fd = -1;
	new->c_type = type;
	cur->next = new;
	return (new);
}

t_stream	*delimit_fd(t_stream *cur)
{
	size_t		i;
	char		*fd;
	char		*redirect;
	t_special_c	type;

	i = 0;
	while (ft_isdigit(cur->str[i]))
		i++;
	fd = ft_custom_substr(cur->str, 0, i);
	redirect = ft_custom_substr(cur->str, i, ft_strlen(cur->str + i));
	free(cur->quot), free(cur->str);
	cur->str = fd;
	cur->quot = get_quot_flag(cur->str);
	type = cur->c_type;
	cur->c_type = FD;
	return (insert_redirect_stream(cur, redirect, type));
}
