# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvass <pvass@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:44:51 by pvass             #+#    #+#              #
#    Updated: 2024/10/28 16:05:06 by pvass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	srcs/main.c \
				srcs/init.c \
				srcs/input.c \
				srcs/utils.c \
				srcs/ft_strncmp.c \
				srcs/threads.c \
				srcs/routine.c
				
SRCS		= ${SRC}

OBJ			= ${SRCS:.c=.o}

INCLUDE		= ./srcs/philosophers.h

NAME		= philo

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