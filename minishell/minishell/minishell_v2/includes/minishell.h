/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:46:46 by silim             #+#    #+#             */
/*   Updated: 2021/09/26 15:24:00 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** libraries
*/
#	include <stdio.h>
#	include <termcap.h>
#	include <curses.h>
#	include <termios.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include "../libft/libft.h"

/*
** defines
*/
# define ESC '\033'
# define KEYBOARD '['
# define UP 'A'
# define DOWN 'B'
# define BACKSPACE 127
# define QUOTE 39
# define DOUBLE_QUOTE 34
# define ENTER 10
# define CTRL_D 4
# define BEEP "\a"

/*
** enums
*/

enum					e_status
{
	INTERNAL_ERROR = 0,
	ARG_ERROR = 0,
	SUCCESS = 1,
	INVALID = 0,
	VALID = 1,
};

enum					e_direction
{
	LEFT = -1,
	NONE = 0,
	RIGHT = 1,
};

/*
** structs
*/

typedef	struct			s_shell
{
	char				**env;
	struct s_history	*history;
	int					env_size;
	int					status;
	struct s_cmd		*cmds;
	char				**pipe;
	int					print_flag;
}						t_shell;

typedef struct			s_cmd
{
	struct s_cmd		*prev;
	struct s_cmd		*next;
	struct s_param		*param;
	int					cmd_count;
	int					cmd_idx;
	int					direction;
}						t_cmd;

typedef struct			s_param
{
	struct s_param		*prev;
	struct s_param		*next;
	int					param_count;
	int					param_idx;
}						t_param;

typedef struct			s_history
{
	struct s_history	*up;
	struct s_history	*down;
	char				*cmd;
	int					count;
	int					rewind;
}						t_history;

typedef struct			s_global
{
	pid_t				pid;
}						t_global;

t_global global;

/*
** functions
*/
void	run_shell(t_shell *shell);
int		check_syntax(char *cmd);
t_history	*search_history(t_history *history, char key, int *arrow_count);
int		parse_cmd(t_shell *shell);
int		read_key(t_history *history);
int		read_general_key(char key, t_history *history);
void	delete_key(char *str);
void	delete_str(int str_len);
t_history	*new_history(t_history *old_history);
t_history	*init_history(void);
t_history	*expire_history(t_history *history);



#endif
