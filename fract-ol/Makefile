# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvass <pvass@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 14:01:44 by pvass             #+#    #+#              #
#    Updated: 2024/06/12 17:13:55 by pvass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
LIBFT_PATH	= include/libft

SRC_DIR		= srcs
OBJ_DIR		= obj
INCLUDE_DIR	= include

SRC_FILES	= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LIBFT		= $(LIBFT_PATH)/libft.a

MLX_DIR 	= ./minilibx-linux
MLX_FLAGS 	= -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm

NAME		= fractol

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
