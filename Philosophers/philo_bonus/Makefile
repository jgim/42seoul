# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 08:07:56 by jgim              #+#    #+#              #
#    Updated: 2022/01/27 11:55:39 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

SRCS	=	main.c \
			data_management.c \
			philosopy.c \
			philosopher.c \
			print.c \
			utils.c \

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(OBJS)
			$(RM) $(NAME)

re		:	fclean all
