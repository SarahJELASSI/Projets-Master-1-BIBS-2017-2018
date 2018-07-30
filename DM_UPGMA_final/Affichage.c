#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Allocation_mem.h"
#include "Affichage.h"


/* ======================= Affichage  ============================ */

void afficher_matrice (int n, float **matrice){
	
    int i;
    int j;
	for (i = 0; i<n; i++){
		for (j=0; j<n; j++){
			printf ("%.2f ", matrice[i][j]);
		}
		printf("\n");
	}
}

/* affiche la liste L */
void afficher_liste(Liste *L) {    
	if (!L) return ; /* si la liste n'existe pas*/
	
	Maillon *p;
    printf("racines : ( ");
    if (L -> tete) {
		p = L -> tete;
		while (p) {
			printf ("%d ", p -> noeud->cle);
			p = p-> suivant;
		}
	}
	printf (" )\n");
}

void afficher_arbre(Arbre *A){
	printf("Arbre : ");
    if (A)
    {
        afficher_arbreAux(A->racine);
    }
    printf("\n");
}
    
void afficher_arbreAux(Noeud *N){
    if ((N->gauche!=NULL) && (N->droit!=NULL)) /*Si on est pas sur une feuille*/
    {
        printf("(");
        afficher_arbreAux(N->gauche);
        afficher_arbreAux(N->droit);
        printf(")");
    }
    else {
        printf("%d",N->cle);/*Si on est sur une feuille, on affiche le numéro du gène*/
    }
}
