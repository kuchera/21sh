CSRC= *.c
COBJ= $(CSRC:.c=.o)
EXEC= shell
CC= gcc -Wall -Wextra -O2

all:: obj
	${CC} -o ${EXEC} ${COBJ}
	make ocaml >> /dev/null

obj::
	${CC} -c ${CSRC}

out:: all
	mkdir out
	cp ${EXEC} *.txt fun_display out/
	make clean

clean::
	rm -f *.o *~ ${EXEC}
	rm -f fun_display
	rm -f fun_calc

ocaml::
	#DISPLAY
	cd fun_displayo && make
	cp fun_displayo/fun_display ./
	cd fun_displayo && make clean
	#CALCULATRICE
	cd calculatrice && make
	cp calculatrice/calculatrice fun_calc
	cd calculatrice && make clean
