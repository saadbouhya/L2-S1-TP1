/* La structure de la pile */
/*typedef	struct
{
			int	sommet	; 	l’indice	du	sommet	de	pile										
			elt_t *	data	; 	l’adresse	de	la	zone	de	stockage				
}	pile_t ; */

/* Redaction des fonctions */

/* 
  ----------------- la fonction init() -----------------------
  
  void init(pile_t *pPile) {
    pPile->sommet = 0; ----- le sommet donne la taille
    pPile->data = (elt_t *) malloc(sizeof(elt));

    if (pPile == NULL) {  ------ methode 1
      fprintf(stderr, "initPile(): faute d'allocation\n");
      exit();
    }

    assert (pPile != NULL); -------- methode 2
  } 

  ----------------- la fonction pop() -----------------------

  elt_t pop (pile_t *pPile) {
    elt_e e;
    assert (pPile->sommet != 0);
    e = pPile->data [ --pPile->sommet ];
    pPile->data = (elt_t *) realloc (pPile->data,sizeof(elt_t) * (pPile->sommet + 1));
    return e;

    -------- autre methode a utiliser au lieu du assert
    #define ELTOUT
    return ELT_OUT
    if ((monelt=pop(&mapile) == ELT_OUT) {
      .......... pile vide ...........
    }
  }

  ----------------- la fonction push() -----------------------

  void push (pile_t *pPile, elt_t e) {
    pPile->data = (elt_t *) realloc (pPile->data, sizeof(elt_t) * (pPile->sommet + 1));
    assert (pPile->data != NULL);
    pPile->data [ pPile->sommet++] = e;
  }

  ----------------- la fonction printPile() -----------------------

  void printPile (const pile_t *pPile) {
    for (int i=0; i<pPile->sommet; i++) {
      printElt(pPile->data [ i ]); ----------- printf("%d", ...);
      printf(" ");
    }
    printf("\n");
  }

  ----------------- la fonction push() methode 2 -----------------------
  
  void push (pile_t *pPile, elt_t e) {
    if (pPile->taille == pPile->sommet) {
      pPile->taille += SEUIL_ALLOC;
      pPile->data = (elt_t *) realloc (pPile->data, sizeof(elt_t) * (pPile->taille));
      assert(pPile->data != NULL); 
    }
    Ppile->data [ pPile->sommet++ ] = e;
  }

  ----------------- la fonction pop() methode 2 -----------------------

  elt_t pop (pile_t *pPile) {
    elt_t e;
    assert (pPile->sommet!=0);
    e = Pile->data [ --pPile->sommet ];
    if ( pPile->taille - pPile->sommet == SEUIL_FREE) {
      pPile->taille -= SEUIL_FREE;
      pPile->data = (elt_t *) realloc (pPile->data, pPile->talle * sizeof(elt_t));
      assert (pPile->data != NULL);
    }
  }
