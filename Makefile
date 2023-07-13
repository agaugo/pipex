# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 16:38:15 by hflohil-          #+#    #+#              #
#    Updated: 2023/06/23 16:38:15 by hflohil-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

SRC_PATH    =   src/
OBJ_PATH    =   obj/

SRC         =	execute.c misc.c pipex.c
SRCS        =   $(addprefix, $(SRC_PATH), $(SRC))

OBJ         =   $(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

INC         =   -I ./include/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re