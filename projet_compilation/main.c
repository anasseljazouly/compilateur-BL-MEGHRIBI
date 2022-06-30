#include "analyseur_lexical.h"
#include "analyseur_syntaxique.h"
#include "analyseur_semantique.h"
int main()
{

/**************************************************************** L'ouverture du fichier *****************************************************************/
program = fopen("C:/Users/Asmaa/Desktop/projet_compilation/test.txt", "r");
if(program == NULL){
        perror("Error while opening the file");
        exit(1);
}

/**************************************************************** Le résultat de l'analyseur lexical *****************************************************/
        NextChar();
        getToken();
        printf("\nAnalyseur lexical:La liste des Tokens\n");
    do{
         // l'affichage du résultat de l'analyseur lexical
         printf("%s_token\n",currentToken.name);
         insertion_syntax(currentToken.name,currentToken.value);
         insertion_semant1(currentToken.name,currentToken.value);
         insertion_semant2(currentToken.name,currentToken.value);
         getToken();
    }while(strcmp(currentToken.name,"EOF"));
/**************************************************************** Le résultat de l'analyseur syntaxique *****************************************************/
   afficherListe_syntax(chaine_syntax);
   PROGRAM();
   if(chaine_syntax==NULL) printf("\nBRAVO!!!\n");
 /*************************************************************** Le résultat de l'analyseur sémantique *************************************************/
//afficherListe_syntax(chaine_semant1);
//afficherListe_syntax(chaine_semant2);
table_symb(chaine_semant1);
afficherListe_tab_sym(chaine_tab_symb);
check(chaine_semant2);
}
