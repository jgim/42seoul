/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 23:53:25 by jgim              #+#    #+#             */
/*   Updated: 2021/07/29 23:53:29 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/*libft_utilities.c*/
int		delimiter(char const *s, char c);
void	*free_word(char **word, int idx);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);

/*copy_libft.c*/
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t num);

#endif
