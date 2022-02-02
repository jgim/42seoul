# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 20:20:05 by jgim              #+#    #+#              #
#    Updated: 2022/02/02 20:20:06 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex00

SRCS	=	main.cpp \
			Bureaucrat.cpp \

OBJS	=	$(SRCS:.cpp=.o)

CXX = clang++

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
