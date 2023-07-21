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

NAME    	= pipex
CC      	= gcc
CFLAGS  	= -Werror -Wextra -Wall
LDFLAGS 	= -Llibft -lft

SRC_PATH    = src/
OBJ_PATH    = obj/
LIBFT_PATH  = libft/

SRC         = get_exe_args.c pipex.c
SRCS        = $(addprefix $(SRC_PATH), $(SRC))

OBJ         = $(SRC:.c=.o)
OBJS        = $(addprefix $(OBJ_PATH), $(OBJ))

INC         = -I ./include/

all: $(LIBFT_PATH)libft.a $(OBJ_PATH) $(NAME)

$(LIBFT_PATH)libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
