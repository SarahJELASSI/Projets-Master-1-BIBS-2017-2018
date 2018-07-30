#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Allocation_mem.h"


/* ========================= Allocation memoire ============================= */

/* Cree un nouvel arbre binaire et renvoie un pointeur vers cet arbre. */
Arbre *nouvel_arbre() {
    
    Arbre *arbre = (Arbre *) malloc (sizeof (Arbre));
	if (!arbre){ /* si arbre vaut NULL donc que malloc n'a pas retourné une adresse valide. */
		fprintf(stderr,"l'allocation de mémoire a échoué! Donc l'arbre n'a pas été crée.\n");
		exit(1);
	}
	arbre -> racine = NULL;
    return arbre;
    
}

/* Cree un nouveau noeud et renvoie un pointeur vers ce noeud */
Noeud *nouveau_noeud(int val) {
	
	Noeud *noeud = (Noeud *) malloc (sizeof (Noeud));
	
	if (!noeud){ /*si noeud vaut NULL donc que malloc n'a pas retourné une adresse valide*/
		fprintf(stderr,"l'allocation de mémoire a échoué! Donc le noeud n'a pas été crée.\n");
		exit(1);
	}
	noeud -> cle = val;
	noeud -> gauche = NULL;
	noeud -> droit = NULL;
    return noeud;

}

/* crée un nouveau maillon qui un pointeur vers un noeud et vers le maillon suivant de la liste.*/
Maillon *nouveau_maillon(Noeud *noeud) {
	
	Maillon *maillon = (Maillon*) malloc (sizeof (Maillon));
	
	if (!maillon){ /* si maillon vaut NULL donc que malloc n'a pas retourné une adresse valide. */
		fprintf(stderr,"l'allocation de mémoire a échoué! Donc le maillon n'a pas été crée.\n");
		exit(1);
	}
	maillon -> noeud = noeud;
	maillon -> suivant = NULL ;
    return maillon;
}

/* crée une nouvelle liste et renvoie un pointeur vers cette liste. */
Liste *nouvelle_liste() {
	
	Liste *liste = (Liste *) malloc (sizeof (Liste));
	
	if (!liste){ /*si liste vaut NULL donc que malloc n'a pas retourné une adresse valide. */
		fprintf(stderr,"l'allocation de mémoire a échoué! Donc la liste n'a pas été crée.\n");
		exit(1);
	}
	liste -> tete = NULL;
    return liste;
}

float ** nouvelle_matrice(int lignes, int colonnes){ /* Une étoile correspond à un pointeur donc 2 étoiles est un pointeur de pointeur (tableau 2 dimensions).*/
	float ** matrice = (float **) malloc (lignes *sizeof(float *));
	if (matrice == NULL) {
		fprintf(stderr, "Memoire insuffisante. \n");
		exit(EXIT_FAILURE);
	}
    int i;
	for (i =0; i<lignes; i++){
		matrice [i] = (float *) malloc (colonnes *sizeof(float));
		if (matrice[i] == NULL){
			fprintf(stderr, "Memoire insuffisante.\n");
			exit (EXIT_FAILURE);
		}
	}
	
	return matrice;
}

/* ======================= Desallocation memoire ============================ */

void free_matrice(float **matrice, int n ){
    int i;
	for (i = 0; i < n; i++){
		
		free(matrice[i]);
	}
	free(matrice);
}  

void free_liste(Liste *L) {
    Maillon *p;
    Maillon *q;
    if (L==NULL) 
        return;
    if (L->tete){
        p=L->tete;
        while(p){
            q=p;
            p=p->suivant;
            free(q);
        }
        free(L);
    }/*free_liste(Liste *)*/
}

/* Libere la memoire allouee a un arbre et a tous ses noeuds */
void free_arbre(Arbre *A) {
    if (A==NULL) return;
    free_arbre_aux(A->racine);
    free(A);
}

void free_arbre_aux(Noeud *N){
    if (N==NULL) return;
    free_arbre_aux(N->gauche);
    free_arbre_aux(N->droit);
    free(N);
}
