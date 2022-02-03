# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 17:03:45 by jgim              #+#    #+#              #
#    Updated: 2022/02/03 17:03:47 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	convert

SRCS	=	main.cpp \
			Convert.cpp \

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
