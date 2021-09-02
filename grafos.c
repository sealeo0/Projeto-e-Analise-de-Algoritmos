#include "grafos.h"

void imprimeAresta(ARESTA a){
    printf("Peso Aresta: %d\n", a.peso);
}

void imprimeVertice(VERTICE v){
    int i;
    printf("Vertice Numero: %d\n", v.id);
    printf("Tamanho do vetor de Arestas: %d\n", v.numArestas);
    for(i = 0; i < v.numArestas; i++){
        imprimeAresta(v.vetArestas[i]);
    }
}

void imprimeGrafo(GRAFO g){
    int i;
    printf("Quantidade de Vertices: %d\n", g.numVertices);
    printf("Orientado: %d\n\n", g.orientado);
    for(i = 0; i < g.numVertices; i++){
        imprimeVertice(g.vertices[i]);
        printf("\n");
    }
}

int existeVertice(GRAFO *g, VERTICE *v){
    int i;
    for(i = 0; i < g->numVertices; i++){
        if((g->vertices + i)->id == v->id){
            return TRUE;
        }
    }    
    return FALSE;
}

VERTICE* procuraVertice(GRAFO *g, VERTICE *v){
    int i;
    for(i = 0; i < g->numVertices; i++){
        if(v->id == g->vertices[i].id){
            return g->vertices+i; //retorna o elemento na posicao i
        }
    }
    return NULL;
}

void insereAresta(GRAFO *g, VERTICE *v1, VERTICE *v2, ARESTA *a){
    if(!existeVertice(g, v1)){
        insereVertice(g, v1);
    }
    if(!existeVertice(g, v2)){
        insereVertice(g, v2);
    }

    VERTICE *origem = procuraVertice(g, v1);
    VERTICE *destino = procuraVertice(g, v2);


    origem->vetArestas = (ARESTA* ) realloc(origem->vetArestas, (origem->numArestas + 1) * sizeof(ARESTA));        
    (origem->vetArestas + origem->numArestas)->peso = a->peso;  
    (origem->vetArestas + origem->numArestas)->verticeDestino = destino;  
    origem->numArestas++;

    if(!g->orientado){
        destino->vetArestas = (ARESTA* ) realloc(destino->vetArestas, (destino->numArestas + 1) * sizeof(ARESTA));
        (destino->vetArestas + destino->numArestas)->peso = a->peso;  
        (destino->vetArestas + destino->numArestas)->verticeDestino = origem;
        destino->numArestas++;  
    }
}

void alocaVertices(GRAFO *g, int qtde){
    g->vertices = (VERTICE* ) malloc((qtde) * sizeof(VERTICE));
    printf("Memoria alocada.\n");
}

void insereVertice(GRAFO *g, VERTICE *v){
    VERTICE *verticeInserido = (g->vertices + g->numVertices);

    verticeInserido->id = v->id;
    verticeInserido->numArestas = 0;
    verticeInserido->vetArestas = NULL;
    g->numVertices += 1;
}

