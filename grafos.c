#include "grafos.h"

void imprimeAresta(ARESTA a){
    printf("Peso Aresta: %d\n", a.peso);
    printf("Destino da aresta: %d\n", a.verticeDestino->id);
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

int encontraPosicaoInsercao(GRAFO *g, VERTICE *v){
    int i; 
    for(i = 0; i < g->numVertices; i++){
        if(g->vertices[i].id > v->id){
            return i;
        }
    }
    return g->numVertices;
}

void copiaVertice(VERTICE *destino, VERTICE *origem){
    destino->id = origem->id;
    destino->numArestas = origem->numArestas;
    destino->vetArestas = origem->vetArestas;
}

void atualizaArestas(GRAFO *g, VERTICE *v){
    int i, j;
    for(i = 0; i < g->numVertices; i++){
        for(j = 0; j < g->vertices[i].numArestas; j++){
            if(g->vertices[i].vetArestas[j].verticeDestino->id == v->id){
                g->vertices[i].vetArestas[j].verticeDestino = v + 1;//DESLOCANDO O ENDERECO PARA A POSICAO A DIREITA
            }
        }
    }
}

void deslocaDireita(GRAFO *g, int pos){
    int i;
    for(i = g->numVertices; i > pos; i--){
        atualizaArestas(g, (g->vertices + i - 1));
        copiaVertice(&g->vertices[i], &g->vertices[i-1]);
    }
}

void insereVertice(GRAFO *g, VERTICE *v){
    int pos = encontraPosicaoInsercao(g, v);

    deslocaDireita(g, pos);

    VERTICE *verticeInserido = (g->vertices + pos);
    
    copiaVertice(verticeInserido, v);

    g->numVertices += 1;

}

void ordenaArestasVertice(VERTICE *v){
    int i, j;
    ARESTA temp;
    for(i = v->numArestas - 1; i >= 0; i--){
        for(j = 1; j <= i; j++){
            if(v->vetArestas[j-1].verticeDestino->id > v->vetArestas[j].verticeDestino->id) {
                temp = v->vetArestas[j-1];
                v->vetArestas[j-1] = v->vetArestas[j];
                v->vetArestas[j] = temp;
            }
        }
    }
}

void ordenaArestasVerticesGrafo(GRAFO *g){
    int i;
    for(i = 0; i < g->numVertices; i++){
        ordenaArestasVertice(g->vertices + i);
    }    
}

VERTICE* retornaVertice(GRAFO *g, int id){
    int i;
    for(i = 0; i < g->numVertices; i++){
        if(g->vertices[i].id == id){
            return g->vertices+i;
        }
    }
    return NULL;
}

