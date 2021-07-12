SRCS	=	push_swap.c\
			swap_push_stack.c\
			rotate.c\
			reverse_rotate.c\
			sort_utilities.c\
			sort.c\
			sort_order.c\
			check_invalid_argument.c\
			libft_utilities.c\
			copy_libft.c\
			add_pop_stack.c

OBJ		=	$(SRCS:.c=.o)
NAME	=	push_swap
FLAGS	=	-Wall -Werror -Wextra
all		:	$(NAME)

.c.o	:
			gcc $(FLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME)	:	$(OBJ)
	gcc $(FLAGS) -I. -o $(NAME) $(OBJ)

clean	:
			rm -f $(OBJ)

fclean	:
			rm -f $(OBJ)
			rm -f $(NAME)

re		:	fclean all
