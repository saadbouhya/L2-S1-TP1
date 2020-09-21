#include "test_pile.h"


void testPile(pile_t *pile) {
	init(pile);
	printf("1. empiler\n");
	printf("2. depiler\n");
	printf("3. afficher la pile\n");
	printf("4. La valeur du sommet de la pile.\n");
	printf("0. quitter\n");
	int choix;
	elt_t valeur;
  unsigned int i;

	while(1) {
		printf("saisir votre choix: ");
		scanf("%d", &choix);
		switch(choix) {
			case 1:	printf("Saisir la valeur: ");
							scanf("%d", &valeur);
							push(pile, valeur);
							break;
			case 2: valeur = pop(pile);
								printf("La valeur depilee est: %d\n", valeur);
							break;
			case 3:	printPile(pile);
							break; 
			case 4: printf("Sasir la valeur de i: ");
              scanf("%d", &i);
              valeur = valeurSommet(*pile, i);
							printf("La valeur de la case i est %d\n", valeur);
							break;
			
			case 0: exit(0);
			default: printf("Choix invalide\n"); 

		}
	}
}

// ----------- la fonction valeurSommet

  elt_t valeurSommet (pile_t Pile, unsigned int i) {
    pile_t p;
    elt_t valeur;
    elt_t valS;
    int count;

    init(&p);

		int j=sommet(&Pile)+1;
		while (j>i)
		{
			valeur = pop(&Pile);
			push(&p, valeur);
			j--;
		}
		
    valS = p.data[p.sommet - 1];
    count = sommet(&p);
    while (count != 0) {
      valeur = pop(&p);
      push(&Pile, valeur);
      count--;
    }


    return valS;
  }