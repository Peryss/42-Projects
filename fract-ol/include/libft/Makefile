SRC			= ft_substr.c ft_strjoin.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

BONSRC		= ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c

BONSRCS		= ${addprefix ${PRE}, ${BONSRC}}

OBJ			= ${SRCS:.c=.o}

BONOBJ		= ${BONSRCS:.c=.o}

PRE			= ./

BONPRE		= ./

HEAD		= ./

NAME		= libft.a

AR			= ar rcs

LIB			= ranlib

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD}  $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			${AR} ${NAME} ${OBJ}

clean:
			rm -f ${OBJ}
			rm -f ${BONOBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

bonus:		${BONOBJ} ${OBJ}
			${AR} ${NAME} ${BONOBJ} ${OBJ}

.PHONY:		all clean fclean re
