
#ifndef ANAL_SYN
#define ANAL_SYN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lenValue    20
#define lenName     20
#include "analyseur_syntaxique.h"

typedef struct Ident Ident;
struct Ident{
char name[20];
char value[20];
char tidf[20];
int taille_tab_fct;
Ident *suivant;
};
Ident* chaine_tab_symb;

Element* chaine_semant1;
Element* chaine_semant2 ;











#endif
