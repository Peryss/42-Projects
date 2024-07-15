# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvass <pvass@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:51:02 by pvass             #+#    #+#              #
#    Updated: 2024/06/20 17:36:13 by pvass            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c input_handling.c input_handling_utils.c do_command.c \
				first_cmd.c first_family.c last_family.c

BON_SRC		= main_bonus.c here_doc_errors_bonus.c here_doc_utils_bonus.c input_handling.c \
				input_handling_utils.c do_command.c first_cmd.c first_family.c \
				mid_family_bonus.c last_family.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

BON_SRCS	= ${addprefix ${BON_PRE}, ${BON_SRC}}

OBJ			= ${SRCS:.c=.o}

BON_OBJ		= ${BON_SRCS:.c=.o}

PRE			= ./srcs/

BON_PRE		= ./srcs/

INCLUDE		= ./srcs/pipex.h

NAME		= pipex

BON_NAME	= pipexbonus

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
			rm -f ${BON_OBJ}
			@cd $(PRINTFDIR) && $(MAKE) clean

fclean:		clean
			rm -f ${NAME} ${BON_NAME}
			@cd $(PRINTFDIR) && $(MAKE) fclean

re:			fclean all

bonus:		${BON_OBJ} ${PRINTF_LIB}
				${CC} ${CFLAGS} -o ${BON_NAME} ${BON_OBJ} -L${PRINTFDIR} -lftprintf


.PHONY:		all clean fclean re bonus