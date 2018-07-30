#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Allocation_mem.h"
#include "Affichage.h"
#include "Outils.h"
#include "UPGMA.h"

int main()
{
    char option;
    int n;
    
	printf ("---------------------------------------\n");
    printf("\nDésirez-vous une matrice des distances aléatoire (tapez a) \nou la matrice des distance de l'énoncé (tapez b) ?\n -a \n -b \n");
	
    scanf("%c", &option);
    
    switch(option)
    {
        case 'a':
                printf("De quelle taille ?"); scanf("%d",&n);
                float **matrice_test_alea = nouvelle_matrice(n,n);
                remplissage(n,matrice_test_alea);
                
                
                printf ("Matrice initiale de distance (%d x %d)\n" , n, n); 
                printf ("---------------------------------------\n"); 
                afficher_matrice(n,matrice_test_alea);
                Arbre *arbre_alea=nouvel_arbre();
                arbre_alea = Algo_UPGMA(n, matrice_test_alea);
                afficher_arbre(arbre_alea);
                
                free_arbre(arbre_alea);
                free_matrice(matrice_test_alea,n);
                break ;
        
        case 'b' :
                n = 5;
                float **matrice_test = nouvelle_matrice(n,n);
                matrice_test[0][0]=0.f; matrice_test[0][1]=2.f; matrice_test[0][2]=3.f; matrice_test[0][3]=1.f; matrice_test[0][4]=6.f;
                matrice_test[1][0]=2.f; matrice_test[1][1]=0.f; matrice_test[1][2]=7.f; matrice_test[1][3]=4.f; matrice_test[1][4]=2.f;
                matrice_test[2][0]=3.f; matrice_test[2][1]=7.f; matrice_test[2][2]=0.f; matrice_test[2][3]=1.f; matrice_test[2][4]=8.f;
                matrice_test[3][0]=1.f; matrice_test[3][1]=4.f; matrice_test[3][2]=1.f; matrice_test[3][3]=0.f; matrice_test[3][4]=3.f;
                matrice_test[4][0]=6.f; matrice_test[4][1]=2.f; matrice_test[4][2]=8.f; matrice_test[4][3]=3.f; matrice_test[4][4]=0.f;
                
                
                printf ("Matrice initiale de distance (%d x %d)\n" , n, n); 
                printf ("---------------------------------------\n"); 
                afficher_matrice(n,matrice_test);
                Arbre *arbre=nouvel_arbre();
                arbre = Algo_UPGMA(n, matrice_test);
                afficher_arbre(arbre);
                
                free_arbre(arbre);
                free_matrice(matrice_test,n);
                break ;
                
        default :
                printf("Ce n'est pas une option\n");
                break;
    }
    
    
	return 0;
}

