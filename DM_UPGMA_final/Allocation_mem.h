#include <stdbool.h>

#ifndef ALLOCATION_MEM_H


/* ========================= Structures ============================= */
typedef struct Noeud Noeud;
typedef struct Maillon Maillon;
typedef struct Liste Liste;
typedef struct Arbre Arbre;

struct Noeud {
    int cle;
    struct Noeud *gauche;
    struct Noeud *droit;
};

struct Maillon {
    Noeud *noeud;
    Maillon *suivant;
};

struct Liste {
    Maillon *tete;
};

struct Arbre {
    Noeud *racine;
};

/* ========================= Fonctions ============================= */
Arbre *nouvel_arbre();
Noeud *nouveau_noeud(int val);
Liste *nouvelle_liste();
Maillon *nouveau_maillon(Noeud *noeud);
void free_matrice(float **matrice, int n);
float ** nouvelle_matrice(int lignes, int colonnes);
void free_liste(Liste *L);
void free_arbre(Arbre *A);
void free_arbre_aux(Noeud *N);

#endif /*!ALLOCATION_MEM_H*/
