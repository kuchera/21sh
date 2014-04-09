#ifndef COLOR_DEFINE
#define COLOR_DEFINE

#include <stdio.h>
 
#define BLEUCLAIR "\033[01;34m"
#define ROUGE "\033[00;31m"
#define BLEU "\033[00;34m"
#define SOULIGNE "\033[04m"
#define NORMAL "\033[00m"

// Efface l'écran et replace le curseur en haut à gauche
#define clearscreen() printf("\033[H\033[2J")

// Sélection de couleurs
#define setcolor(param) printf("\033[%sm",param)

#endif
