SRCS        = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ         = ${SRCS:.cpp=.o}

NAME        = scavtrap

CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -g -std=c++98 -pedantic

all:        ${NAME}

.cpp.o:
	${CPP} ${CPPFLAGS} -c $< -o $@

${NAME}:    ${OBJ}
	${CPP} ${CPPFLAGS} -o ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean:     clean
	rm -f ${NAME}

re:         fclean all

.PHONY:     all clean fclean re
