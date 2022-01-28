# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 02:48:38 by jgim              #+#    #+#              #
#    Updated: 2022/01/29 02:48:39 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	replace

SRCS	=	main.cpp \
			Replace.cpp

OBJS	=	$(SRCS:.c=.o)

CXX			=	clang++ -std=c++98

CXXFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) *.txt
			$(RM) *.replace

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

