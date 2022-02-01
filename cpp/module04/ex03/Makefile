# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 22:00:46 by jgim              #+#    #+#              #
#    Updated: 2022/02/01 22:00:47 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex03

SRCS	=	main.cpp \
			AMateria.cpp \
			Character.cpp \
			Cure.cpp \
			Ice.cpp \
			MateriaSource.cpp \

OBJS	=	$(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) $(NAME)

fclean	:
			$(RM) $(OBJS)
			$(RM) $(NAME)

re		:	fclean all
