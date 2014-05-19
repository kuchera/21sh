open Genlex

type tree =
| Nb of int
| Op of tree * string * tree

let power n e =
	if e = 0 then 1 else
	let k = ref 1 in
	for i = 1 to e do
		k := !k * n
	done;
	!k

let fact gauche =
	if gauche = 0 then 1 else
	let k = ref 1 in 
	for i = 1 to gauche do 
		k := !k * i
	done;
	!k

let lexer str =
    let rec minus = parser
        | [< ''-'; s >] -> [< ''-'; '' '; minus s >]
        | [< 'a; s >] -> [< 'a; minus s >]
        | [< >] -> [< >] in
    let keywords = ["("; ")"; "+"; "-"; "*"; "/"; "^"] in
    make_lexer keywords (minus(Stream.of_string str))


let parseur lexer = 
     let op_parser op_list next_level =
        let rec aux gauche next_level = parser
             [<'Kwd op when List.mem op op_list; droite = next_level; s >] -> aux (Op (gauche, op, droite)) next_level s
            | [< >] -> gauche
        in parser [< gauche = next_level; s >] -> aux gauche next_level s
     in
     let rec ope_low l = op_parser ["+"; "-"] ope_high l
     	and ope_high l = op_parser ["*"; "/"; "^"] pth l
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
    | "^" -> power gauche droite
    | _ -> failwith "Fonction non connue."

let main () = 
   
    if Array.length (Sys.argv) < 2 then
        let c = ref "" in
        Printf.printf "Bienvenue dans la calculatrice 21SH.\nPour quitter veuillez taper \"quit\", \"exit\" ou \"q\".\n>";
	c := read_line();
    	while(true) do
	  if !c = "quit" || !c = "exit" || !c = "q" then 
	  begin
	        Printf.printf "Calculatrice quittée\n";
		exit 0
	  end;
	
	  begin
		try
    		let r = execute (parseur (lexer !c)) in
    			print_int r;
		with
	  		_ ->Printf.printf "expression invalide"
	  end;
    		Printf.printf "\n>";
    		c := read_line();
    	  done
    else
	  let c = ref "" in
	  for i = 1 to (Array.length (Sys.argv))-1 do
	 	c := !c ^ Sys.argv.(i)
	  done;
	  begin
	  try
		let r = execute (parseur (lexer !c)) in
			print_int r;
	  with
	  	_ -> Printf.printf "expression invalide"
	  end;
		Printf.printf "\n";
    exit 0

let _ = main ()
