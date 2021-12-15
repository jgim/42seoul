/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:11:39 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:42:08 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Create envlist from envp. Return the list.
*/

static void	set_key_and_value(char *env, t_envlist *new)
{
	char	*key;
	char	*value;
	char	*p_equal;
	size_t	key_len;

	p_equal = ft_strchr(env, '=');
	key_len = p_equal - env;
	key = ft_custom_substr(env, 0, key_len);
	value = ft_custom_substr(env, key_len + 1, ft_strlen(env) - key_len - 1);
	new->key = key;
	new->value = value;
}

static t_envlist	*new_envlist(t_envlist *cur, char *env)
{
	t_envlist	*new;

	new = ft_custom_calloc(1, sizeof(*new));
	set_key_and_value(env, new);
	cur->next = new;
	return (new);
}

t_envlist	*create_envlist(char **envp)
{
	t_envlist	head;
	t_envlist	*cur;
	size_t		i;

	i = 0;
	cur = &head;
	if (envp[i] == NULL)
		return (NULL);
	while (envp[i])
	{
		cur = new_envlist(cur, envp[i]);
		i++;
	}
	return (head.next);
}
