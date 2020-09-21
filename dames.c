#include <string.h>
#include "pile.h"

#define Passer1erFils(pile) push(pile, 0)
#define RemonterPere(pile) pop(pile)
#define PasserFrereSuivant(pile, E)  E=pop(pile), push(pile, E+1)

#define NaPlusDeFrere(pile, nbElt) valS(pile) == nbElt-1
#define estTerminal(pile, nbElt)  hauteur(pile) == nbElt
#define CestPasFini(pile) pilevide(pile) == 1

int estValide ( pile_t *pPile );
unsigned int affiche1Sol (const pile_t *pPile, const char *pMot);

int main() {
  pile_t pile;
  elt_t e;
  elt_t E;
  int succes;
  char ch[50];
  init(&pile);
  int nombreSol=0;

  printf("Saisir une chaine: ");
  scanf("%s", ch);
  do
  {
    
    succes=0;
    while( (estValide(&pile)==1) && (succes==0))
    {
      if (estTerminal(&pile,strlen(ch))) //succès
        {
        if (succes==0) 
          {
            affiche1Sol(&pile,ch);
            nombreSol++;
          }
        succes=1;
        }
      else

      {	
        Passer1erFils(&pile); 
        //affiche1Sol(&pile,ch);
      }
    } 
    // 2 
    while(!(CestPasFini(&pile)) && NaPlusDeFrere(pile,strlen(ch)) )
    { 
      RemonterPere(&pile); 
      //affiche1Sol(&pile,ch);
    }

    // 3 
    if (!(CestPasFini(&pile)))
      {
        PasserFrereSuivant(&pile, E);
        //affiche1Sol(&pile,ch);
      }

  }while(!(CestPasFini(&pile)));

  printf("\n");
  printf("Le nombre de solution est: %d\n", nombreSol);

  return 0;
}

int estValide ( pile_t *pPile ) {
  int i,j;

  for(i=0; i<hauteur(pPile); i++) {

    for (j=0; j<hauteur(pPile); j++) {

			if(pPile->data[i]==pPile->data[j] || i - pPile->data[i]== j - pPile->data[j] || i + pPile->data[i] == j + pPile->data[j])
			{
				return 0;
			}

    }

	}

    return 1;
}

unsigned int affiche1Sol (const pile_t *pPile, const char *pMot) {
  static unsigned int numSol = 0 ;
  elt_t e;
  pile_t pile;
  init(&pile);

  while (!(pilevide(pPile))) {
    e = pop(pPile);
    printf("%c", pMot[e]);
    push(&pile, e);
  }

  while (!(pilevide(&pile))) {
    e = pop(&pile);
    push(pPile, e);
  }

  printf(" ");

  

}