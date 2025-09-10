SRCS        = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ         = ${SRCS:.cpp=.o}
DEPS		= $(OBJ:.o=.d)

NAME        = ex03

CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -g -std=c++98 -MD -MP

all:        ${NAME}

%.d: ;

-include $(DEPS)

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
