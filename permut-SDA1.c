#include <string.h>
#include "pile.h"
#define TAILLE 10

#define passerAuPremierFils(p,E)    push(p,E) 
// p est un pointeur de pile_t 

#define passerAuFrereSuivant(p,e)   *e = pop(p),push(p,(*e)+1) 

#define remonterAuPere(p)    pop(p)

#define noeudTerminal(p,ch)   hauteur(p)==strlen(ch)

#define naPlusDeFrereSuivant(p,ch)    valeurSommet(p)==strlen(ch)

#define rechercheTerminee(p)    pilevide(p)==1


int noeudValide(const pile_t *p)
{
int i,j;
printf("\n tailleeee de la pile = %d\n",p->sommet);
for(i=1;i<p->sommet;i++)
	for(j=i+1;j<=p->sommet;j++)
		{
		printf("\n\t compar de %d et %d",p->data[i],p->data[j]);
		if ((p->data[i])==(p->data[j])) // on a trouve un doublon !!
			{
			printf("\n je renv 0");
			return 0;}
			}

			
printf("\n je renv 1");
return 1;
}


void afficherSolution(pile_t *p,char *ch)
{
elt_t E;
pile_t p2;
init(&p2);

while(!(pilevide(p)))
{
	E = pop(p);
	printf("-->>%d",E);
	push(&p2,E);
}
// ATTENTION :: ici p est vide !!

//reconstitution de la pile initiale
while(!(pilevide(&p2)))
{
	E = pop(&p2);
	push(p,E);
}
printf("\n");


}


int main()
{
pile_t p;
elt_t E;
int gagne;
char ch[TAILLE];
init(&p);

// recherche des permutations
printf("\n Quelle est la chaine ?  (taille max = %d) : ",TAILLE);
scanf("%s",ch);
//ALGO DU POLY
do
{
// à vous de jouer ...  
// 1
gagne=0;
while( ((noeudValide(&p))==1) && (gagne==0))
{
	if (noeudTerminal(&p,ch)) //succès
		{
		if (gagne==0) 
			{printf("\n GAGNE : ");afficherSolution(&p,ch);printf("\n");}
		gagne=1;
		}
	else

	{	
		printf("\n prem fils ");
		passerAuPremierFils(&p,1); 
		afficherSolution(&p,ch);
	}
} 
// 2 
while(!(rechercheTerminee(&p)) && naPlusDeFrereSuivant(p,ch) )
{ remonterAuPere(&p); 
afficherSolution(&p,ch);
}

// 3 
if (!(rechercheTerminee(&p)))
	{passerAuFrereSuivant(&p,&E);
afficherSolution(&p,ch);
}

}while(!(rechercheTerminee(&p)));










return 0;
}




















/*

elt_t E;
int retour;

	init(&p);

	if (pilevide(&p))
		printf("\n pile vide");
	else
		printf("\n pile PAS vide");
	//****************  push *****************

	printf("\n hauteur = %d -- sommet = %f",hauteur(&p),sommet(&p));
	E=12.2;
	//printf("\n -------->%f",E);
	retour = push(&p,E);
	if (retour==1)
		printf("\n valeur bien empilée : %f",E);
	else
		printf("\n valeur NON empilée");

	printf("\n hauteur = %d -- sommet = %f",hauteur(&p),sommet(&p));

	E=15.7;
	retour = push(&p,E);
	if (retour==1)
		printf("\n valeur bien empilée : %f",E);
	else
		printf("\n valeur NON empilée");
	
	printf("\n hauteur = %d -- sommet = %f",hauteur(&p),sommet(&p));

	E=19.3;
	retour = push(&p,E);
	if (retour==1)
		printf("\n valeur bien empilée : %f",E);
	else
		printf("\n valeur NON empilée");

	printf("\n hauteur = %d -- sommet = %f",hauteur(&p),sommet(&p));
	E=22.9;
	retour = push(&p,E);
	if (retour==1)
		printf("\n valeur bien empilée : %f",E);
	else
		printf("\n valeur NON empilée");
	printf("\n hauteur = %d -- sommet = %f",hauteur(&p),sommet(&p));
	//****************  pop *****************
	
	retour=pop(&p,&E);   // premier depilement
	if (retour==1)
		printf("\n valeur bien dépilée : %f ",E);
	else
		printf("\n impossible de dépiler");
	printf("\n hauteur = %d -- sommet = %f",hauteur(&p),sommet(&p));
	

	retour=pop(&p,&E); // deuxieme depilement
	if (retour==1)
		printf("\n valeur bien dépilée : %f ",E);
	else
		printf("\n impossible de dépiler");

	printf("\n hauteur = %d -- sommet = %f",hauteur(&p),sommet(&p));

	retour=pop(&p,&E); // troisieme depilement
	if (retour==1)
		printf("\n valeur bien dépilée : %f ",E);
	else
		printf("\n impossible de dépiler");

	printf("\n hauteur = %d -- sommet = %f",hauteur(&p),sommet(&p));

	retour=pop(&p,&E); // qautrieme depilement
	if (retour==1)
		printf("\n valeur bien dépilée : %f ",E);
	else
		printf("\n impossible de dépiler");

	printf("\n hauteur = %d -- sommet = %f",hauteur(&p),sommet(&p));

*/
