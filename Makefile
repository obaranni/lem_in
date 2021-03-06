# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obaranni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 15:44:29 by obaranni          #+#    #+#              #
#    Updated: 2018/12/06 16:25:13 by obaranni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in 

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./headers/

LIB_DIR = ./libft/

LIBFT = $(LIB_DIR)libft.a

SRC =		lem_in.c					\
			add_room.c					\
			reader.c					\
			free.c						\
			free2.c						\
			reader_links.c				\
			set_error.c					\
			reader_ants.c				\
			bfs.c						\
			connect_rooms.c				\
			create_packages.c			\
			check_arguments.c			\
			get_file.c					\
			print.c						\
			print2.c					\
			print3.c					\
			get_best_package.c			\
			create_ants.c				\
			move_ants.c					\
			set_ants_on_ways.c			\
			set_packages_capacity.c		\
			ants_preparation.c			\
			package_preparation.c		\
			inits.c						\
			work_with_packages.c		\
			work_with_room_functions.c	\
			work_with_way_functions.c	\
			help_functions.c			\
			is_enough_data.c			\
			is_it_error.c				\
			room_validate.c				\
			reader_room.c				

OBJ = $(SRC:.c=.o)

SRC_FILES =	$(addprefix $(SRC_DIR),$(SRC))

OBJ_FILES =	$(addprefix $(OBJ_DIR),$(OBJ))


COMPALING_FLAGS = -I$(INC_DIR) -I$(LIB_DIR) -Wall -Wextra -Werror # `pkg-config --cflags gtk+-3.0`

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
