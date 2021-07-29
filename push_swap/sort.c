/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:16:12 by jgim              #+#    #+#             */
/*   Updated: 2021/07/27 17:16:13 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	basic_sort(t_stack *a, t_stack *b, int low, int high)
{
	int			i;
	int			len;
	t_pivot		pivot;
	t_rewind	rewind;

	i = 0;
	len = a->length;
	init_var(&pivot, &rewind, low, high);
	if (high - low <= 3)
		return (three_and_less(a, b, high - low, 1));
	while (i++ < high - low)
	{
		if (a->top->data.order > pivot.high)
			rotate_a(a);
		else
		{
			push_b(a, b);
			if (b->top->data.order <= pivot.low)
				rotate_b(b);
		}
	}
	a_two_b_sort(a, b, pivot.high, high);
	b_two_a_sort(a, b, pivot.low, pivot.high);
	b_two_a_sort(a, b, low, pivot.low);
	return (0);
}

int	a_two_b_sort(t_stack *a, t_stack *b, int low, int high)
{
	t_pivot		pivot;
	t_rewind	rewind;
	int			i;

	init_var(&pivot, &rewind, low, high);
	if (high - low <= 3)
		return (three_and_less(a, b, high - low, 1));
	i = -1;
	while (++i < high - low)
	{
		if (a->top->data.order > pivot.high)
			rotate_a(a) && rewind.a++;
		else
		{
			push_b(a, b);
			if (b->top->data.order > pivot.low)
				rotate_b(b) && rewind.b++;
		}
	}
	rewind_stack(a, b, rewind);
	a_two_b_sort(a, b, pivot.high, high);
	b_two_a_sort(a, b, pivot.low, pivot.high);
	return (b_two_a_sort(a, b, low, pivot.low));
}

int	b_two_a_sort(t_stack *a, t_stack *b, int low, int high)
{
	t_pivot		pivot;
	t_rewind	rewind;
	int			i;

	init_var(&pivot, &rewind, low, high);
	if (high - low <= 3)
		return (three_and_less(a, b, high - low, 2));
	i = 0;
	while (i++ < high - low)
	{
		if (b->top->data.order <= pivot.low)
			rotate_b(b) && rewind.b++;
		else
		{
			push_a(a, b);
			if (a->top->data.order <= pivot.high)
				rotate_a(a) && rewind.a++;
		}
	}
	a_two_b_sort(a, b, pivot.high, high);
	rewind_stack(a, b, rewind);
	a_two_b_sort(a, b, pivot.low, pivot.high);
	return (b_two_a_sort(a, b, low, pivot.low));
}
