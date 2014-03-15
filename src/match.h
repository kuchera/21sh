#ifndef MATCH_DEFINE
#define MATCH_DEFINE

#include <string.h>
#include "my_tab.h"
#include "my_charwork.h"

/*
 * Effectue les traitements de reconnaissance
 * Modifie le tableau
 */
void match(my_tab argv);
/*
 * Fonction de gestion des joker (*)
 * La chaine s1 peut contenir des joker (s2 sans)
 * La fonction retourne 1 si la chaine s1 correspond a la chaine s2, 0 si non
 */
int match_joker(const char *s1, const char *s2);
/*
 * Gere les expressions entre guillemets
 * ex : cat "mon fichier.txt"
 * (les elements de tab pourront etre supprimes)
 */
void match_quotes(my_tab tab);

#endif
