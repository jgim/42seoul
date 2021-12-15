/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:13:15 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:44:56 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		pipe_fd[READ] = -1;
		pipe_fd[WRITE] = -1;
		return (-1);
	}
	return (0);
}

int	ft_dup(t_execdata *data, t_std_fd type, int oldfd)
{
	int	newfd;

	newfd = dup(oldfd);
	if (newfd == -1)
		ft_perror("dup");
	else
		data->std_fd[type] = newfd;
	return (newfd);
}

int	ft_dup2(int oldfd, int newfd)
{
	int	fd;

	fd = 0;
	if (oldfd < 0)
		return (-1);
	if (oldfd != newfd)
	{
		fd = dup2(oldfd, newfd);
		if (fd == -1)
		{
			if (errno == EBADF)
				ft_perror("file descriptor out of range");
			else
				ft_perror("dup2");
		}
		xclose(oldfd);
	}
	return (fd);
}

t_path_type	ft_stat(char *pathname)
{
	struct stat	sb;

	if (stat(pathname, &sb) == -1)
		return (UNKNOWN);
	if ((sb.st_mode & S_IFMT) == S_IFREG)
	{
		if (sb.st_mode & S_IXUSR)
			return (EXECUTABLE);
		return (UN_EXECUTABLE);
	}
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
		return (IS_DIR);
	return (ELSE_TYPE);
}

int	ft_open(t_stream *filenode, int flags, mode_t mode)
{
	int	fd;

	if (mode == 0)
		fd = open(filenode->str, flags);
	else
		fd = open(filenode->str, flags, mode);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(filenode->str, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror("");
	}
	return (fd);
}
