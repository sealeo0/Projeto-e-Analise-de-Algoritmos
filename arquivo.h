#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "grafos.h"


//#ifdef NDEBUG 
//int enableDebug = TRUE;
//#else 
//int enableDebug = FALSE;
//#endif

FILE* abreArquivoLeitura(char nomeArq[]);

int verificaFinalArquivo(FILE *f);

void eliminaChar(char str[], int pos);

void trim(char str[]);

int verificaOrientado(FILE *f);

int verificaTotalVertices(FILE *f);

void lerArestas(FILE *f, GRAFO *g);

GRAFO lerArquivo(char nomeArq[]);

#endif