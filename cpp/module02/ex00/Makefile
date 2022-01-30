NAME		=	fixed

SRCS		=	main.cpp \
				Fixed.cpp

OBJS		=	$(SRCS:.c=.o)

CXX			=	clang++

CXXFLAGS	=	-Wall -Werror -Wextra

RM			=	rm -f

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean		:
				$(RM) $(NAME)

fclean		:
				$(RM) $(NAME)

re			:	fclean all

