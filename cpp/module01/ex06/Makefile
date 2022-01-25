NAME	=	karen

SRCS	=	main.cpp \
			Karen.cpp

OBJS	=	$(SRCS:.c=.o)

CC		=	clang++ -std=c++98

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

fclean	:
			$(RM) $(NAME)

re		:	fclean all

