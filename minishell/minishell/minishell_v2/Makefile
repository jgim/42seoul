# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 11:46:41 by silim             #+#    #+#              #
#    Updated: 2021/09/26 14:58:51 by silim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c \
			srcs/run_shell.c \
			srcs/check_syntax.c \
			srcs/history.c \
			srcs/read_key.c \
			srcs/parse_cmd.c \

OBJ		=	$(SRCS:.c=.o)
NAME	=	minishell
CC		=	gcc -Wall -Werror -Wextra
LIBFT	=	./libft/libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJ)
		make all -C libft/
		$(CC) $(OBJ) $(LIBFT) -o $(NAME)

clean	:
			rm -f $(OBJ)
			make clean -C libft/

fclean	:
			rm -f $(OBJ)
			rm -f $(NAME)
			make fclean -C libft/

re		:	fclean all

.PHONY	:	all clean fclean re
