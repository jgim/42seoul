/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:18:11 by silim             #+#    #+#             */
/*   Updated: 2021/09/23 00:25:37 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_output(char **backup, char **line, char *nl_here)
{
	char		*tmp;

	tmp = *backup;
	if (nl_here)
	{
		*line = ft_substr(*backup, 0, nl_here - *backup);
		*backup = ft_strdup(nl_here + 1);
		free(tmp);
		return (_SUCCESS);
	}
	*line = ft_strdup(*backup);
	free(tmp);
	*backup = 0;
	return (_EOF);
}

int				get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	char		*nl_here;
	char		*tmp;
	int			rd_byte;

	rd_byte = 1;
	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (_ERROR);
	while (rd_byte > 0 &&
	(nl_here = is_newline(backup[fd])) == 0)
	{
		if ((rd_byte = read(fd, buff, BUFFER_SIZE)) < 0)
			return (_ERROR);
		buff[rd_byte] = '\0';
		if (!backup[fd])
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin(backup[fd], buff);
		free(backup[fd]);
		backup[fd] = tmp;
	}
	return (get_output(&backup[fd], line, nl_here));
}
