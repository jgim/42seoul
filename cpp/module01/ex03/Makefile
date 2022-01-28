# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 02:48:06 by jgim              #+#    #+#              #
#    Updated: 2022/01/29 02:48:08 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	weapon

SRCS	=	main.cpp \
			HumanA.cpp \
			HumanB.cpp \
			Weapon.cpp

OBJS	=	$(SRCS:.c=.o)

CXX			=	clang++ -std=c++98

CXXFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

fclean	:
			$(RM) $(NAME)

re		:	fclean all

