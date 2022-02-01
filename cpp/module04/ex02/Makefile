# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 21:57:16 by jgim              #+#    #+#              #
#    Updated: 2022/02/01 21:57:19 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex02

SRCS	=	main.cpp \
			Animal.cpp \
			Dog.cpp \
			Cat.cpp \
			Brain.cpp \
			Bird.cpp \

OBJS	=	$(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror

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
