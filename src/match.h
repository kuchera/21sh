#ifndef MATCH_DEFINE
#define MATCH_DEFINE

#include <string.h>
#include "my_tab.h"
#include "my_charwork.h"
#include "env.h"
#include "fun_ls.h"

/*
 * Effectue les traitements de reconnaissance
 * Modifie le tableau
 */
void match(my_tab argv);
/*
 * Fonction de gestion des joker (*)
 */
void match_joker(my_tab argv);
/*
 * Gere les expressions entre guillemets
 * ex : cat "mon fichier.txt"
 * (les elements de tab pourront etre supprimes)
 */
void match_quotes(my_tab tab);

#endif
