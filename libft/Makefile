# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obaranni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 11:12:50 by obaranni          #+#    #+#              #
#    Updated: 2018/08/06 12:53:32 by obaranni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = ./src/

OBJ_DIR = ./obj/

HEADER_DIR = ./inc/

SRC = $(shell ls src)

OBJ = $(SRC:.c=.o)

SRC_FILES = $(addprefix $(SRC_DIR),$(SRC))

OBJ_FILES = $(addprefix $(OBJ_DIR),$(OBJ))

COMPALING_FLAGS = -I$(HEADER_DIR) -Wall -Wextra -Werror

CC = gcc

all:$(OBJ_FILES) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	$(CC) $(COMPILING_FLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR)
	 ar rc $(NAME) $(OBJ_FILES) $(OBJ_LIB_FILES)


$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)

re: fclean all
