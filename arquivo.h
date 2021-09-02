#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "grafos.h"
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//#ifdef NDEBUG 
//int enableDebug = TRUE;
//#else 
//int enableDebug = FALSE;
//#endif

FILE* abreArquivoLeitura(char nomeArq[]);

int verificaFinalArquivo(FILE *f);

void eliminaChar(char str[], int pos);

void trim(char str[]);

void imprimeAresta(ARESTA a);

void imprimeVertice(VERTICE v);

void imprimeGrafo(GRAFO g);

int verificaOrientado(FILE *f);

int existeVertice(GRAFO *g, VERTICE *v);

void insereAresta(GRAFO *g, VERTICE *origem, VERTICE *destino, ARESTA *a);

void insereVertice(GRAFO *g, VERTICE *v);

void lerLinhas(FILE *f, GRAFO *g);

GRAFO lerArquivo(char nomeArq[]);

#endif