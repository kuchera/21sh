CSRC= *.c
COBJ= $(CSRC:.c=.o)
EXEC= shell
CC= gcc -Wall -Wextra -O2

all:: obj
	${CC} -o ${EXEC} ${COBJ}

obj::
	${CC} -c ${CSRC}

out:: all
	rm -rf out/
	mkdir out
	cp ${EXEC} *.txt out/
	rm -f *.o *~ ${EXEC}

clean::
	rm -rf out
	rm -f *.o *~ ${EXEC}
