CSRC= *.c
COBJ= $(CSRC:.c=.o)
EXEC= shell
CC= gcc -Wall -Wextra -O2

all:: obj
	${CC} -o ${EXEC} ${COBJ}
	@echo
	@echo
	@echo ======== MAKE OCAML ========
	make ocaml

obj::
	${CC} -c ${CSRC}

out:: all
	mkdir out
	cp ${EXEC} *.txt fun_display out/
	make clean

clean::
	rm -f *.o *~ ${EXEC}
	rm -f fun_display

ocaml::
	cd fun_displayo && make
	cp fun_displayo/fun_display ./
	cd fun_displayo && make clean
