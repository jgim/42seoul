# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:06:35 by jgim              #+#    #+#              #
#    Updated: 2022/01/31 01:06:37 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fixed

SRCS	=	main.cpp \
			Fixed.cpp

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

