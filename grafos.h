#ifndef GRAFOS_H
#define GRAFOS_H

#include <stdio.h>

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



#endif