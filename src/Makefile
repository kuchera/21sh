CSRC= *.c
OBJ= *.o
EXEC= shell
CC= gcc -Wall -Wextra -std=c99 -O2

all:: obj
	${CC} -o ${EXEC} ${CSRC}

obj::
	${CC} -c ${CSRC}

clean::
	rm -f *.o *~ ${EXEC}
