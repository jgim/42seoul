/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:16:28 by silim             #+#    #+#             */
/*   Updated: 2021/09/22 22:28:14 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	@file check_syntax.c
**	@description  check if is valid syntax as below.
**		1. must not be double pipe, double semi-colon.
		2. quote(or double quote) count must be even.
*/

static int	is_valid_seperator(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[i] == '|' || cmd[i] == ';')
		return (INVALID);
	while (cmd[++i] && (cmd[i] == ' ' || cmd[i] == '>'
		|| cmd[i] == '<' || cmd[i] == '|' || cmd[i] == ';'))
	{
		if (cmd[i] == '|' || cmd[i] == ';')
			return (INVALID);
	}
	return (VALID);
}

int		check_syntax(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd || is_valid_seperator(cmd) == INVALID)
		return (ARG_ERROR);
	return (SUCCESS);
}
