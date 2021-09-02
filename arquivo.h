#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "grafos.h"
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#ifdef NDEBUG 
int enableDebug = TRUE;
#else 
int enableDebug = FALSE;
#endif

FILE* abreArquivoLeitura(char nomeArq[]);

int verificaFinalArquivo(FILE *f);

void eliminaChar(char str[], int pos);

void trim(char str[]);

int verificaOrientado(FILE *f);

GRAFO lerArquivo(char nomeArq[]);

#endif