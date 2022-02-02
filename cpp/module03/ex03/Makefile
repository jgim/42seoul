# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 03:08:46 by jgim              #+#    #+#              #
#    Updated: 2022/02/01 03:08:48 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Game

SRCS	=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \
			DiamondTrap.cpp \

OBJS	=	$(SRCS:.cpp=.o)

CXX 	= clang++

CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(OBJS)
			$(RM) $(NAME)

re		:	fclean all
