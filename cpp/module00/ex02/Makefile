# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 23:14:20 by jgim              #+#    #+#              #
#    Updated: 2022/01/25 23:14:21 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Account

SRCS		=	Account.cpp \
				tests.cpp \

OBJS		=	$(SRCS:.c=.o)

CXX			=	clang++ -std=c++98

CXXFLAGS	=	-Wall -Werror -Wextra

RM			=	rm -f

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean		:
				$(RM) $(NAME)

fclean		:
				$(RM) $(NAME)

re			:	fclean all

