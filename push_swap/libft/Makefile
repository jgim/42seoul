# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 23:53:39 by jgim              #+#    #+#              #
#    Updated: 2021/07/29 23:53:41 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	libft_utilities.c\
			copy_libft.c\

OBJS 	=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc -Wall -Werror -Wextra

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean $(NAME)

.PHONY	:	all clean fclean re
