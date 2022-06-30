#ifndef ANAL_SYN
#define ANAL_SYN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lenValue    20
#define lenName     20
#include "analyseur_lexical.h"

typedef struct Element Element;
struct Element
{    char name[lenName];
     char value[lenValue];
     Element *suivant;
};

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
Element* chaine_syntax;
void insertion_syntax(char* ,char* );
void afficherListe_syntax(Element* );
bool verifyToken(char *);
void PROGRAM();
void SyntaxError();
void DEF();
void CONSTS();
void CONSTID();
void ALPHA();
void TABCONST();
void VAR();
void VARS();
void ALPHANUM();
void FONCTION();
void BLOCK();
void INSTS();
void INST();
void AFFECT();
void AFFEC();
void EXPR1();
void AFFECTAB();
void AFFEC2();
void SI();
void ECRIRE();
void ECRIREA();
void ECRIREB();
void LIRE();
void FOR();
void WHILE();
void SWITCH();
void PARAM();
void EXPR();
void term();
void fact();
void COND();
void APPELFCT();
void APPEL();
void FCTDEC();
void VAL();
void FCTDEFC1();
void FCTDEFC2();
void FCTDEFC3();
void FCTDEFC4();
void FCTDEFC5();
void ARG1();




















#endif
