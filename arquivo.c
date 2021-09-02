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
    printf("Orientado: %d", g.orientado);
    for(i = 0; i < g.numVertices; i++){
        imprimeVertice(g.vertices[i]);
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

    if(origem->numArestas){
        origem->vetArestas = (ARESTA* ) realloc(origem->vetArestas, (origem->numArestas + 1) * sizeof(ARESTA));        
        (origem->vetArestas + origem->numArestas)->peso = a->peso;  
        (origem->vetArestas + origem->numArestas)->verticeDestino = destino;  
        origem->numArestas++;
    }
    else{
        origem->vetArestas = (ARESTA* ) malloc((origem->numArestas + 1) * sizeof(ARESTA));
        (origem->vetArestas + origem->numArestas)->peso = a->peso;  
        (origem->vetArestas + origem->numArestas)->verticeDestino = destino;  
        origem->numArestas++;        
    }

    if(!g->orientado){
        if(destino->numArestas){
            destino->vetArestas = (ARESTA* ) realloc(destino->vetArestas, (destino->numArestas + 1) * sizeof(ARESTA));
            (destino->vetArestas + destino->numArestas)->peso = a->peso;  
            (destino->vetArestas + destino->numArestas)->verticeDestino = origem;
            destino->numArestas++;  
        }
        else{
            destino->vetArestas = (ARESTA* ) malloc((destino->numArestas + 1) * sizeof(ARESTA));
            (destino->vetArestas + destino->numArestas)->peso = a->peso;  
            (destino->vetArestas + destino->numArestas)->verticeDestino = origem;
            destino->numArestas++;            
        }
    }
    printf("PIROCA\n");
}

void insereVertice(GRAFO *g, VERTICE *v){
    if(g->numVertices){ //GAMBIARRA 
        g->vertices = (VERTICE* ) realloc(g->vertices, (g->numVertices + 1) * sizeof(VERTICE));
    }
    else{
        g->vertices = (VERTICE* ) malloc((g->numVertices + 1) * sizeof(VERTICE));
    }
    VERTICE *verticeInserido = (g->vertices + g->numVertices);
    g->numVertices += 1;


//    if(enableDebug){
   //     printf("Inserido vertice com id: %d\n", v->id);    
    //}
    
    verticeInserido->id = v->id;
    verticeInserido->numArestas = 0;
    verticeInserido->vetArestas = NULL;
    
}

void lerLinhas(FILE *f, GRAFO *g){
    char str[15];
    VERTICE v1, v2;
    ARESTA a;
    while(!verificaFinalArquivo(f)){
        fscanf(f, "(%d,%d):%d", &(v1.id), &(v2.id), &(a.peso));
        printf("%d %d %d", v1.id, v2.id, a.peso);

        insereAresta(g, &v1, &v2, &a);
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
    printf("%d\n", g.orientado);

    lerLinhas(f, &g);

    imprimeGrafo(g);


    return g;
}