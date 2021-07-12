/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:55:08 by jgim              #+#    #+#             */
/*   Updated: 2021/01/05 18:04:15 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t n_len(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break;
		i++;
	}
	return (i);
}

int devider(char **paragraph, char **line)
{
	char *temp;

	if (n_len(*paragraph) < ft_strlen(*paragraph))
	{
		*line = ft_substr(*paragraph, 0, n_len(*paragraph));
		temp = ft_substr(*paragraph, n_len(*paragraph) + 1, ft_strlen(*paragraph));
		free(*paragraph);
		*paragraph = ft_strdup(temp);
		free(temp);
		return (1);
	}
	else
	{
		*line = ft_strdup(*paragraph);
		free(*paragraph);
		*paragraph = 0;
		return (0);
	}
}

int get_next_line(int fd, char **line)
{
	static char *paragraph[OPEN_MAX];
	char buf[BUFFER_SIZE + 1];
	int rd_byte;
	char *temp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((rd_byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_byte] = '\0';
		if (!paragraph[fd])
			paragraph[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(paragraph[fd], buf);
			free(paragraph[fd]);
			paragraph[fd] = temp;
		}
		if (ft_strchr(paragraph[fd], '\n'))
			break;
	}
	if (rd_byte < 0)
		return (-1);
	else if (rd_byte == 0 && paragraph[fd] == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (devider(&paragraph[fd], line));
}
