SRCS        = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ         = ${SRCS:.cpp=.o}
DEPS        = ${SRCS:.cpp=.d}

NAME        = fixed

CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -g -std=c++98 -pedantic -MMD

all:        ${NAME}

-include ${DEPS}

.cpp.o:
	${CPP} ${CPPFLAGS} -c $< -o $@

${NAME}:    ${OBJ}
	${CPP} ${CPPFLAGS} -o ${NAME} ${OBJ}

clean:
	rm -f ${OBJ} ${DEPS}

fclean:     clean
	rm -f ${NAME}

re:         fclean all

.PHONY:     all clean fclean re
