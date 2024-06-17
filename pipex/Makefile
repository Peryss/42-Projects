# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvass <pvass@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:51:02 by pvass             #+#    #+#              #
#    Updated: 2024/06/14 13:22:54 by pvass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJ			= ${SRCS:.c=.o}

PRE			= ./srcs/

INCLUDE		= ./srcs/pipex.h

NAME		= pipex

PRINTFDIR	= ./ft_printf

PRINTF_LIB  = ${PRINTFDIR}/libftprintf.a

CC			= cc -g

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