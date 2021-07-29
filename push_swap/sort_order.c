/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:14:51 by jgim              #+#    #+#             */
/*   Updated: 2021/07/27 17:14:52 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_and_less(t_stack *a, t_stack *b, int order_gap, int flag)
{
	if (order_gap != 3)
	{
		if (order_gap == 1 && flag == 2)
			return (push_a(a, b));
		else if (order_gap == 2 && flag == 1
			&& a->top->data.order > a->top->down->data.order)
			return (swap_a(a));
		else if (order_gap == 2 && flag == 2)
		{
			if (b->top->data.order < b->top->down->data.order)
				swap_b(b);
			return (push_a(a, b), push_a(a, b));
		}
		return (1);
	}
	if ((a->length == 3 && flag == 1)
		|| (b->length == 3 && flag == 2))
		return (basic_three_sort(a, b, flag));
	return (sort_three(a, b, flag));
}

int	sort_three(t_stack *a, t_stack *b, int flag)
{
	int		pivot;

	if (flag == 2)
		push_a(a, b) && push_a(a, b) && push_a(a, b);
	pivot = pivot_three(a, b, 1);
	if (a->top->data.order == pivot)
	{
		swap_a(a) && rotate_a(a) && swap_a(a) && r_rotate_a(a);
		if (a->top->data.order > a->top->down->data.order)
			swap_a(a);
	}
	else if (a->top->down->data.order == pivot)
	{
		rotate_a(a) && swap_a(a) && r_rotate_a(a);
		if (a->top->data.order > a->top->down->data.order)
			swap_a(a);
	}
	else
		if (a->top->data.order > a->top->down->data.order)
			swap_a(a);
	return (1);
}

int	basic_three_sort(t_stack *a, t_stack *b, int flag)
{
	int	pivot;

	pivot = pivot_three(a, b, flag);
	if (flag == 1)
		basic_a_three(a, pivot);
	else
	{
		basic_b_three(b, pivot);
		return (push_a(a, b), push_a(a, b), push_a(a, b));
	}
	return (1);
}

void	basic_a_three(t_stack *a, int pivot)
{
	if (a->top->data.order == pivot)
	{
		rotate_a(a);
		if (a->top->data.order > a->top->down->data.order)
			swap_a(a);
	}
	else if (a->top->down->data.order == pivot)
	{
		r_rotate_a(a);
		if (a->top->data.order > a->top->down->data.order)
			swap_a(a);
	}
	else
		if (a->top->data.order > a->top->down->data.order)
			swap_a(a);
}

void	basic_b_three(t_stack *b, int pivot)
{
	if (b->top->data.order == pivot)
	{
		rotate_b(b);
		if (b->top->data.order < b->top->down->data.order)
			swap_b(b);
	}
	else if (b->top->down->data.order == pivot)
	{
		r_rotate_b(b);
		if (b->top->data.order < b->top->down->data.order)
			swap_b(b);
	}
	else
		if (b->top->data.order < b->top->down->data.order)
			swap_b(b);
}
