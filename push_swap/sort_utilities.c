/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:16:17 by jgim              #+#    #+#             */
/*   Updated: 2021/07/27 17:16:18 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rewind_stack(t_stack *a, t_stack *b, t_rewind rewind)
{
	int	i;
	int	re_rotate;

	i = 0;
	re_rotate = 0;
	if (!b->top)
		return ;
	if (rewind.a < rewind.b)
		re_rotate = rewind.a;
	else
		re_rotate = rewind.b;
	while (i++ < re_rotate)
		d_r_rotate(a, b);
	i = 0;
	if (rewind.a < rewind.b)
		while (i++ < rewind.b - rewind.a)
			r_rotate_b(b);
	else if (rewind.a > rewind.b)
		while (i++ < rewind.a - rewind.b)
			r_rotate_a(a);
}

void	init_var(t_pivot *pivot, t_rewind *rewind, int low, int high)
{
	pivot->high = low + 2 * (high - low) / 3;
	pivot->low = low + (high - low) / 3;
	rewind->a = 0;
	rewind->b = 0;
}

int	pivot_three(t_stack *a, t_stack *b, int flag)
{
	int	pivot;

	if (flag == 1)
	{
		pivot = a->top->data.order;
		if (a->top->down->data.order > pivot)
			pivot = a->top->down->data.order;
		if (a->top->down->down->data.order > pivot)
			pivot = a->top->down->down->data.order;
	}
	else
	{
		pivot = b->top->data.order;
		if (b->top->down->data.order < pivot)
			pivot = b->top->down->data.order;
		if (b->top->down->down->data.order < pivot)
			pivot = b->top->down->down->data.order;
	}
	return (pivot);
}

int	order_sort(t_stack *a, int num)
{
	int		i;
	t_node	*low_node;
	t_node	*compare_node;

	i = 0;
	while (++i <= num)
	{
		low_node = a->bottom;
		while (low_node->data.order)
			low_node = low_node->up;
		compare_node = low_node->up;
		while (compare_node != NULL)
		{
			if (low_node->data.value > compare_node->data.value
				&& !compare_node->data.order)
				low_node = compare_node;
			else if (low_node->data.value == compare_node->data.value)
				return (write (1, "Error\n", 6));
			compare_node = compare_node->up;
		}
		low_node->data.order = i;
	}
	if (!check_ascending(*a))
		return (1);
	return (0);
}
