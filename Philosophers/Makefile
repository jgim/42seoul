NAME	=	philo

SRCS	=	main.c \
			data_management \
			eat.c \
			philsopher.c \
			print.c \
			time.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

LIBFT	=	./libft/libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(OBJS)
			$(RM) $(NAME)

re		:	fclean all
