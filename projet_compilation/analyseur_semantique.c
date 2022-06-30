
#include "analyseur_syntaxique.h"
/******************************************************** La chaine 1 de l'analyseur sémantique ************************************************************/

void insertion_semant1(char* nameToken,char* valueToken)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    strcpy(nouveau->name,nameToken);
    strcpy(nouveau->value,valueToken);
    nouveau->suivant=NULL;
    if(chaine_semant1 == NULL) chaine_semant1=nouveau;
    else {
    Element *actuel = chaine_semant1;
    while(actuel->suivant !=NULL) actuel=actuel->suivant;
     actuel->suivant=nouveau;
    }
}
/******************************************************** La chaine 2 de l'analyseur sémantique ************************************************************/

void insertion_semant2(char* nameToken,char* valueToken)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    strcpy(nouveau->name,nameToken);
    strcpy(nouveau->value,valueToken);
    nouveau->suivant=NULL;
    if(chaine_semant2==NULL) chaine_semant2=nouveau;
    else {
    Element *actuel = chaine_semant2;
    while(actuel->suivant !=NULL) actuel=actuel->suivant;
     actuel->suivant=nouveau;
    }
}

/****************************************************** la chaine de la table de symbole *******************************************************************/
void insertion_tab_sym(char* nameIdent,char* typeIdent,char * valueIdent,int tailleIdent)
{
    Ident* chercher=chaine_tab_symb;
    while(chercher!=NULL && strcmp(chercher->value,valueIdent)!=0) chercher=chercher->suivant;
    if(chercher!=NULL){
     printf("\n L'identificateur est d\x8Aja declar\x82\n");
     SyntaxError();
    }
    else {
    Ident *nouveau = malloc(sizeof(*nouveau));
    strcpy(nouveau->name,nameIdent);
    strcpy(nouveau->tidf,typeIdent);
    strcpy(nouveau->value,valueIdent);
    nouveau->taille_tab_fct= tailleIdent;
    nouveau->suivant=NULL;
    if(chaine_tab_symb == NULL) {chaine_tab_symb=nouveau; }
    else {
    Ident* actuell = chaine_tab_symb;
    while(actuell->suivant !=NULL) actuell=actuell->suivant;
     actuell->suivant=nouveau;

    }
    }
}




void afficherListe_tab_sym(Ident* chaine_tab_symb)
{    printf("La table de symbole\n");
    if (chaine_tab_symb == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Ident* actuel = chaine_tab_symb;
    while (actuel != NULL)
    {
        printf("%s\n", actuel->name);
        printf("%s\n", actuel->tidf);
        printf("%s\n", actuel->value);
        printf("%d\n", actuel->taille_tab_fct);
        actuel = actuel->suivant;
    }

}


/**************************************************** insertion des ids dans la table de symbole ************************************************/
void table_symb(Element* chaine_semant1){


    int nbre = 0, taille_du_tableau;
    Element* actuel=chaine_semant1;
    while(actuel!=NULL){
          if(strcmp(actuel->name,"DEREJ")==0) return 0;
          else {
        // 2ila wssalna lmt7arek khass ndiro une boucle do while bch nboucliw 3la ga3 lles ids tant que mawwsalnach l ;
           if(strcmp(actuel->name,"MT7AREK")==0){
            do{
            actuel=actuel->suivant; // 7na f l'ID
            if(strcmp(actuel->suivant->name,"PO") !=0 ) {
            /************************************** makhassoch ykoun mot clé - le cas d'une variable 3adiya ************************************/
                    int j=0;
                    while(j < NBRKEYWORDS && strcmp(toupper(actuel->value), keywords_list[j]) != 0    ) j++;
                    if(j==NBRKEYWORDS){
                        if(strcmp(toupper(actuel->value),"3LA7ASSAB")==0 || strcmp(toupper(actuel->value),"9RA")==0 ||
                           strcmp(toupper(actuel->value),"9AREN")==0 || strcmp(toupper(actuel->value),"3AMRA")==0 ||
                           strcmp(toupper(actuel->value),"9SSEM")==0 || strcmp(toupper(actuel->value),"3EYET3AMRA")==0 ||
                           strcmp(toupper(actuel->value),"3EYETKHAWYA")==0 ){
                               printf("\n N'utilisez pas les mots clés du langage\n"); exit(0);
                        }

                    }
                    else {
                         printf("\n N'utilisez pas les mots clés du langage\n"); exit(0);
                    }
            insertion_tab_sym(actuel->name,"TVAR",actuel->value,-1); actuel=actuel->suivant;
            // ghankono f , wla ; avec -1 c'est la taille du tableau
            }
            else {
            /************************************** makhassoch ykoun mot clé - le cas d'un tableau ******************************************/
                    int j=0;
                    while( j < NBRKEYWORDS  && strcmp(toupper(actuel->value), keywords_list[j]) != 0 ) j++;
                    if(j==NBRKEYWORDS){
                        if(strcmp(toupper(actuel->value),"3LA7ASSAB")==0 || strcmp(toupper(actuel->value),"9RA")==0 ||
                           strcmp(toupper(actuel->value),"9AREN")==0 || strcmp(toupper(actuel->value),"3AMRA")==0 ||
                           strcmp(toupper(actuel->value),"9SSEM")==0 || strcmp(toupper(actuel->value),"3EYET3AMRA")==0 ||
                           strcmp(toupper(actuel->value),"3EYETKHAWYA")==0 ){
                               printf("\n N'utilisez pas les mots clés du langage\n"); exit(0);
                        }

                    }
                    else {
                         printf("\n N'utilisez pas les mots clés du langage\n"); exit(0);
                    }
                   insertion_tab_sym(actuel->name,"TVARTAB",actuel->value,atoi(actuel->suivant->suivant->value));
                   actuel = actuel->suivant;//PO
                   actuel = actuel->suivant;//Taille du tableau

                   int s=0;
                   while(actuel->value[s] != '\0'){
                    if(actuel->value[s] =='.') { printf("la taille du tableau doit etre un entier !!!!!! \n"); SyntaxError();}
                    s++;
                   }
                   actuel = actuel->suivant;//PF
                   actuel = actuel->suivant;// soit virgule wla ;
                   }
            } while(strcmp(actuel->name,"VIR")==0);
              }

            // 2ila wssalna lTABT khass ndiro une boucle do while bch nboucliw 3la ga3 lles ids tant que mawwsalnach l ;
            else if(strcmp(actuel->name,"TABT")==0){

            do{
            actuel=actuel->suivant; // f l'ID


            if(strcmp(actuel->suivant->name,"PO") !=0 ) {
            /************************************** makhassoch ykoun mot clé _ le cas d'une variable 3adiya ************************************/
                    int j=0;
                    while( j < NBRKEYWORDS && strcmp(toupper(actuel->value), keywords_list[j]) != 0    ) j++;
                    if(j==NBRKEYWORDS){
                        if(strcmp(toupper(actuel->value),"3LA7ASSAB")==0 || strcmp(toupper(actuel->value),"9RA")==0 ||
                           strcmp(toupper(actuel->value),"9AREN")==0 || strcmp(toupper(actuel->value),"3AMRA")==0 ||
                           strcmp(toupper(actuel->value),"9SSEM")==0 || strcmp(toupper(actuel->value),"3EYET3AMRA")==0 ||
                           strcmp(toupper(actuel->value),"3EYETKHAWYA")==0 ){
                               printf("\n N'utilisez pas les mots clés du langage\n"); exit(0);
                        }

                    }
                    else {
                         printf("\n N'utilisez pas les mots clés du langage\n"); exit(0);
                    }
            insertion_tab_sym(actuel->name,"TCONST",actuel->value,-1);
            actuel=actuel->suivant; // =
            actuel=actuel->suivant;
            if(strcmp(actuel->name,"GUI")==0) {
                actuel=actuel->suivant; // string
                actuel=actuel->suivant; // gui
            }

            actuel=actuel->suivant; // ghnakono virgule wla ;
            }
            else {

            taille_du_tableau = atoi(actuel->suivant->suivant->value); // kan7ato la taille dyal tableau
              /************************************** makhassoch ykoun mot clé - le cas d'un tableau ****************************************/
                    int j=0;
                    while(j< NBRKEYWORDS && strcmp(toupper(actuel->value), keywords_list[j]) != 0) j++;
                    if(j==NBRKEYWORDS){
                        if(strcmp(toupper(actuel->value),"3LA7ASSAB")==0 || strcmp(toupper(actuel->value),"9RA")==0 ||
                           strcmp(toupper(actuel->value),"9AREN")==0 || strcmp(toupper(actuel->value),"3AMRA")==0 ||
                           strcmp(toupper(actuel->value),"9SSEM")==0 || strcmp(toupper(actuel->value),"3EYET3AMRA")==0 ||
                           strcmp(toupper(actuel->value),"3EYETKHAWYA")==0 ){
                               printf("\n N'utilisez pas les mots clés du langage\n"); exit(0);
                        }

                    }
                    else {
                         printf("\n N'utilisez pas les mots clés du langage\n"); exit(0);
                    }

            insertion_tab_sym(actuel->name,"TCONSTTAB",actuel->value,taille_du_tableau);

            actuel=actuel->suivant; // po
            actuel=actuel->suivant; // la taille du tableau
             int s=0;
                   while(actuel->value[s] != '\0'){
                    if(actuel->value[s] =='.') { printf("la taille du tableau doit etre un entier !!!!!! \n"); SyntaxError();}
                    s++;
                   }
            actuel=actuel->suivant; // pf
            actuel=actuel->suivant; // =
            actuel=actuel->suivant; // CRO
            actuel=actuel->suivant;
             // ghankono f la valeur lawla f tab wla f GUI
            do {
                if(strcmp(actuel->name,"VIR")==0) actuel=actuel->suivant;

                if(strcmp(actuel->name,"GUI") != 0) {
                actuel=actuel->suivant;// ghankono f lvirgule
                }
                else {
                actuel=actuel->suivant; // Ghankono f string
                actuel =actuel->suivant; // Ghankono f GUI
                actuel = actuel->suivant;// ghankono f lvirgule
                }
                nbre++;
            }while(strcmp(actuel->name,"VIR") ==0 ); // ghankhrojo b parenthese fermante
            if(taille_du_tableau != nbre) SyntaxError();
            nbre = 0;
            actuel = actuel ->suivant; // ghankono virgule wla ;
            }

            } while(strcmp(actuel->name,"VIR")==0);
         }

          // Daba le cas des fcts
          else if(strcmp(actuel->name,"KHAWYA")==0 || strcmp(actuel->name,"3AMRA")==0  ){

                  char * name_fonction=(char*)malloc(sizeof(char));
                  char * value_fonction=(char*)malloc(sizeof(char));

                  int nbre_param=0;
                  actuel =actuel->suivant;
                  strcpy(value_fonction,actuel->value);
                  strcpy(name_fonction,actuel->name);
                  actuel=actuel->suivant;//PO
                  actuel=actuel->suivant;//7na soit f le premier param soit f parenthese fermante
                  while(strcmp(actuel->name,"PF") !=0 ){
                        nbre_param++;
                        actuel=actuel->suivant; // f lvirgule wla PF
                        if(strcmp(actuel->name,"VIR")==0) actuel=actuel->suivant;
                  }

                  insertion_tab_sym(name_fonction,"TIDFCT",value_fonction,nbre_param);
          }


    }


    actuel=actuel->suivant;

    }


}


/************************************************************** CHECK ********************************************************************************/
void check(Element* chaine_semant2){

     Element* actuel=chaine_semant2;
     Element* actuel1=chaine_semant2;
     Element* actuel2=chaine_semant2;
     Element* actuel3=chaine_semant2;
     Element* actuel4=chaine_semant2;
     while (actuel!=NULL && strcmp(actuel->name,"DEREJ")!=0)   actuel=actuel->suivant;
     while (actuel1!=NULL && strcmp(actuel1->name,"DEREJ")!=0) actuel1=actuel1->suivant;
     while (actuel2!=NULL && strcmp(actuel2->name,"DEREJ")!=0) actuel2=actuel2->suivant;
     while (actuel3!=NULL && strcmp(actuel3->name,"DEREJ")!=0) actuel3=actuel3->suivant;
     while (actuel4!=NULL && strcmp(actuel4->name,"DEREJ")!=0)   actuel4=actuel4->suivant;

     while(actuel!=NULL){

      if(strcmp(actuel->name,"ID")==0) {

                   /************************************** id non déclaré *****************************************************************/
                   Ident* tableSymb1=chaine_tab_symb;
                   while(tableSymb1!=NULL && strcmp(tableSymb1->value,actuel->value)!=0) tableSymb1=tableSymb1->suivant;
                   if(tableSymb1==NULL){  printf("\n L'identificateur est non declar\x82\n"); exit(0); }
                   /**************************************cte non affectée ou lue *********************************************************/
                   Ident* tableSymb2=chaine_tab_symb;
                   //mn b3d mat2akadna ana l'ID est déja déclaré ... kan9albo 3lih f la table de symbole
                   while(tableSymb2!=NULL && strcmp(tableSymb2->value,actuel->value)!=0) tableSymb2=tableSymb2->suivant;




                   //2ila kan dak l'id est une constante
                   if(strcmp(tableSymb2->tidf,"TCONST")==0 ){
                        actuel1=chaine_semant2;
                        while (actuel1!=NULL && strcmp(actuel1->name,"DEREJ")!=0) actuel1=actuel1->suivant;
                        if(strcmp(actuel->suivant->name,"AFF")==0) {
                                printf("\nLa constante ne doit pas etre modifiee\n"); exit(0); }
                        else {
                              while(actuel1!=NULL){
                                  if(strcmp(actuel1->name,"9RA")==0){
                                      while(strcmp(actuel1->name,"PF")!=0){
                                            if(strcmp(actuel1->name,"ID") == 0 && strcmp(actuel1->value,actuel->value) == 0 ) {
                                              printf("\nLa constante ne doit pa étre lue \n"); exit(0);
                                            }
                                      actuel1=actuel1->suivant;
                                      }
                                  }
                                  else actuel1=actuel1->suivant;
                              }
                        }
                   }

                    if(strcmp(tableSymb2->tidf,"TIDFCT")==0 ){
                        actuel1=chaine_semant2;
                        while (actuel1!=NULL && strcmp(actuel1->name,"DEREJ")!=0) actuel1=actuel1->suivant;
                        if(strcmp(actuel->suivant->name,"AFF")==0) {
                                printf("\nLa fonction ne doit pas etre modifiee\n"); exit(0); }
                        else {
                              while(actuel1!=NULL){
                                  if(strcmp(actuel1->name,"9RA")==0){
                                      while(strcmp(actuel1->name,"PF")!=0){
                                            if(strcmp(actuel1->name,"ID") == 0 && strcmp(actuel1->value,actuel->value) == 0 ) {
                                              printf("\nLa fonction ne doit pa étre lue \n"); exit(0);
                                            }
                                      actuel1=actuel1->suivant;
                                      }
                                  }
                                  else actuel1=actuel1->suivant;
                              }
                        }
                   }

                     //hna le cas diyal tableau constant

                    if(strcmp(tableSymb2->tidf,"TCONSTTAB")==0){
                         actuel4=chaine_semant2;
                         while (actuel4!=NULL && strcmp(actuel4->name,"DEREJ")!=0)   actuel4=actuel4->suivant;
                        if(actuel->suivant->suivant->suivant->suivant!= NULL && strcmp(actuel->suivant->suivant->suivant->suivant->name,"AFF")==0) {
                                printf("\nLe tableau est constant, il ne doit pas etre modifiee\n"); exit(0); }
                        else {

                              while(actuel4!=NULL){
                                  if(strcmp(actuel4->name,"9RA")==0){
                                      while(strcmp(actuel4->name,"PF")!=0){
                                            if(strcmp(actuel4->name,"ID") == 0 && strcmp(actuel4->value,actuel->value) == 0 ) {
                                              printf("\n Le tableau est constant, il ne doit pas etre lu \n"); exit(0);
                                            }
                                      actuel4=actuel4->suivant;
                                      }
                                  }
                                  else actuel4=actuel4->suivant;
                              }
                        }
                   }


                   //2ila kan l'id smiyet fct
                   else if(strcmp(tableSymb2->tidf,"TIDFCT")==0){

                         Element* actuel7=chaine_semant2;// kaychouf les ids dyal les instructions
                         Element* actuel8=chaine_semant2;

                         while(actuel7!=NULL  && strcmp(actuel7->name,"DEREJ")!=0 && strcmp(actuel7->value,tableSymb2->value)!=0) actuel7=actuel7->suivant;

                         while(strcmp(actuel7->name,"AF")!=0)  actuel7=actuel7->suivant; //ghanmchiw lles instructions
                         actuel7=actuel7->suivant;
                         while(actuel7!=NULL && strcmp(actuel7->name,"AF")!=0){
                            if(strcmp(actuel7->name,"ID")==0){ // une fois l9aw chi id
                                actuel8=chaine_semant2;
                                while(strcmp(actuel8->name,"AF")!=0 && strcmp(actuel8->value, actuel7->value)!=0 ) actuel8=actuel8->suivant; //hadi fl3aybat dyal lprogramme
                                if(strcmp(actuel8->name,"AF")==0){// khasso ymchi lfct bach ychouf les variables locales li flfct

                                    while(actuel8!=NULL  && strcmp(actuel8->name,"DEREJ")!=0 && strcmp(actuel8->value,tableSymb2->value)!=0) actuel8=actuel8->suivant;
                                    while(strcmp(actuel8->name,"AF")!=0 && strcmp(actuel8->value, actuel7->value)!=0 ) actuel8=actuel8->suivant;// l3aybat dyal lfct
                                    if(strcmp(actuel8->name,"AF")==0) {
                                        printf("L'ID %s n'est pas déclaré !! ",actuel7->value); exit(0);
                                    }
                                }
                            }
                            actuel7=actuel7->suivant;
                         }

                         int amra;
                         Element* actuel5=chaine_semant2;
                         while(actuel5!=NULL  && strcmp(actuel5->name,"DEREJ")!=0 && strcmp(actuel5->suivant->value,tableSymb2->value)!=0) actuel5=actuel5->suivant;
                         if(strcmp(actuel5->name,"3AMRA")==0)  amra=1; else amra=0;
                         Element* actuel6=chaine_semant2;
                         while(actuel6!=NULL  && strcmp(actuel6->name,"DEREJ")!=0 && strcmp(actuel6->suivant->value,tableSymb2->value)!=0) actuel6=actuel6->suivant;
                         while(strcmp(actuel6->name,"AF")!=0)  actuel6=actuel6->suivant;
                         actuel6=actuel6->suivant;
                         while(strcmp(actuel6->name,"AF")!=0 && strcmp(actuel6->name,"REJE3")!=0) actuel6=actuel6->suivant;
                         if(strcmp(actuel6->name,"AF")==0 && amra==1) {
                            printf("Vous devez ajouter le mot clé REJE3 !!! ");
                            exit(0);
                         }
                         else if(strcmp(actuel6->name,"REJE3")==0 && amra==0){
                           printf("Vous devez supprimer le mot clé REJE3 !!! ");
                            exit(0);
                         }

                        int cpt=0;
                       actuel2=chaine_semant2;
                       while (actuel2!=NULL && strcmp(actuel2->name,"DEREJ")!=0) actuel2=actuel2->suivant;
                        while(actuel2!=NULL){
                                  if( (strcmp(actuel2->name,"3EYETKHAWYA")==0 || strcmp(actuel2->name,"3EYET3AMRA") ==0)
                                        && strcmp(actuel2->suivant->value,tableSymb2->value)==0){
                                    if(strcmp(actuel2->name,"3EYET3AMRA")==0 && amra==0 ) {
                                           printf("La fonction ne retourne rien !!!"); exit(0);
                                    }
                                    else if(strcmp(actuel2->name,"3EYETKHAWYA")==0 && amra==1) {
                                           printf("La fonction retourne une valeur !!!"); exit(0);
                                    }
                                    actuel2=actuel2->suivant;//smiyet lfct
                                    actuel2=actuel2->suivant;//7na f PO
                                    // hna movina lPO bach may7ssebch l id dyal la fct comme paramètre
                                     while(strcmp(actuel2->name,"PF")!=0){
                                        if(strcmp(actuel2->name,"ID")==0 || strcmp(actuel2->name,"NUM")==0 || strcmp(actuel2->name,"STRING")==0 ) cpt++;
                                        actuel2=actuel2->suivant;

                                     }

                                             if(tableSymb2->taille_tab_fct!=cpt) {
                                                   printf("\nL'appel de la fonction est erronée, le nombre de paramétre n'est pas respecté \n"); exit(0);}


                                   }
                                   else actuel2=actuel2->suivant;
                     }


                   }

                   //hna le cas dyal un tableau déclaré f MT7AREK
                   else if(strcmp(tableSymb2->tidf,"TVARTAB")==0){
                        actuel3=chaine_semant2;
                        while (actuel3!=NULL && strcmp(actuel3->name,"DEREJ")!=0) actuel3=actuel3->suivant;
                        int cpt1=0;
                             while(actuel3!=NULL){
                                  if(strcmp(actuel3->value,tableSymb2->value)==0){ //hna 7na f le nom dyal le tableau
                                        if(strcmp(actuel3->suivant->name,"PO")==0){ // le cas ou on affecte directement b l'indice
                                           int s=0;
                                           while(actuel3->suivant->suivant->value[s] != '\0'){
                                              if(actuel3->suivant->suivant->value[s] =='.') { printf("l'indice doit etre un entier !!!!!! \n"); SyntaxError();}
                                               s++;
                                             }
                                           if(atoi(actuel3->suivant->suivant->value)<0 ){ printf("l'indice ne doit pas etre negatif !!!!!! \n"); SyntaxError();}
                                           if(atoi(actuel3->suivant->suivant->value)>=tableSymb2->taille_tab_fct){
                                                printf("l'indice ne doit pas etre supèrieur ou égal la taille du tableau !!!!!! \n"); SyntaxError(); }


                                        }

                                       while(strcmp(actuel3->name,"CRF")!=0){
                                           actuel3=actuel3->suivant;
                                        if(strcmp(actuel3->name,"ID") ==0 || strcmp(actuel3->name,"NUM")==0 || strcmp(actuel3->name,"STRING")==0 ) cpt1++;

                                     }

                                   }
                                   else actuel3=actuel3->suivant;
                     }
                    if(tableSymb2->taille_tab_fct!=cpt1) {
                          printf("\nL'affectation du tableau est erronée, le nombre de paramétre n'est pas respecté \n"); exit(0);
                    }

                   }





}

actuel=actuel->suivant;

}
                         Element* actuel9=chaine_semant2;// kaychouf les ids dyal les instructions
                         Element* actuel10=chaine_semant2;;
                         Ident* tableSymb3=chaine_tab_symb;
                         while(actuel9!=NULL  && strcmp(actuel9->name,"DEREJ")!=0) actuel9=actuel9->suivant;
                         while(actuel9!=NULL && strcmp(actuel9->name,"AF")!=0 )
                         {
                              if(strcmp(actuel9->name,"ID")==0)// une fois l9aw chi id
                                {
                                  tableSymb3=chaine_tab_symb;
                                  while(tableSymb3!=NULL && strcmp(tableSymb3->value,actuel9->value)!=0)
                                    tableSymb3=tableSymb3->suivant;
                                  if(strcmp(tableSymb3->tidf,"TIDFCT")!=0)//ze3ma on évite le cas lorsque le id est utiliseé comme étant un id de le fct
                                  {
                                        actuel10=chaine_semant2;
                                        while(actuel10!=NULL  && strcmp(actuel10->name,"AF")!=0 && strcmp(actuel10->value,actuel9->value)!=0  )
                                              actuel10=actuel10->suivant;
                                        if(strcmp(actuel10->name,"AF")==0)
                                           {
                                             printf("l'id %s doit etre déclaré ",actuel9->value);
                                              exit(0);
                                            }

                                  }


                                 }
                               actuel9=actuel9->suivant;
                         }
}
