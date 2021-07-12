#include "push_swap.h"

t_node		*init_node(t_data data)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->up = NULL;
	node->data.value = data.value;
	node->data.order = data.order;
	node->down = NULL;
	return (node);
}

void		init_stack(t_stack *a, t_stack *b)
{
	a->length = 0;
	a->top = NULL;
	a->bottom = NULL;
	b->length = 0;
	b->top = NULL;
	b->bottom = NULL;
}

int		input_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;
	t_data	data;

	i = -1;
	while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = -1;
		while(str[++j])
		{
			if(!check_num(str[j]) || !check_int(str[j]))
			{
				free_word(str);
				return (write(1, "Error\n", 6));
			}
			data.value = ft_atoi(str[j]);
			data.order = 0;
			r_add_stack(a, data);
			free(str[j]);
		}
		free(str);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a, &b);
	if(input_stack(&a, argc - 1, argv + 1))
		return (0);
	if (order_sort(&a, a.length))
		return (0);
	basic_sort(&a, &b, 0, a.length);
	return 0;
}
