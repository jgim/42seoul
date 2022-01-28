# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 02:45:44 by jgim              #+#    #+#              #
#    Updated: 2022/01/29 02:45:58 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	zombie

SRCS		=	main.cpp \
				newZombie.cpp \
				randomChump.cpp \
				Zombie.cpp


OBJS		=	$(SRCS:.c=.o)

CXX			=	clang++ -std=c++98

CXXFLAGS	=	-Wall -Werror -Wextra

RM			=	rm -f

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

fclean		:
				$(RM) $(NAME)

re			:	fclean all

