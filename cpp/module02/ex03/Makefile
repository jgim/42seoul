NAME	=	Bsp

SRCS	=	main.cpp \
			Fixed.cpp \
			Point.cpp \
			Bsp.cpp

OBJS	=	$(SRCS:.c=.o)

CXX			=	clang++

CXXFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

fclean	:
			$(RM) $(NAME)

re		:	fclean all

