#include <stdbool.h>

#ifndef OUTILS_H

void ajout_element_fin(Liste *L, Noeud *noeud);
int supp_element(Liste *L, int k);
Noeud *Element (Liste *L, int i);
float **mise_a_jour (int n_k, float **matrice, int i, int j);
void remplissage (int n, float **matrice);
int random_number(int min_value, int max_value);


#endif /*!OUTILS_H*/
