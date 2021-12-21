NAME	=	philo

SRCS	=	main.c \
			data_management.c \
			philosopy.c \
			philosopher.c \
			print.c \
			utils.c \

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(OBJS)
			$(RM) $(NAME)

re		:	fclean all
