# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/22 18:32:09 by jgim              #+#    #+#              #
#    Updated: 2021/08/22 18:32:14 by jgim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER				=	server
CLIENT				=	client

BONUS_SERVER		=	bonus_server
BONUS_CLIENT		=	bonus_client

SERVER_SRC			= 	minitalk/server.c	\
						minitalk/utility.c

CLIENT_SRC 			=	minitalk/client.c	\
						minitalk/utility.c

BONUS_SERVER_SRC	= 	minitalk_bonus/server_bonus.c	\
						minitalk_bonus/utility_bonus.c

BONUS_CLIENT_SRC 	=	minitalk_bonus/client_bonus.c	\
						minitalk_bonus/utility_bonus.c

SERVER_OBJ			=	$(SERVER_SRC:.c=.o)
CLIENT_OBJ			=	$(CLIENT_SRC:.c=.o)

BONUS_SERVER_OBJ	=	$(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJ	=	$(BONUS_CLIENT_SRC:.c=.o)

CC					=	gcc

FLAGS				=	 -Wall -Werror -Wextra

RM					=	rm -f

all					:	$(SERVER) $(CLIENT)

$(SERVER)			:	$(SERVER_OBJ)
		$(CC) $(FLAGS) $(SERVER_OBJ) -o $(SERVER)

$(CLIENT)			:	$(CLIENT_OBJ)
		$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(CLIENT)

bonus				:	$(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_SERVER)		:	$(BONUS_SERVER_OBJ)
		$(CC) $(FLAGS) $(BONUS_SERVER_OBJ) -o $(BONUS_SERVER)

$(BONUS_CLIENT)		:	$(BONUS_CLIENT_OBJ)
		$(CC) $(FLAGS) $(BONUS_CLIENT_OBJ) -o $(BONUS_CLIENT)

clean				:
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_CLIENT_OBJ) $(BONUS_SERVER_OBJ)

fclean				:
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		$(RM) $(SERVER) $(CLIENT)
		$(RM) $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ)
		$(RM) $(BONUS_SERVER) $(BONUS_CLIENT)


re					:	fclean all

bonus_re			:	fclean bonus
