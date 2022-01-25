NAME	=	replace

SRCS	=	main.cpp \
			replace.cpp

OBJS	=	$(SRCS:.c=.o)

CC		=	clang++ -std=c++98

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) *.txt
			$(RM) *.replace

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

