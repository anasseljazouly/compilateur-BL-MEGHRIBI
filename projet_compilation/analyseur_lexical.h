#ifndef ANAL_LEX
#define ANAL_LEX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* keywords_list[];
extern const char* specialTokens_list[];
extern const char* specialTokens_symb[];
int keywords_list_size;
int specialTokens_list_size;
int testguill;
int nbreguill;
#define MAXDIGIT 11
#define MAXCHAR  20
#define NBRKEYWORDS         keywords_list_size
#define NBRSPECIALTOKENS    specialTokens_list_size
#define lenValue    20
#define lenName     20
/**************** créer un type qui retourne un booléan *************************/
typedef enum{FALSE, TRUE} bool;
/*********************** Le pointeur du fichier *********************************/
FILE* program ;
/*********************** La structre d'un Token *********************************/
typedef struct{
    char name[lenName];
    char value[lenValue];
} Token;
/******************************************************************************** La déclaration **********************************************************************************************/
char currentChar;
Token currentToken;
char NextChar();// retourne le prochain caractére dans le fichier
void LexError();// affiche un message d'erreur et sortir
Token getToken();
void ignoreWhiteSpaces();
bool isNumber();
bool isWord();
bool isSpecial();

#endif
