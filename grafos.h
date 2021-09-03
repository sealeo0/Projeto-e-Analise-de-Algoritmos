#ifndef GRAFOS_H
#define GRAFOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct vertice{
    int id;
    struct aresta *vetArestas;
    int numArestas;
} typedef VERTICE;

struct aresta{
    int peso;
    VERTICE *verticeDestino;
} typedef ARESTA;

struct grafo{
    VERTICE *vertices;
    int orientado;
    int numVertices;
}typedef GRAFO;

void imprimeAresta(ARESTA a);

void imprimeVertice(VERTICE v);

void imprimeGrafo(GRAFO g);

int existeVertice(GRAFO *g, VERTICE *v);

void insereAresta(GRAFO *g, VERTICE *origem, VERTICE *destino, ARESTA *a);

void alocaVertices(GRAFO *g, int qtde);

int encontraPosicaoInsercao(GRAFO *g, VERTICE *v);

void copiaVertice(VERTICE *destino, VERTICE *origem);

void atualizaArestas(GRAFO *g, VERTICE *v);

void deslocaDireita(GRAFO *g, int pos);

void insereVertice(GRAFO *g, VERTICE *v);

#endif