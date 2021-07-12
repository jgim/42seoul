NAME = libftprintf.a

SRC = ft_basic.c \
	ft_c_s_d_i.c\
	ft_flag.c \
	ft_glue_group.c \
	ft_itoa_group.c \
	ft_prec_width_join.c \
	ft_printf.c \
	ft_type.c \
	ft_u_x_p.c \

CC = gcc

RM = rm -rf

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_Bonus:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	    	ar rcs $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ) $(OBJ_B)

fclean : clean
		$(RM) $(NAME)

re : fclean all
