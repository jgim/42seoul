# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 23:13:11 by jgim              #+#    #+#              #
#    Updated: 2022/01/25 23:13:13 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

SRCS	=	main.cpp \
			phonebook.cpp \
			contact.cpp \

OBJS	=	$(SRCS:.c=.o)

CC		=	clang++ -std=c++98

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) $(NAME)

fclean	:
			$(RM) $(NAME)

re		:	fclean all

