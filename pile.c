#include "pile.h"
#include <assert.h>
 

                      /* Redaction des fonctions */

 
  /** 
   * \fn init
   * \brief fixe le sommet a 0 et alloue un premier tableau 
   * \author saad bouhya
   * \version 1.0
   * \param parametre 1 recoit une pile
   * \return ne retourne rien (void)
   */
   
  void init(pile_t *pPile) {
    pPile->sommet = 0; //----- le sommet donne la taille
    pPile->data = (elt_t *) malloc(sizeof(elt_t));

    if (pPile == NULL) {  //------ methode 1
      fprintf(stderr, "initPile(): faute d'allocation\n");
      exit(0);
    }

    // assert (pPile != NULL); //-------- methode 2
  } 

  /** 
   * \fn pop
   * \brief depile l'element qui est au sommet et si la taille de la partie vide du tableau est egale a SEUIL_FREE on soustracte SEUIL_FREE  de la taille du tableau 
   * \author saad bouhya
   * \version 1.0
   * \param recoit une pile
   * \return retourne l'element depile
   */

  elt_t pop (pile_t *pPile) {
    elt_t e;
    assert (pPile->sommet!=0);
    e = pPile->data [ --pPile->sommet ];
    if ( (pPile->taille) - (pPile->sommet) == SEUIL_FREE) {
      pPile->taille -= SEUIL_FREE;
      pPile->data = (elt_t *) realloc (pPile->data, pPile->taille * sizeof(elt_t));
      assert (pPile->data != NULL);
    }
    
    return e;
   
  }

  /** 
   * \fn push
   * \brief empile l'element passe en parametre et si on atteint la taille du tableau on rajoute la taille SEUIL_ALLOC a la taille de notre tableau 
   * \author saad bouhya
   * \version 1.0
   * \param parametre 1 recoit une pile
   * \param parametre 2 recoit l'element a empiler
   * \return ne retourne rien (void)
   */

  void push (pile_t *pPile, elt_t e) {
    if (pPile->taille == pPile->sommet) {
      pPile->taille += SEUIL_ALLOC;
      pPile->data = (elt_t *) realloc (pPile->data, sizeof(elt_t) * (pPile->taille));
      assert(pPile->data != NULL); 
    }
    pPile->data [ pPile->sommet++ ] = e;
  }

  /** 
   * \fn printPile
   * \brief affiche tout les elements de notre pile 
   * \author saad bouhya
   * \version 1.0
   * \param parametre 1 recoit une pile
   * \return ne retourne rien (void)
   */

  void printPile (const pile_t *pPile) {
    for (int i=0; i<pPile->sommet; i++) {
      printf("%d", pPile->data [ i ]);
      printf(" ");
    }
    printf("\n");
  }

  

  /** 
   * \fn hateur 
   * \brief sert a avoir le nombre d'element dans le tableau 
   * \author saad bouhya
   * \version 1.0
   * \param parametre 1 recoit une pile
   * \return retourne un int qui est le nombre d'element dans le tableau
   */
  
elt_t hauteur (pile_t * Pile) {
  return Pile->sommet;
}

  /** 
   * \fn pileVide
   * \brief nous aide a savoir si la pile est vide ou non 
   * \author saad bouhya
   * \version 1.0
   * \param parametre 1 recoit une pile
   * \return retourne 1 si la pile est vide et 0 si la pile n'est pas vide
   */

  int pilevide(const  pile_t *P)
  {
    if (P->sommet == 0) {
      return 1;
    }

    return 0;
  }

  /** 
   * \fn sommet
   * \brief nous aide a savoir la position du sommet de la pile 
   * \author saad bouhya
   * \version 1.0
   * \param parametre 1 recoit une pile
   * \return retourne la position du sommet
   */

  int sommet(pile_t * pile) {
    return (pile->sommet - 1);
  }

  /** 
   * \fn valS
   * \brief nous donne la valeur du sommet de la pile 
   * \author saad bouhya
   * \version 1.0
   * \param parametre 1 recoit une pile
   * \return retourne la valeur du sommet de la pile
   */

  elt_t valS (pile_t pile) {
    return (elt_t)pile.data[pile.sommet-1];
  }
