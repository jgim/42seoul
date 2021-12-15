/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:11:17 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:44:42 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;
	size_t	msize;

	msize = count * size;
	ans = malloc(msize);
	if (!ans)
		return (NULL);
	if (!msize)
		msize = 1;
	ft_bzero(ans, msize);
	return (ans);
}
