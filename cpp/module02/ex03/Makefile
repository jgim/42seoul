# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:07:30 by jgim              #+#    #+#              #
#    Updated: 2022/01/31 01:07:31 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Bsp

SRCS	=	main.cpp \
			Fixed.cpp \
			Point.cpp \
			Bsp.cpp

OBJS	=	$(SRCS:.c=.o)

CXX			=	clang++

CXXFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

fclean	:
			$(RM) $(NAME)

re		:	fclean all

