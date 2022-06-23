TARGET = tester.out
INC = ./include
SRC = main.cpp ex00.cpp ex01.cpp ex02.cpp ex03.cpp ex04.cpp ex05.cpp ex06.cpp ex07.cpp ex08.cpp ex09.cpp ex10.cpp ex11.cpp
SRCDIR = ./src
OBJ = ${SRC:.cpp=.o}

CC = g++
CFLAGS = -Wall -Wextra -g# -Werror

%.o: ${SRCDIR}/%.cpp
	${CC} ${CFLAGS} -I ${INC} -c $< -o $@

${TARGET}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o $@

all: ${TARGET}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${TARGET}

re: fclean all

.PHONY: all clean fclean re
