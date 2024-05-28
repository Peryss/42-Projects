# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvass <pvass@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 14:01:44 by pvass             #+#    #+#              #
#    Updated: 2024/05/28 14:14:59 by pvass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
LIBFT_PATH	= include/libft
MLX_PATH	= include/minilibx-linux

SRC_DIR		= src
OBJ_DIR		= obj
INCLUDE_DIR	= include

SRC_FILES	= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LIBFT		= $(LIBFT_PATH)/libft.a
MLX			= $(MLX_PATH)/libmlx.a

NAME		= fractol

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lGL -lm -lX11

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	rm -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm ${NAME}

re: fclean all

.PHONY: all clean fclean re