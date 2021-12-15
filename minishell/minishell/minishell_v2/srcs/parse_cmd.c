/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:00:39 by jgim              #+#    #+#             */
/*   Updated: 2021/09/22 22:24:25 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	@file parse_cmd.c
**	@description  parse command line into cmd & param values.
*/

//int		parse_cmd(t_shell **shell, char *cmd)
//{
//	int	i;

//	i = 0;
//	while(cmd[i])
//	{

//	}
//}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:00:39 by jgim              #+#    #+#             */
/*   Updated: 2021/09/27 14:49:34 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	@file parse_cmd.c
**	@description  parse command line into cmd & param values.
*/

t_cmd	*new_command(t_cmd *old_cmd)
{
	t_cmd	*new_cmd;

	new_cmd = init_cmd();
	if (old_cmd)
	{
		new_cmd->prev = old_cmd;
		old_cmd->next = new_cmd;
	}
	else
		old_cmd = new_cmd;
	return (new_cmd);
}

t_cmd	*init_command(void)
{
	t_cmd *new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->prev = NULL;
	new_cmd->next = NULL;
	new_cmd->redir = NULL;
	new_cmd->has_pipe = 0;
	return(new_cmd);
}

int	double_strlen2(char **double_str, char *delim)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (double_str[++i])
	{
		j = -1;
		while (double_str[i][++j])
		{
			while (*delim)
			{
				if (double_str[i][j] == *delim)
					count++;
				(*delim)++;
			}
		}
		count++;
	}
	return (count);
}

int		ft_double_split1(char **double_str, char **new_str)
{
	int		i;
	int		j;
	int		k;
	int		start;

	i = -1;
	k = -1;
	while (double_str[++i])
	{
		j = -1;
		while (double_str[i][++j])
		{
			if (double_str[i][j] == '\"' && double_str[i][j - 1] != '\\');
			{
				start = j;
				while(double_str[i][j] && (double_str[i][j] != '\"' || double_str[i][j - 1] == '\\'))
					j++;
				if (double_str[i][j] != '\"')
					return (DOUBLE_QUOTE_ERROR);
				new_str[++k] = ft_strlcpy(double_str[i], start, j - 1);
			}
			else if (double_str[i][j] == '\'')
			{
				start = j;
				while(double_str[i][j] && (double_str[i][j] != '\'' || double_str[i][j - 1] == '\\'))
					j++;
				if (double_str[i][j] != '\'')
					return (SINGLE_QUOTE_ERROR);
				new_str[++k] = ft_strlcpy(double_str[i], start, j - 1);
			}
			else if (double_str[i][j] == '|')
			{
				if (double_str[i][j + 1] != '|')
					return (DOUBLE_PIPE_ERROR);
				new_str[++k] = ft_strlcpy(double_str[i], j, 1);
			}
			else if (double_str[i][j] == '>')
			{
				start = j;
				if (double_str[i][j + 1] == '>')
				{
					if (double_str[i][j + 2] == '>')
						return (TRIPLE_RIGHT_REDIR_ERROR);
					j++;
				}
				new_str[++k] = ft_strlcpy(double_str[i], start, j);
			}
			else if (double_str[i][j] == '<')
			{
				start = j;
				if (double_str[i][j + 1] == '<')
				{
					if (double_str[i][j + 2] == '<')
						return (TRIPLE_LEFT_REDIR_ERROR);
					j++;
				}
				new_str[++k] = ft_strlcpy(double_str[i], start, j);
			}
			else
			{
				start = j;
				while(double_str[i][j] && (double_str[i][j] != '\'' || double_str[i][j] != '\"' || double_str[i][j] != '|' \
					double_str[i][j] != '>' || double_str[i][j] != '<' || double_str[i][j - 1] != '\\'))
					j++;
				new_str[++k] = ft_strlcpy(double_str[i], start, j - 1);
				noname->flag = DOUBLE_QUOTE;
				j--;
			}
		}
	}
	new_str[++k] = NULL;
	return (0);
}

int		parse_cmd(t_cmd *shell_cmd, char *cmd)
{
	char	**tmp_list;
	char	**cmd_list;
	t_cmd 	*new_cmd;
	int		i;
	int		j;

	tmp_list = ft_double_split1(tmp_list, cmd_list);
	cmd_list = ft_double_split2(tmp_list, ' ');
}


int	double_strlen1(char **double_str, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (double_str[++i])
	{
		j = -1;
		while (double_str[i][++j])
		{
			if (double_str[i][j] == c)
				count++;
		}
		count++;
	}
	return (count);
}


char	**ft_double_split1(char **double_str, char c)
{
	int	i;
	int j;
	char **new_double_str;
	char **tmp_str;

	new_double_str = (char **)malloc(sizeof(char *) * \
					(double_strlen(double_str, c) + 1));
	i = -1;
	while (double_str[++i])
	{
		tmp_str = ft_split(double_str[i], c);
		j = -1;
		while (tmp_str[++j])
			new_double_str = tmp_str[j];
	}
	return (new_double_str);
}
