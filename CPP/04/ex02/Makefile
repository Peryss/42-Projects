SRCS        = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ         = ${SRCS:.cpp=.o}
DEPS        = ${SRCS:.cpp=.d}

NAME        = ex02

CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -g -std=c++98 -MP -MD

all:        ${NAME}

%.d: ;

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

