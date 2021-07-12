#include "push_swap.h"

int		rotate_a(t_stack *a)
{
	t_data x;

	if (a->bottom->up)
	{
		x = pop_stack(a);
		r_add_stack(a, x);
	}
	return (write(1, "ra\n", 3));
}

int		rotate_b(t_stack *b)
{
	t_data x;

	if (b->bottom->up)
	{
		x = pop_stack(b);
		r_add_stack(b, x);
	}
	return (write(1, "rb\n", 3));
}

int		d_rotate(t_stack *a, t_stack *b)
{
	t_data x;

	if (a->bottom->up)
	{
		x = pop_stack(a);
		r_add_stack(a, x);
	}
	if (b->bottom->up)
	{
		x = pop_stack(b);
		r_add_stack(b, x);
	}
	return (write (1,"rr\n", 3));
}
