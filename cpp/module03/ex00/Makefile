# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 03:06:14 by jgim              #+#    #+#              #
#    Updated: 2022/02/01 03:06:16 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Game

SRCS	=	main.cpp \
			ClapTrap.cpp

OBJS	=	$(SRCS:.c=.o)

CXX		=	clang++

CXXFLAGS = -Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
fclean	:
			$(RM) $(NAME)

re		:	fclean all
