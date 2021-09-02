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

int existeVertice(GRAFO *g, VERTICE *v){
    int i;
    for(i = 0; i < g->numVertices; i++){
        if((g->vertices + i)->id == v->id){
            return TRUE;
        }
    }    
    return FALSE;
}

void insereAresta(GRAFO *g, VERTICE *origem, VERTICE *destino, ARESTA *a){
    if(!existeVertice(g, origem)){
        insereVertice(g, origem);
    }
    if(!existeVertice(g, destino)){
        insereVertice(g, destino);
    }

    origem->vetArestas = (ARESTA* ) realloc(origem->numArestas + 1, sizeof(ARESTA));
    (origem->vetArestas + origem->numArestas)->peso = a->peso;  
    (origem->vetArestas + origem->numArestas)->verticeDestino = destino;  


}

void insereVertice(GRAFO *g, VERTICE *v){
    g->vertices = (VERTICE* ) realloc(g->numVertices + 1, sizeof(VERTICE));
    VERTICE *verticeInserido = (g->vertices + g->numVertices);


    if(enableDebug){
        printf("Inserido vertice com id: %d\n", v->id);    
    }
    
    verticeInserido->id = v->id;
    verticeInserido->numArestas = 0;
    verticeInserido->vetArestas = NULL;
    
    
}

void lerLinhas(FILE *f, GRAFO *g){
    char str[15];
    VERTICE v1, v2;
    int peso;
    while(!verificaFinalArquivo(f)){
        fscanf(f, "(%d,%d):%d", &(v1.id), &(v2.id), &peso);

        
    }

}

GRAFO lerArquivo(char nomeArq[]){
    
    FILE *f = abreArquivoLeitura(nomeArq);
    GRAFO g;

    if(verificaFinalArquivo(f)){
        printf("Arquivo corrompido, programa sera encerrado.\n");
        exit(1);
    }

    g.orientado = verificaOrientado(f);
    g.numVertices = 0;
    printf("%d", g.orientado);



}