#include "analyseur_syntaxique.h"
/************************************************************* La chaine de l'analyseur syntaxique ****************************************************/

// permet d'insérer un tocken dans une liste chainée
void insertion_syntax(char* nameToken,char* valueToken)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    strcpy(nouveau->name,nameToken);
    strcpy(nouveau->value,valueToken);
    nouveau->suivant=NULL;
    if(chaine_syntax == NULL) chaine_syntax = nouveau;
    else {
    Element* actuel = chaine_syntax;
    while(actuel->suivant !=NULL) actuel=actuel->suivant;
     actuel->suivant=nouveau;
    }
}

// cette fct permet l'affichage d'une liste chainée qui contient les tockens
void afficherListe_syntax(Element* chaine_syntax)
{
    if (chaine_syntax == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = chaine_syntax;
    while (actuel != NULL)
    {
        printf("%s\n", actuel->name);
        printf("%s\n", actuel->value);
        actuel = actuel->suivant;
    }

}

// kanchofo wach tocken li f la liste chainée hadik hya blassto syntaxiquement
bool verifyToken(char* name_to_test){
    if(chaine_syntax==NULL) return FALSE;
    else if(strcmp(chaine_syntax->name,name_to_test)!=0){
         printf("%s_khayb \n",chaine_syntax->name);
        return FALSE;  }
    else {
        printf("%s_mazian \n",chaine_syntax->name);
        chaine_syntax=chaine_syntax->suivant;
    return TRUE;
} }

// had la fct 2affiche une erreur ila l9at chi erreur f syntaxe w katwe9ef le programme
void SyntaxError(){
    printf("Syntax Error");
    exit(1);
}

void PROGRAM(){
if(verifyToken("L3AYBAT")) {
        DEF();
      if(! verifyToken("FCT")) SyntaxError();
      else {
          FONCTION();
          if(! verifyToken("DEREJ")) SyntaxError();
          else BLOCK();

           }
}
else SyntaxError();

}

void DEF(){
if( verifyToken("AO"))  {
    CONSTS();
    VARS();
    if( ! verifyToken("AF"))  SyntaxError();
}
else SyntaxError();
}

void CONSTS(){
if( verifyToken("TABT"))  {
     do{
        CONSTID();
    }while(verifyToken("VIR"));
    if( ! verifyToken("PV"))  SyntaxError();


}
}

void CONSTID() {
if( verifyToken("ID"))  {
    ALPHA();
}
else SyntaxError();
}


void ALPHA(){
if (verifyToken("PO")) {
    if(! verifyToken("NUM")) SyntaxError();
    else {
         if(! verifyToken("PF")) SyntaxError();
         else {
               if(! verifyToken("AFF")) SyntaxError();
               else {
                     if(! verifyToken("CRO")) SyntaxError();
                     else {
                           TABCONST();
                           if(! verifyToken("CRF")) SyntaxError();
                     }
               }
         }
    }


}
else if(verifyToken("AFF")){
    ALPHANUM();

}
else SyntaxError();

}

void TABCONST()
{
    if(verifyToken("NUM")) {
          while(verifyToken("VIR")){
          if(! verifyToken("NUM")) SyntaxError();
         }
    }
    else if(verifyToken("GUI")) {
                if( ! verifyToken("STRING")) SyntaxError();
                else {
                    if(! verifyToken("GUI")) SyntaxError();
                    else {
                    while(verifyToken("VIR")) {
                       if(! verifyToken("GUI")) SyntaxError();
                       else {
                        if(! verifyToken("STRING")) SyntaxError();
                        else {
                            if(! verifyToken("GUI")) SyntaxError();
                        }
                        }
                        }
                        }
                        }

    }
  else  SyntaxError();

}


void VARS(){
if(verifyToken("MT7AREK")){
        do{
          if(! verifyToken("ID")) SyntaxError();
          else VAR();
          }while(verifyToken("VIR"));
       if(! verifyToken("PV")) SyntaxError();
}
}

void VAR(){
if( verifyToken("PO")) {
   if(! verifyToken("NUM")) SyntaxError();
   else {
         if(! verifyToken("PF")) SyntaxError();
   }

}

}
void ALPHANUM(){
if(verifyToken("NUM"));
else if(verifyToken("GUI")){
    if(! verifyToken("STRING")) SyntaxError();
    else {
        if(! verifyToken("GUI")) SyntaxError();
    }
}
else SyntaxError();
}

void FONCTION(){
if(verifyToken("AO")){
   while(verifyToken("KHAWYA") || verifyToken("3AMRA")){
      if(! verifyToken("ID")) SyntaxError();
      else {
          if(! verifyToken("PO")) SyntaxError();
          else {
              PARAM();
              if(! verifyToken("PF")) SyntaxError();
              else {
                 if(! verifyToken("AO")) SyntaxError();
                 else{
                 DEF();
                 INSTS();
                 if(verifyToken("REJE3")) {
                    if(! verifyToken("PO")) SyntaxError();
                    else {
                          if(! (verifyToken("NUM")|| verifyToken("ID") )) SyntaxError();
                          else {
                            if(! verifyToken("PF")) SyntaxError();
                            if(! verifyToken("PV")) SyntaxError();
                          }
                        }
                      }
                    }
                }
           }
        }
      if(! verifyToken("AF")) SyntaxError();
   }
    if(! verifyToken("AF")) SyntaxError();
}
else SyntaxError();
}


void BLOCK(){
    if(! verifyToken("AO")) SyntaxError();
    else {
            INSTS();
    if(! verifyToken("AF")) SyntaxError();
    }
}


void INSTS(){
    INST();
}

void INST(){
      if(verifyToken("ID")){ AFFECT(); INST(); }
      else if(verifyToken("ILAKAN")) { SI(); INST(); }
      else if(verifyToken("KTEB")) { ECRIRE(); INST(); }
      else if(verifyToken("9RA"))  { LIRE(); INST(); }
      else if(verifyToken("MENHADI")) { FOR(); INST(); }
      else if(verifyToken("MA7ED")) { WHILE(); INST(); }
      else if(verifyToken("3LA7ASSAB")) { SWITCH(); INST(); }
      else if(verifyToken("3EYETKHAWYA")) {APPELFCT(); INST();}

}
void AFFECT(){
    AFFEC();
    if(! verifyToken("PV"));
}
void AFFEC(){
  if(verifyToken("AFF")) AFFEC2();
  else if(verifyToken("PO")) AFFECTAB();
  else SyntaxError();
}


void EXPR1(){
 if(verifyToken("GUI")){
         if(! verifyToken("STRING")) SyntaxError();
         else {
         if(! verifyToken("GUI")) SyntaxError();
              }
     }
     else if(verifyToken("3EYET3AMRA"))
          APPELFCT();
     else  EXPR();




}
void AFFECTAB(){
//if(! verifyToken("NUM")) SyntaxError();
//else {
     EXPR();
    if(! verifyToken("PF")) SyntaxError();
    else {
          if(! verifyToken("AFF") ) SyntaxError();
          else {
                EXPR1();
          }
    }
//}

}


void AFFEC2(){
     if(verifyToken("CRO")) {
         TABCONST();
         if(! verifyToken("CRF")) SyntaxError();
     }
     else if(verifyToken("GUI")){
         if(! verifyToken("STRING")) SyntaxError();
         else {
         if(! verifyToken("GUI")) SyntaxError();
              }
     }
      else if(verifyToken("3EYET3AMRA"))
          APPELFCT();
      else  EXPR();

}


void SI(){
    COND();
    if(! verifyToken("AO")) SyntaxError();
    else {
          INSTS();
          if(! verifyToken("AF")) SyntaxError();
          if(verifyToken("ILAMAKAN"))  {
                     if(! verifyToken("AO")) SyntaxError();
                     else {
                          INSTS();
                          if(! verifyToken("AF")) SyntaxError();
                     }
          }
    }
}

void ECRIRE(){
if(! verifyToken("PO")) SyntaxError();
else {
    ECRIREA();
    if(! verifyToken("PF")) SyntaxError();
    if(! verifyToken("PV")) SyntaxError();
}

}

void ECRIREA(){
if(verifyToken("ID")){
    ECRIREB();
}
else if(verifyToken("GUI")){
    if(! verifyToken("STRING")) SyntaxError();
    else {
          if(! verifyToken("GUI")) SyntaxError();
          else {
                ECRIREB();
          }
    }
}
else SyntaxError();
}

void ECRIREB(){
if(verifyToken("PLUS")){
    ECRIREA();
}
}

void LIRE(){
if(! verifyToken("PO")) SyntaxError();
else {
     do {
        if(! verifyToken("ID")) SyntaxError();
     }while(verifyToken("VIR"));
     if(! verifyToken("PF")) SyntaxError();
     else {
     if(! verifyToken("PV")) SyntaxError();
}
}
}


void FOR(){
if(! verifyToken("PO")) SyntaxError();
else {
      if(! verifyToken("ID")) SyntaxError();
      else {
            if(! verifyToken("AFF")) SyntaxError();
            else {
                  if(! verifyToken("NUM")) SyntaxError();
                  else {
                        if(! verifyToken("PF")) SyntaxError();
                        else {
                              if(! verifyToken("LHADI")) SyntaxError();
                              else {
                                    if(! verifyToken("PO")) SyntaxError();
                                    else {
                                          if(! verifyToken("ID")) SyntaxError();
                                           else {
                                                 if(! verifyToken("AFF")) SyntaxError();
                                                 else {
                                                       if(! verifyToken("NUM")) SyntaxError();
                                                       else {
                                                             if(! verifyToken("PF")) SyntaxError();
                                                            else {
                                                                 if(! verifyToken("NEMCHIWBHADI")) SyntaxError();
                                                                 else {
                                                                       if(! verifyToken("PO")) SyntaxError();
                                                                       else {
                                                                             if(! (verifyToken("PLUS") || verifyToken("MOINS"))) SyntaxError();
                                                                             else {
                                                                                  if(! verifyToken("NUM")) SyntaxError();
                                                                                  else {
                                                                                       if(!verifyToken("PF")) SyntaxError();
                                                                                        else {
                                                                                             if(! verifyToken("AO")) SyntaxError();
                                                                                             else {
                                                                                                   INSTS();
                                                                                                    if(! verifyToken("AF")) SyntaxError();
                                                                                   }
                                                                             }
                                                                       }
                                                                 } }
                                                            }

                                              }
                                        }
                                 }
                             }
                          }
                       }
                     }
                  }
               }

            }
       }
}

void WHILE(){
COND();
    if(! verifyToken("AO")) SyntaxError();
            else {
                  INSTS();
                  if(! verifyToken("AF")) SyntaxError();

      }

}

void SWITCH(){
if(! verifyToken("PO")) SyntaxError();
else {
      if(! verifyToken("ID")) SyntaxError();
      else {
            if(! verifyToken("PF")) SyntaxError();
            else {
                  if(! verifyToken("AO")) SyntaxError();
                  else {
                        if(! verifyToken("WACH")) SyntaxError();
                        else {
                              do{
                              ALPHANUM();
                               if(! verifyToken("DP")) SyntaxError();
                               INSTS();
                               if(verifyToken("BARAKA")){
                                  if(!verifyToken("PV")) SyntaxError();
                                     }
                               }while(verifyToken("WACH"));
                               if(! verifyToken("TA7AJA")) SyntaxError();
                               else {
                                    if(! verifyToken("DP")) SyntaxError();
                                    else {
                                          INSTS();
                                          if(verifyToken("BARAKA")){
                                             if(!verifyToken("PV")) SyntaxError();
                                                                    }
                                          if(! verifyToken("AF")) SyntaxError();
                                         }
                                    }


                             }

                       }

                }
      }
}

}

void PARAM(){
if(verifyToken("ID")){
    while(verifyToken("VIR")) {
         if(! verifyToken("ID")) SyntaxError();
    }
}
}

void EXPR(){
    do{
     term();
      }while(verifyToken("PLUS") || verifyToken("MOINS"));

}



void term(){
do{
     fact();
      }while(verifyToken("MULT") || verifyToken("DIV"));


}

void fact(){
     if(verifyToken("ID")) ;
     else if(verifyToken("NUM"));
     else if(verifyToken("PO")) {
           EXPR();
           if( ! verifyToken("PF")) SyntaxError();
     }
     else SyntaxError();

}
void COND(){
if(! verifyToken("PO")) SyntaxError();
else {
  EXPR();
  if(verifyToken("EG"));
  else if(verifyToken("INF"));
  else if(verifyToken("INFEG"));
  else if(verifyToken("SUP"));
   else if(verifyToken("DIFF"));
  else if(verifyToken("SUPEG"));
  else SyntaxError();
  EXPR();
  if(! verifyToken("PF")) SyntaxError();
}

}

void APPELFCT(){
 APPEL();
 if(!verifyToken("PV")) SyntaxError();
}


void APPEL(){
if(verifyToken("ID")) FCTDEC();
else if( verifyToken("WACH3ADADWLA7ARF")|| verifyToken("WACH7ARF") || verifyToken("WACH3ADAD") || verifyToken("WACH3ALAMA") || verifyToken("VABSOLUE") ||
        verifyToken("LBA9I")  || verifyToken("SIN") || verifyToken("COS") || verifyToken("TAN") || verifyToken("SQRT")  ||  verifyToken("LOG") || verifyToken("EXP") ||
        verifyToken("PUISSANCE") || verifyToken("ASIN")||  verifyToken("9SSEM") || verifyToken("ACOS") || verifyToken("ATAN") || verifyToken("L3ADDAD") ||
        verifyToken("KIFMAKAN") ) FCTDEFC1();
else if(verifyToken("KHROJ")) FCTDEFC2();
else if(verifyToken("HEZ7ET") || verifyToken("JME3")) FCTDEFC3();
else if(verifyToken("TOUL")) FCTDEFC4();
else if(verifyToken("9AREN")) FCTDEFC5();
else SyntaxError();

}

void FCTDEC(){

if(! verifyToken("PO")) SyntaxError();
else {
do{
VAL();
}while(verifyToken("VIR"));
if(! verifyToken("PF")) SyntaxError();

}
}
void VAL(){
if(verifyToken("ID"));
else if(verifyToken("NUM"));
else if(verifyToken("GUI")) {
    if(! verifyToken("STRING")) SyntaxError();
    else {
           if(! verifyToken("GUI")) SyntaxError();
    }
    }
}

void FCTDEFC1(){
 if(! verifyToken("PO")) SyntaxError();
 else{
        if(! verifyToken("ID")) SyntaxError();
        else {
              if(! verifyToken("PF")) SyntaxError();
        }
}
}


void FCTDEFC2 (){
if(! verifyToken("PO")) SyntaxError();
else{
     if(! verifyToken("NUM")) SyntaxError();
     else {
           if(! verifyToken("PF")) SyntaxError();
     }
}
}

void FCTDEFC3() {
if(! verifyToken("PO")) SyntaxError();
else {
      if(! verifyToken("ID")) SyntaxError();
      else {
            if(! verifyToken("VIR")) SyntaxError();
            ARG1();
            if(! verifyToken("PF")) SyntaxError();
      }

}

}

void FCTDEFC4(){
if(! verifyToken("PO")) SyntaxError();
else {
      ARG1();
      if(! verifyToken("PF")) SyntaxError();
}


}


void FCTDEFC5(){
if(! verifyToken("PO")) SyntaxError();
else {
      ARG1();
      if(! verifyToken("VIR")) SyntaxError();
      else {
            ARG1();
             if(! verifyToken("PF")) SyntaxError();
      }
}


}


void ARG1(){
if(verifyToken("ID"));
else if(verifyToken("GUI")){
    if(! verifyToken("STRING")) SyntaxError();
    else {
        if(! verifyToken("GUI")) SyntaxError();
    }
}
else SyntaxError();

}
