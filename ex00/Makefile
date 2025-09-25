PROJ=megaphone

NAME=${PROJ}.a

CXX=c++

SRC_FILES=${PROJ}.cpp

OBJ_FILES=${PROJ}.o

AR=	ar rcs

CFLAGS= -Wall -Wextra -Werror

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



