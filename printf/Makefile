SRC			= ft_countres.c ft_hexupdown.c ft_putpointer.c ft_putunsigned.c ft_printf.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

LIBFTT		= libft

OBJ			= ${SRCS:.c=.o}

BONOBJ		= ${BONSRCS:.c=.o}

PRE			= ./

HEAD		= ./includes

NAME		= printflibft.a

AR			= ar rcs

LIB			= ranlib

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD}  $< -o ${<:.c=.o}

${NAME}: ${OBJ}

			make -C ${LIBFTT}
			cp libft/libft.a .
			move libft.a ${NAME}
			${AR} ${NAME} ${OBJ}

clean:
			rm -f ${OBJ}
			make clean -C ${LIBFTT}

fclean:		clean
			rm -f ${NAME}
			rm -f ${LIBFTT}/libft.a

re:			fclean all

.PHONY:		all clean fclean re
