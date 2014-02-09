#ifndef COMMAND_H
#define COMMAND_H

#include <stdlib.h>
#include <stdio.h>

typedef struct command *command;
struct command
{
	int argc;
	char **argv;
};

// Renvoie une commande vide
command c_new();
// Parse l'entree str
command c_parse(char *str);
// Affiche une commande (tests)
void c_print(command c);
// Libere la commande
void c_free(command c);

#endif
