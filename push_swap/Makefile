# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvass <pvass@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:51:02 by pvass             #+#    #+#              #
#    Updated: 2024/05/16 18:30:11 by pvass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= push_swap.c free_push.c rr_comb.c rrr_comb.c stack_op.c main.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJ			= ${SRCS:.c=.o}

PRE			= ./srcs/

INCLUDE		= push_swap.h ft_printf.h libft.h

NAME		= push_swap

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
				${CC} ${CFLAGS} -o ${NAME} ${OBJ} 

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

.PHONY: all clean fclean re bonus