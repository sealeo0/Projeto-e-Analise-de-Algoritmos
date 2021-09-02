#include "arquivo.h"

FILE* abreArquivoLeitura(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    
    if(f == NULL){
        printf("Erro ao abrir o arquivo, programa sera encerrado.\n");
        exit(1);
    }

    return f;

}

int verificaFinalArquivo(FILE *f){
    return feof(f);
}

void eliminaChar(char str[], int pos){
    int i;
    for(i = pos; str[i] != '\0'; i++){
        str[i] = str[i+1];
    }
}

void trim(char str[]){
    int i;
    
    while(str[0] == ' '){
        eliminaChar(str, 0);
    }
    
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            while(str[i+1] == ' '){
                eliminaChar(str, i);
            }
        }
    }

    if(str[i-1] == ' '){
        eliminaChar(str, i-1);
    }
}

int verificaOrientado(FILE *f){
    char str[20];
    fscanf(f, " %[^\n]\n", str);
    trim(str);
    if(strcmp(str, "orientado=sim") == 0){
        return TRUE;
    }
    else if(strcmp(str, "orientado=nao") == 0){
        return FALSE;
    }
    else{
        printf("Argumento Invalido, programa sera encerrado.\n");
        exit(1);
    }
}

int verificaTotalVertices(FILE *f){
    int qtde;
    fscanf(f, "V=%d\n", &qtde);
    return qtde;
}

void lerArestas(FILE *f, GRAFO *g){
    VERTICE v1, v2;
    v1.numArestas = 0;
    v2.numArestas = 0;
    ARESTA a;
    while(!verificaFinalArquivo(f)){
        fscanf(f, "(%d,%d):%d\n", &(v1.id), &(v2.id), &(a.peso));

        insereAresta(g, &v1, &v2, &a);
    }
}

GRAFO lerArquivo(char nomeArq[]){
    
    FILE *f = abreArquivoLeitura(nomeArq);
    GRAFO g;
    int total;

    if(verificaFinalArquivo(f)){
        printf("Arquivo corrompido, programa sera encerrado.\n");
        exit(1);
    }

    g.orientado = verificaOrientado(f);

    if(verificaFinalArquivo(f)){
        printf("Arquivo corrompido, programa sera encerrado.\n");
        exit(1);
    }

    total = verificaTotalVertices(f);

    alocaVertices(&g, total);

    g.numVertices = 0; //Indice inicial no grafo


    lerArestas(f, &g);


    return g;
}