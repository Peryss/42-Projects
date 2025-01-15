# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvass <pvass@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:44:51 by pvass             #+#    #+#              #
#    Updated: 2024/12/11 17:57:19 by pvass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	srcs/main.c \
				srcs/init.c \
				srcs/input.c \
				srcs/utils.c \
				srcs/ft_strncmp.c \
				srcs/threads.c \
				srcs/routine.c \
				srcs/mutex_users.c \
				srcs/observer.c \
				srcs/cleanup.c
				
SRCS		= ${SRC}

OBJ			= ${SRCS:.c=.o}

INCLUDE		= ./srcs/philosophers.h

NAME		= philo

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

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

thread:		${OBJ}
				${CC} ${CFLAGS} -o ${NAME} ${OBJ} # -fsanitize=thread -g -O1 -lpthread

.PHONY:		all clean fclean re