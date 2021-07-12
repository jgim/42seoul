NAME	= cub3d

SRC_NAME = main2.c \

SRC_PATH = ./
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

SCREENSHOT = screenshot.bmp

HEADER	= -I./includes

CFLAG	= -Wall -Wextra -Werror

#LIBFT	= libft.a

LIBMLX	= libmlx.a

MLX	= -framework OpenGL -framework Appkit

LIBS = -L./minilibx -lmlx

RM	= rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBMLX)
	gcc -o $(NAME) $(OBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)

#$(LIBFT):
#	$(MAKE) -C lib/libft

$(LIBMLX):
	$(MAKE) -C minilibx

clean	:
	#$(MAKE) -C lib/libft clean
	$(MAKE) -C minilibx clean
	rm -rf $(OBJ_PATH) $(SCREENSHOT)

#fclean	: clean
#	$(MAKE) -C lib/libft fclean
#	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re