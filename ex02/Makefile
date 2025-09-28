PROJ=Account

NAME=${PROJ}.a

CXX=c++

SRC_FILES=${PROJ}.cpp tests.cpp

OBJ_FILES=${PROJ}.o tests.o

AR=	ar rcs

CXXFLAGS= -Wall -Wextra -Werror -std=c++98

all: ${PROJ}

$(PROJ): ${SRC_FILES} ${OBJ_FILES}
	$(CXX) ${OBJ_FILES} -o ${PROJ}

clean:
	rm -fr $(OBJ_FILES)

fclean: clean
	rm -fr ${PROJ}

re: fclean all

r: re
	./${PROJ}

val: re
	clear
	valgrind --leak-check=full --trace-children=yes --show-leak-kinds=all ./${PROJ}

.PHONY: re fclean clean all val r

# so:



