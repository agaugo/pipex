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

NAME	= pipex
FLAGS	= -Wall -Werror -Wextra -g
COMPILE	= gcc
SRC_DIR		= src/
OBJ_DIR		= obj/

SRC = pipex.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(COMPILE) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re