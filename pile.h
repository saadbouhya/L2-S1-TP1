#include <stdlib.h>
#include <stdio.h>


typedef int elt_t;

#define SEUIL_ALLOC 5
#define SEUIL_FREE 10

/* La structure de la pile */
typedef	struct
{
			int	sommet	; 	//l’indice	du	sommet	de	pile										
			int taille;
			elt_t *	data	; 	//l’adresse	de	la	zone	de	stockage				
}	pile_t ;

// les prototypes des fonctions

void init (pile_t *pPile);
elt_t pop (pile_t *pPile);
void push (pile_t *pPile, elt_t e);
void printPile (const pile_t *pPile);
elt_t hauteur (pile_t * Pile);
int pilevide(const  pile_t *P);
int sommet(pile_t * pile);
elt_t valS (pile_t pile); // c la valeur du sommet