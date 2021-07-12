#include "push_swap.h"

void	add_stack(t_stack *s, t_data data)
{
	t_node	*new_node;

	new_node = init_node(data);
	new_node->down = s->top;
	if (s->top)
	{
		s->top->up = new_node;
		s->top = new_node;
	}
	else
	{
		s->bottom = new_node;
		s->top = new_node;
	}
	s->length += 1;
}

void	r_add_stack(t_stack *s, t_data	data)
{
	t_node	*new_node;

	new_node = init_node(data);
	new_node->up = s->bottom;
	if (s->top)
	{
		s->bottom->down = new_node;
		s->bottom = new_node;
	}
	else
	{
		s->bottom = new_node;
		s->top = new_node;
	}
	s->length += 1;
}

t_data		pop_stack(t_stack *s)
{
	t_data	temp_value;
	t_node	*temp;

	temp_value.value = s->top->data.value;
	temp_value.order = s->top->data.order;
	temp = s->top;
	s->top = s->top->down;
	free(temp);
	s->length -= 1;
	if(!s->length)
	{
		s->bottom = NULL;
		s->top = NULL;
	}
	else
		s->top->up = NULL;
	return (temp_value);
}

t_data		r_pop_stack(t_stack *s)
{
	t_data	temp_value;
	t_node	*temp;

	temp_value.value = s->bottom->data.value;
	temp_value.order = s->bottom->data.order;
	temp = s->bottom;
	s->bottom = s->bottom->up;
	free(temp);
	s->length -= 1;
	if(!s->length)
	{
		s->top = NULL;
		s->bottom = NULL;
	}
	else
		s->bottom->down = NULL;
	return (temp_value);
}
