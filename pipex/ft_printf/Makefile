# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvass <pvass@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:51:02 by pvass             #+#    #+#              #
#    Updated: 2024/04/15 17:28:58 by pvass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_countres.c ft_hexupdown.c ft_putpointer.c ft_putunsigned.c ft_printf.c get_next_line.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

LIBFT		= libft

OBJ			= ${SRCS:.c=.o}

BONOBJ		= ${BONSRCS:.c=.o}

PRE			= ./

HEAD		= ./includes

NAME		= libftprintf.a

AR			= ar rcs

LIB			= ranlib

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD}  $< -o ${<:.c=.o}

${NAME}: ${OBJ}

			make -C ${LIBFT}
			cp libft/libft.a ${NAME}
			${AR} ${NAME} ${OBJ}

clean:
			rm -f ${OBJ}
			make clean -C ${LIBFT}

fclean:		clean
			rm -f ${NAME}
			rm -f libft.a
			rm -f ${LIBFT}/libft.a

re:			fclean all

.PHONY:		all clean fclean re
