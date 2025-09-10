SRCS        = main.cpp Bureaucrat.cpp
OBJ         = ${SRCS:.cpp=.o}
DEPS		= $(OBJ:.o=.d)

NAME        = ex00

CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -g -std=c++98 -MD -MP

-include $(DEPS)

all:        ${NAME}

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
