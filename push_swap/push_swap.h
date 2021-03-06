/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:16:01 by jgim              #+#    #+#             */
/*   Updated: 2021/07/27 17:16:02 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

struct	s_node;
struct	s_data;
struct	s_pivot;
struct	s_rewind;
struct	s_note;
struct	s_stack;

typedef struct s_data
{
	int	value;
	int	order;
}		t_data;

typedef struct s_node
{
	struct s_node	*down;
	t_data			data;
	struct s_node	*up;
}					t_node;

typedef struct s_pivot
{
	int	high;
	int	low;
}		t_pivot;

typedef struct s_rewind
{
	int	a;
	int	b;
}		t_rewind;

typedef struct s_note
{
	int	top;
	int	middle;
	int	base;
}		t_note;

typedef struct s_stack
{
	int		length;
	t_node	*bottom;
	t_node	*top;
}			t_stack;

/* check_invalid_argument.c */
int		check_ascending(t_stack a);
int		check_int(char *str);
int		check_num(const char *str);

/* sort_order.c */
void	basic_a_three(t_stack *a, int pivot);
void	basic_b_three(t_stack *b, int pivot);
int		basic_three_sort(t_stack *a, t_stack *b, int flag);
int		sort_three(t_stack *a, t_stack *b, int flag);
int		three_and_less(t_stack *a, t_stack *b, int order_gap, int flag);

/* sort.c */
int		basic_sort(t_stack *a, t_stack *b, int low, int high);
int		b_two_a_sort(t_stack *a, t_stack *b, int low, int high);
int		a_two_b_sort(t_stack *a, t_stack *b, int low, int high);

/* sort_utilities.c */
void	rewind_stack(t_stack *a, t_stack *b, t_rewind rewind);
void	init_var(t_pivot *pivot, t_rewind *rewind, int low, int high);
int		pivot_three(t_stack *a, t_stack *b, int flag);
int		order_sort(t_stack *a, int num);

/* reverse_rotate.c */
int		d_r_rotate(t_stack *a, t_stack *b);
int		r_rotate_b(t_stack *b);
int		r_rotate_a(t_stack *a);

/* rotate.c */
int		d_rotate(t_stack *a, t_stack *b);
int		rotate_b(t_stack *b);
int		rotate_a(t_stack *a);

/* swap_push_stack.c */
int		push_b(t_stack *a, t_stack *b);
int		push_a(t_stack *a, t_stack *b);
int		d_swap(t_stack *a, t_stack *b);
int		swap_b(t_stack *b);
int		swap_a(t_stack *a);

/* add_pop_stack.c */
int		input_stack(t_stack *a, char **str, t_data *data);
t_data	r_pop_stack(t_stack *s);
t_data	pop_stack(t_stack *s);
void	r_add_stack(t_stack *s, t_data	data);
void	add_stack(t_stack *s, t_data data);

/* push_swap.c */
int		main(int argc, char **argv);
int		clear_stack(t_stack *a, t_stack *b);
int		input_value(t_stack *a, int argc, char **argv);
void	init_stack(t_stack *a, t_stack *b);
t_node	*init_node(t_data data);

#endif
