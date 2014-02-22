#ifndef MATCH_DEFINE
#define MATCH_DEFINE

/*
 * Fonction de gestion des joker (*)
 * La chaine s1 peut contenir des joker (s2 sans)
 * La fonction retourne 1 si la chaine s1 correspond a la chaine s2, 0 si non
 */
int match_joker(const char *s1, const char *s2);

#endif
