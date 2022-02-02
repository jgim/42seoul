# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 03:07:40 by jgim              #+#    #+#              #
#    Updated: 2022/02/01 03:07:41 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Game

SRCS	=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \

OBJS	=	$(SRCS:.cpp=.o)

CXX 	= clang++

CXXFLAGS = -Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(OBJS)
			$(RM) $(NAME)

re		:	fclean all
