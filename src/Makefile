CSRC= *.c
COBJ= $(CSRC:.c=.o)
EXEC= shell
CC= gcc -Wall -Wextra -std=c99 -O2

all:: obj
	${CC} -o ${EXEC} ${COBJ}

obj::
	${CC} -c ${CSRC}

out:: all
	rm -f *.o *~

clean::
	rm -f *.o *~ ${EXEC}
