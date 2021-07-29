/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:31:10 by jgim              #+#    #+#             */
/*   Updated: 2021/07/26 16:31:14 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_rotate_a(t_stack *a)
{
	t_data	x;

	if (a->bottom->up)
	{
		x = r_pop_stack(a);
		add_stack(a, x);
	}
	return (write (1, "rra\n", 4));
}

int	r_rotate_b(t_stack *b)
{
	t_data	x;

	if (b->bottom->up)
	{
		x = r_pop_stack(b);
		add_stack(b, x);
	}
	return (write (1, "rrb\n", 4));
}

int	d_r_rotate(t_stack *a, t_stack *b)
{
	t_data	x;

	if (a->bottom->up)
	{
		x = r_pop_stack(a);
		add_stack(a, x);
	}
	if (b->bottom->up)
	{
		x = r_pop_stack(b);
		add_stack(b, x);
	}
	return (write (1, "rrr\n", 4));
}
