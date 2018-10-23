# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obaranni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 15:44:29 by obaranni          #+#    #+#              #
#    Updated: 2018/10/23 13:19:12 by obaranni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in 

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./headers/

LIB_DIR = ./libft/

LIBFT = $(LIB_DIR)libft.a

SRC =		lem_in.c					\
#			free.c						\
			reader/reader.c				\
			validator/validator.c		\
			analizer/analizer.c			\
			responder/responder.c		\
			visualizer/visualizer.c		\
			parser/parser.c				\
			parser/parse_figure.c    	\
			parser/parse_map.c			\
			analizer/set_priorities.c   \
			analizer/brute_force.c		\
			parser/cut_figure.c			\
			journalist/logbook.c		\

OBJ = $(SRC:.c=.o)

SRC_FILES =	$(addprefix $(SRC_DIR),$(SRC))

OBJ_FILES =	$(addprefix $(OBJ_DIR),$(OBJ))

COMPALING_FLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR)# `pkg-config --cflags gtk+-3.0`

LINKING_FLAGS = -framework opengl -framework appkit -lft -L$(LIB_DIR) # -lmlx -L minilibx_macos `pkg-config --libs --cflags gtk+-3.0`

CC = gcc

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(LINKING_FLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(COMPALING_FLAGS) -o $@ -c $<

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir obj
	mkdir obj/reader
	mkdir obj/validator
	mkdir obj/visualizer
	mkdir obj/analizer
	mkdir obj/responder
	mkdir obj/parser
	mkdir obj/journalist

$(LIBFT):
	make -C $(LIB_DIR)


clean:
	rm -rf $(OBJ_FILES)
	make clean -C $(LIB_DIR)


fclean: clean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
