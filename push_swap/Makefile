# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvass <pvass@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:51:02 by pvass             #+#    #+#              #
#    Updated: 2024/05/25 10:01:53 by pvass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= push_swap1.c push_swap2.c push_swap3.c free_push.c rr_comb.c rrr_comb.c stack_op.c stack_op2.c main.c utils1.c utils2.c utils3.c utils4.c input.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJ			= ${SRCS:.c=.o}

PRE			= ./srcs/

INCLUDE		= ./srcs/push_swap.h

NAME		= push_swap

PRINTFDIR	= ./ft_printf

PRINTF_LIB  = ${PRINTFDIR}/libftprintf.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${PRINTF_LIB}
				${CC} ${CFLAGS} -o ${NAME} ${OBJ} -L${PRINTFDIR} -lftprintf

${PRINTF_LIB}:
			make -C ${PRINTFDIR}

clean:
			rm -f ${OBJ}
			@cd $(PRINTFDIR) && $(MAKE) clean

fclean:		clean
			rm -f ${NAME}
			@cd $(PRINTFDIR) && $(MAKE) fclean

re:			fclean all

.PHONY:		all clean fclean re