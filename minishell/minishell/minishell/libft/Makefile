# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 11:46:24 by silim             #+#    #+#              #
#    Updated: 2021/09/24 19:35:08 by silim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_strlen.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strcjoin.c \
			ft_strlcpy.c \
			ft_substr.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			get_next_line.c \
			get_next_line_utils.c \

OBJ		=	$(SRCS:.c=.o)
NAME	=	libft.a
CC		=	gcc -Wall -Werror -Wextra

all		:	$(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all
