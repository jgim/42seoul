# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 17:13:15 by jgim              #+#    #+#              #
#    Updated: 2021/07/27 17:13:23 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	push_swap

SRCS	=	push_swap.c\
			swap_push_stack.c\
			rotate.c\
			reverse_rotate.c\
			sort_utilities.c\
			sort.c\
			sort_order.c\
			check_invalid_argument.c\
			add_pop_stack.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc -Wall -Werror -Wextra

RM		=	rm -f

LIBFT	=	./libft/libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C libft/
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean	:
			make clean -C libft
			$(RM) $(OBJS)

fclean	:
			make fclean -C libft
			$(RM) $(OBJS)
			$(RM) $(NAME)

re		:	fclean all
