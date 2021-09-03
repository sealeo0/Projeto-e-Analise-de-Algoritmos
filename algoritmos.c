#include "algoritmos.h"

void buscaProfundidade(GRAFO *g, int id, int *timestamp){
    int *cor = (int* ) malloc((g->numVertices)*sizeof(int));
    int *pi = (int* ) malloc((g->numVertices)*sizeof(int));

    int i;
    for(i = 0; i < g->numVertices; i++){
        cor[i] = BRANCO;
        pi[i] = NIL;
    }   

    *timestamp = 0;

    for(i = 0; i < g->numVertices; i++){
        if(cor[i] == BRANCO){
            buscaProfundidadeVisita(g->vertices+i);
        }
    }

    free(pi);
    free(cor);
}