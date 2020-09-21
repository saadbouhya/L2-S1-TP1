/* ------------------------------------------------------------------------ */
/**
 *  \file       epilogue.c
 *  \brief      Sequelette pour acceuillir un programme quelconcque 
 *              avec ex�cution de la fonction epilogue � la fin du
 *              programme
 *
 *  \author     saad bouhya
 *
 *  \date       14 septembre 2020
 *
 *  \version    1.0
 *
 *
 *   \remark	ce fichier doit devenir le programme principal
 *				de votre TP (SDA2_TP1_TAD_Pile_Dyn.c, par exemple)
 *
 */

/* ------------------------------------------------------------------------ */
/*		I N C L U D Es  S T A N D A R Ds									*/
/* ------------------------------------------------------------------------ */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// #include "test_pile.h"
#include "permut.h"

#include <time.h>

#include <sys/types.h>
#include <sys/timeb.h>

#if defined (_WIN32)
#include <windows.h>
#pragma comment(lib, "Ws2_32.lib")
//#elif defined (__unix__)
#else
#define  __unix__
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif


#if defined (_MSC_VER)
/* 
 *	S�lection du niveau le plus �lev� d'affichage des messages
 *	d'avertissement
 */
#pragma warning( push, 4 )

/*
 *	D�sactivation de l'affichage des messages d'avertissement li�s �
 *	l'utilisation de fonctions d�pr�ci�es par Visual C++ car rempla��es
 *	par des fonctions sp�cifiques plus s�res mais non standards
 */
#pragma warning( disable : 4996 )
#endif

int menu()
{
	int choix;

	printf("\n\n\n TP1 ");
	printf("\n\n\n 1 : test pile");
	printf("\n\n\n 2 : tester les permutations d'une chaine");
	printf("\n 0 :  QUITTER  ");
	printf("\n votre choix ?  ");
	scanf("%d",&choix);
	return choix;
}
/* ------------------------------------------------------------------------ */
/*		C O N S T A N T E S   &   P R O T O T Y P E S						*/
/* ------------------------------------------------------------------------ */
#define MAXLEN          256
void    epilogue(void);




/* ------------------------------------------------------------------------ */
/*		F O N C T I O N     P R I N C I P A L E 		    */
/* ------------------------------------------------------------------------ */
int main(void)
{
    atexit(epilogue);
    /*  Initialisation du g�n�rateur de nombres al�atoires			*/
		pile_t pile;

		int chx;

		do
		{
			chx=menu();
			switch (chx)
				{
				case 1 :  
					// On teste les fonctions de la pile
					// testPile(&pile); 
					break;
				case 2 :
					// On test les permutations d'une chaine
					testPermut();
					break;

				}
		}while(chx!=0);

    srand((unsigned int)time(NULL));


#if (0)    

#endif

   return 0;
}

/* ------------------------------------------------------------------------ */
void epilogue(void)
{
	static const char * jour[] = {
	    "Dimanche", "Lundi", "Mardi", "Mercredi",
	    "Jeudi", "Vendredi", "Samedi"};

	static const char * mois[] = {
		"Janvier", "Fevrier", "Mars"     , "Avril"  , "Mai"     , "Juin"    ,
		"Juillet", "Aout"   , "Septembre", "Octobre", "Novembre", "Decembre",
	};

	time_t ltime;
    struct tm * today;
	char userName[MAXLEN + 1] = "";
	char hostName[MAXLEN + 1] = "";
	unsigned long name_len = MAXLEN + 1;

#if defined (_WIN32)
    	WSADATA wsaData;
#endif

    struct hostent * pHostEntry;
    struct in_addr *pinAddr;

#if defined (_WIN32)
	WSAStartup(MAKEWORD(2,2), &wsaData);
#endif

	/*	Nom de l'utilisateur   					                			*/
#if defined (_WIN32)
	GetUserName(userName, &name_len);
#elif defined (__unix__)
	getlogin_r(userName,name_len);
#endif
	printf("\n%-9.9s ", userName);

	/*	Nom de l'ordinateur   								                */
    gethostname(hostName, MAXLEN);

 	/* Nom r�seau et adresse IP de l'ordinateur								*/
    pHostEntry = gethostbyname(hostName);
    if (pHostEntry != NULL)
    {
        printf("%-13.10s ", pHostEntry->h_name);
        pinAddr = ((struct in_addr *)pHostEntry->h_addr_list[0]);
        if (pinAddr != NULL)
            printf("%s ", inet_ntoa(*pinAddr));
    }

	/*	Date et heure														*/
    tzset();
	time(&ltime);
	today = localtime(&ltime);
	printf("%9s %d %s %4d a %dh %dmn %ds\n",
		jour[today->tm_wday], today->tm_mday,
		mois[today->tm_mon], today->tm_year + 1900,
		today->tm_hour, today->tm_min, today->tm_sec);

#if defined (_WIN32)
	WSACleanup();
#endif
}
/* ------------------------------------------------------------- THE END -- */

