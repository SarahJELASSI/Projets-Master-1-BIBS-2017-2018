#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Allocation_mem.h"
#include "Outils.h"

/*
 * 
 * Remplissage aléatoire d'une matrice des distances
 * 
 * */
 
void remplissage (int n, float **matrice)
{
    int i;
    int j;
    for (i=0 ; i<=n-1 ; i++){
        for (j=0; j<=n-1; j++){
            matrice[i][j]=matrice[j][i]=(float) random_number(0,10);
            matrice[i][i]=0;
        }
    }
}


int random_number(int min_value, int max_value) 
{
	int result= 0;
	result= rand()% (max_value-min_value); /*renvoie un entier dans un intervalle [min_value ; max_value[  */
	result+=min_value;
	return result;
}



/*
 * 
 * Mise à jour de la matrice des distances
 * 
 * */

float ** mise_a_jour(int n_k, float **matrice, int i, int j) {

	float **new_matrice = nouvelle_matrice(n_k, n_k); 
	/* remplissage de la nouvelle matrice*/ 
	int compteur_ligne=0;
	int compteur_colonne=0;
    int ligne;
    int colonne;
	for (ligne = 0; ligne < n_k; ligne ++) {
		if (ligne==i || ligne==j){ /*Si on est sur une ligne à supprimer, on la saute à l'aide d'un compeur*/
				compteur_ligne++;
		}
		else{
			compteur_colonne=0; 
			if(ligne>i) 
				compteur_colonne++;
			if(ligne>j)
				compteur_colonne++;
			for (colonne = ligne ; colonne <= n_k; colonne ++) { /*parcours symetrique : 
                                                                 on se déplace à partir du numéro de la colonne correpondant à la ligne ce qui nous fait nous déplacer seulement sur la moitié haut-gauche de la matrice*/
				if((colonne==i || colonne==j)){ /*on saute la colonne si elle doit être supprimée*/
					compteur_colonne++;
				}
				else {
					if (colonne-compteur_colonne == n_k-2){ /* si on est sur la denière colonne de la nouvelle matrice, on la rempli en calculant les nouvelles distances*/
						new_matrice[ligne-compteur_ligne][colonne-compteur_colonne] = (double) (matrice[ligne][i]+matrice[ligne][j]) /2 ;
						new_matrice[colonne-compteur_colonne][ligne-compteur_ligne] = (double) (matrice[ligne][i]+matrice[ligne][j]) /2 ;
					}
					else if ((ligne-compteur_ligne)==(colonne-compteur_colonne)){ /*si on est sur la diagonale, on la remplie de 0*/
						new_matrice[ligne-compteur_ligne][colonne-compteur_colonne] = 0.00;
					}
					else {
						new_matrice[ligne-compteur_ligne][colonne-compteur_colonne] = matrice[ligne][colonne]; /* sinon on copie les valeurs de l'ancienne matrice*/
						new_matrice[colonne-compteur_colonne][ligne-compteur_ligne] = matrice[ligne][colonne]; 
					}
				}
			}
		}
	}
    
	free_matrice(matrice,n_k); /*on désalloue la place en mémoire de l'ancienne matrice*/
	return new_matrice;
}


/* ======================= Fonctions sur les listes ============================ */

void ajout_element_fin(Liste *L, Noeud *noeud) {
	if (!L) return ; /* si la liste n'existe pas*/
	
	Maillon *ajoutfin = nouveau_maillon(noeud);
	
	if (L -> tete == NULL) { /* si la liste est vide*/
		L -> tete = ajoutfin;
	}
	else {
		Maillon *p = L -> tete;
		while (p -> suivant != NULL){ 
			p = p -> suivant;
		}
		p -> suivant = ajoutfin;
	}
}

/* supprime le k-ième élément de la liste (on suppose que la première place est
 * 1); si c'est possible, on modifie la liste et on renvoie la valeur 1; sinon,
 * on ne modifie pas la liste et on renvoie la valeur 0 */
int supp_element(Liste *L, int k) {
	
	Maillon *PC;
	Maillon *PPC;

	int compteur=1;
	
	if (!L) return 0;
	else if(k==0){
		Maillon *p = L-> tete;
		L -> tete = p -> suivant;
		free (p);
		return 1;
	}
	else{
		PC = L -> tete;
		while (compteur < k){
			if (PC -> suivant == NULL)
				return 0;
			PC = PC -> suivant; 
			compteur ++;
		}
		PPC = PC -> suivant;
		PC ->suivant = PPC -> suivant;
		free(PPC);
		return 1;
	}
}

Noeud *Element (Liste *L, int i){
	if (!L) return NULL ; 
	Maillon *p;
	int compteur = 0; 
	
	if (L -> tete) {
		p = L -> tete;
		
		while (compteur < i) {
			if (p -> suivant == NULL)
				return NULL;
			p = p-> suivant;
			compteur ++;
		}
	
		return p -> noeud;
	} else {
		return NULL;
	}
}
