/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:12:44 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:44:44 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ans;
	unsigned char	ch;

	ans = (unsigned char *)b;
	ch = (unsigned char)c;
	while (len--)
		*(ans++) = ch;
	return (b);
}
