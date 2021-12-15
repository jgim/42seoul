/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:30:45 by jgim              #+#    #+#             */
/*   Updated: 2021/07/26 16:30:52 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clear_stack(t_stack *a, t_stack *b)
{
	while (a && a->length)
		pop_stack(a);
	while (b && b->length)
		pop_stack(b);
	return (1);
}

t_node	*init_node(t_data data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->up = NULL;
	node->data.value = data.value;
	node->data.order = data.order;
	node->down = NULL;
	return (node);
}

void	init_stack(t_stack *a, t_stack *b)
{
	a->length = 0;
	a->top = NULL;
	a->bottom = NULL;
	b->length = 0;
	b->top = NULL;
	b->bottom = NULL;
}

int	input_value(t_stack *a, int argc, char **argv)
{
	int		i;
	char	**str;
	t_data	data;

	i = -1;
	while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (input_stack(a, str, &data))
			return (1);
		free(str);
	}
	if (!a->length)
		return (write(1, "Error\n", 6));
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (!argv[1])
		return (0);
	init_stack(&a, &b);
	if (input_value(&a, argc - 1, argv + 1))
		return (clear_stack(&a, &b));
	if (order_sort(&a, a.length))
		return (clear_stack(&a, &b));
	basic_sort(&a, &b, 0, a.length);
	return (clear_stack(&a, &b));
}
