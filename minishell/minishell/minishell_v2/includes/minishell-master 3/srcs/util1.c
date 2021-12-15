/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:13:07 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:42:29 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void	*ft_custom_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
	{
		ft_perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

char	*ft_custom_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = ft_substr(s, start, len);
	if (ret == NULL)
	{
		ft_perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

char	*ft_custom_strdup(const char *src)
{
	char	*ret;

	ret = ft_strdup(src);
	if (ret == NULL)
	{
		ft_perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

char	*ft_custom_itoa(int n)
{
	char	*ret;

	ret = ft_itoa(n);
	if (ret == NULL)
	{
		ft_perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

void	custom_signal(int sig, void f(int))
{
	if (signal(sig, f) == SIG_ERR)
	{
		ft_perror("signal");
		exit(EXIT_FAILURE);
	}
}
