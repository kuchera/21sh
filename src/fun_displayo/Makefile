OCAML=ocamlopt
OCAMLFLAGS= -I +sdl -I +site-lib/sdl
OCAMLLD= bigarray.cmxa sdl.cmxa sdlloader.cmxa
 
display: display.ml
	${OCAML} ${OCAMLFLAGS} ${OCAMLLD} -o fun_display display.ml
 
clean::
	rm -f *~ *.o *.cm? fun_display
