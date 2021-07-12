#include "push_swap.h"

int		swap_a(t_stack *a)
{
	t_data x;
	t_data y;

	if (a->bottom->up)
	{
		x = pop_stack(a);
		y = pop_stack(a);
		add_stack(a, x);
		add_stack(a, y);
	}
	return (write (1,"sa\n", 3));
}

int		swap_b(t_stack *b)
{
	t_data x;
	t_data y;

	if (b->bottom->up)
	{
		x = pop_stack(b);
		y = pop_stack(b);
		add_stack(b, x);
		add_stack(b, y);
	}
	return (write (1,"sb\n", 3));
}

int		d_swap(t_stack *a, t_stack *b)
{
	t_data x;
	t_data y;

	if (a->bottom->up)
	{
		x = pop_stack(a);
		y = pop_stack(a);
		add_stack(a, x);
		add_stack(a, y);
	}
	if (b->bottom->up)
	{
		x = pop_stack(b);
		y = pop_stack(b);
		add_stack(b, x);
		add_stack(b, y);
	}
	return (write (1,"ss\n", 3));
}

int		push_a(t_stack *a, t_stack *b)
{
	t_data x;

	if (b->bottom)
	{
		x = pop_stack(b);
		add_stack(a, x);
	}
	return (write(1, "pa\n", 3));
}


int		push_b(t_stack *a, t_stack *b)
{
	t_data x;

	if (a->bottom)
	{
		x = pop_stack(a);
		add_stack(b, x);
	}
	return (write(1, "pb\n", 3));
}
