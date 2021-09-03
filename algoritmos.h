#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "arquivo.h"

#define BRANCO 10
#define CINZA 20
#define PRETO 30
#define NIL -1

struct no{
	int id;
	struct no *next;
}typedef NO_FILA;

struct fila{
	NO_FILA *first;
	NO_FILA *last;
}typedef FILA;

void buscaProfundidadeVisita(VERTICE *v, int *cor, int *pi);

void buscaProfundidade(GRAFO *g, int id);

NO_FILA* alocaNoFila();

FILA* alocaFila();

int vazia(FILA *f);

void insereFinal(FILA *f, int x);

void imprimeFila(FILA *f);

void removeComeco(FILA *f);

void buscaLargura(GRAFO *g, VERTICE *v);

#endif