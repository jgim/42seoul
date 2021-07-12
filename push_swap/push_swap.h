#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct		s_data
{
	int				value;
	int				order;
}					t_data;

typedef struct		s_node
{
	struct s_node	*down;
	t_data			data;
	struct s_node	*up;
}					t_node;

typedef	struct		s_pivot
{
	int				high;
	int				low;
}					t_pivot;

typedef struct		s_rewind
{
	int				a;
	int				b;
}					t_rewind;

typedef	struct		s_note
{
	int				top;
	int				middle;
	int				base;
}					t_note;

typedef	struct		s_stack
{
	int				length;
	t_node			*bottom;
	t_node			*top;
}					t_stack;

/* copy_libft.c */
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t num);

/* libft_utilities.c */
int		delimiter(char const *s, char c);
size_t	ft_strlen(const char *s);
void	*free_word(char **word);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

/* check_invalid_argument.c */
int		check_ascending(t_stack a);
int 	check_int(char *str);
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
t_data	r_pop_stack(t_stack *s);
t_data	pop_stack(t_stack *s);
void	r_add_stack(t_stack *s, t_data	data);
void	add_stack(t_stack *s, t_data data);

/* push_swap.c */
int		main(int argc, char **argv);
int		input_stack(t_stack *a, int argc, char **argv);
void	init_stack(t_stack *a, t_stack *b);
t_node	*init_node(t_data data);
