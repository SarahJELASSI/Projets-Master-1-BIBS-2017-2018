#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Allocation_mem.h"
#include "Affichage.h"
#include "Outils.h"
#include "UPGMA.h"

/* ======================= Algo UPGMA ============================ */

Arbre *Algo_UPGMA (int n, float **matrice){
	
	Arbre *arbre; 
	Liste *racines;
	Noeud *noeud ;
	Noeud *noeud_n_k ;
	Noeud *root;
	
	arbre = nouvel_arbre();
	racines = nouvelle_liste();
	
	/*Création des feuilles de l'arbre*/ 
    int i;
	for (i=0; i<n; i++){
		noeud = nouveau_noeud (i);
		ajout_element_fin (racines, noeud);
	}

	afficher_liste (racines);
	
    int k;
	for (k=0; k<n-2; k++) {
		
		printf ("=======================================\n"); 
		printf ("Itération k = %d\n" , k); 
		int i=0;
		int j=0;
		int min= INT_MAX; 
		/*Calcule de la position où la distance est minimale*/
        int ligne;
        int colonne;
		for (ligne=0; ligne < n-1-k; ligne ++){
			for (colonne=ligne+1; colonne < n-k; colonne++){
				if ((min > matrice [ligne][colonne]) && (matrice [ligne][colonne]!=0)){
					min = matrice [ligne][colonne];
					i = ligne; 
					j = colonne;
				}
			}
		}
		/* Création du nouveau noeud: noeud(n+k)*/
		noeud_n_k = nouveau_noeud (n+k); 
		noeud_n_k -> gauche = Element (racines, i); 
		noeud_n_k -> droit = Element (racines, j); 
		ajout_element_fin (racines,noeud_n_k);
		
		printf ("Nouvelle matrice de distances : %d x %d\n", n-k-1, n-k-1);
		printf ("---------------------------------------\n"); 
		
		/*Maj de M avec le nouveau noeud*/
		matrice=mise_a_jour(n-k,matrice,i,j);
		supp_element(racines,i);
		supp_element(racines,j-1);
		
		afficher_matrice(n-k-1,matrice);
		afficher_liste(racines);
	}
    
	/*int k = n-2;*/ /*<-A quoi sert-il ?*/
	root= nouveau_noeud(n+k);
	root -> gauche = Element (racines,0);
	root -> droit = Element (racines,1);
	arbre -> racine = root;
    
    
    
	free_liste(racines);
    free_matrice(matrice,2);
	return arbre;
}
