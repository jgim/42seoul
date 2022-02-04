# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 18:24:16 by jgim              #+#    #+#              #
#    Updated: 2022/02/04 18:24:17 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex02

SRCS	=	main.cpp \
			mutantstack.cpp \

OBJS	=	$(SRCS:.cpp=.o)

CXX 	= clang++

CXXFLAGS = -Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean	:
		$(RM) $(OBJS) $(NAME)

re		:	fclean all
