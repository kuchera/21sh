open Genlex

type tree =
| Nb of int
| Op of tree * string * tree

let lexer str =
    let rec minus = parser
        | [< ''-'; s >] -> [< ''-'; '' '; minus s >]
        | [< 'a; s >] -> [< 'a; minus s >]
        | [< >] -> [< >] in
    let keywords = ["("; ")"; "+"; "-"; "*"; "/"] in
    make_lexer keywords (minus(Stream.of_string str))


let parseur lexer = 
     let op_parser op_list next_level =
        let rec aux gauche next_level = parser
              [<'Kwd op when List.mem op op_list; droite = next_level; s >] -> aux (Op (gauche, op, droite)) next_level s
            | [< >] -> gauche
        in parser [< gauche = next_level; s >] -> aux gauche next_level s
     in
     let rec ope_low l = op_parser ["+"; "-"] ope_high l
     	and ope_high l = op_parser ["*"; "/"] pth l
     	and pth = parser
             | [< 'Kwd "("; e = ope_low; 'Kwd ")" >] -> e
             | [< 'Int n >] -> Nb n
     in ope_low lexer

let rec execute tree = match tree with
| Nb n -> n
| Op(fg, r, fd) ->
    let gauche, droite = execute fg, execute fd in
    match r with
    | "+" -> gauche + droite
    | "-" -> gauche - droite
    | "*" -> gauche * droite
    | "/" -> gauche / droite
    | _ -> failwith "Fonction non connue."

let main () = 
    let c = ref "" in
	c := read_line();
    	while(true) do
	begin
	try
    		let r = execute (parseur (lexer !c)) in
    			print_int r;
	with
	  _ ->Printf.printf "expression invalide"
	end;
    		Printf.printf "\n";
    		c := read_line();
		if !c = "quit" then exit 0;
    	done;

    exit 0

let _ = main ()
