/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:14:57 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:44:56 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_quote_type
{
	DEFAULT,
	D_QUOT,
	S_QUOT,
	END_S_QUOT,
	END_D_QUOT,
}	t_quote_type;

typedef enum e_special_c
{
	IN_REDIRECT,
	OUT_REDIRECT,
	HERE_DOC,
	APPEND_REDIRECT,
	PIPE,
	FD,
	ELSE
}	t_special_c;

typedef enum e_cmd
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	OTHER,
	NON_CMD,
	CMD_NUM
}	t_cmd;

typedef enum e_pipe_fd
{
	READ,
	WRITE,
	pipe_fd_NUM
}	t_pipe_fd;

typedef enum e_std_fd
{
	ORIGINAL_IN,
	ORIGINAL_OUT,
	ORIGINAL_ERR,
	std_fd_NUM
}	t_std_fd;

typedef enum e_path_type
{
	UNKNOWN,
	EXECUTABLE,
	UN_EXECUTABLE,
	IS_DIR,
	ELSE_TYPE
}	t_path_type;

typedef enum e_fd_mode
{
	SAVE,
	RESTORE,
}	t_fd_mode;

typedef struct s_token
{
	char			*str;
	t_quote_type		type;
	t_special_c		special;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_stream
{
	t_special_c		c_type;
	char			*str;
	char			*quot;
	int				open_fd;
	struct s_stream	*next;
}	t_stream;

typedef struct s_cmdlist
{
	char				*str;
	char				*quot;
	struct s_cmdlist	*next;
}	t_cmdlist;

typedef struct s_envlist
{
	char				*key;
	char				*value;
	struct s_envlist	*next;
}	t_envlist;

typedef struct s_execdata
{
	char				**cmdline;
	int					std_fd[std_fd_NUM];
	t_cmd				cmd_type;
	t_cmdlist			*clst;
	t_stream			*iolst;
	t_envlist			*elst;
	struct s_execdata	*next;
}	t_execdata;

#endif
