#include "algoritmos.h"

void buscaProfundidadeVisita(VERTICE *v, int *cor, int *pi){
    cor[v->id] = CINZA;
    printf("%d", v->id);
    int i;
    for(i = 0; i < v->numArestas; i++){
        if(cor[v->vetArestas[i].verticeDestino->id] == BRANCO){
            pi[v->vetArestas[i].verticeDestino->id] = v->id;
            printf(" - ");
            buscaProfundidadeVisita(v->vetArestas[i].verticeDestino, cor, pi);
        }
    }
    cor[v->id] = PRETO;
}

void buscaProfundidade(GRAFO *g, int id){
    int *cor = (int* ) malloc((g->numVertices)*sizeof(int));
    int *pi = (int* ) malloc((g->numVertices)*sizeof(int));

    int existe = 0;

    int i;
    for(i = 0; i < g->numVertices; i++){
        cor[i] = BRANCO;
        pi[i] = NIL;
    }   

    for(i = 0; i < g->numVertices; i++){
        if(g->vertices[i].id == id){
            buscaProfundidadeVisita(g->vertices+i, cor, pi);
            existe = 1;
        }
    }
    
    if(!existe){
        printf("O Vertice escolhido nao esta no grafo\n");
    }

    printf("\n");

    free(pi);
    free(cor);
}

NO_FILA* alocaNoFila(){
	NO_FILA *no = malloc(sizeof(NO_FILA));
	no->next = NULL;
	return no;
}

FILA* alocaFila(){
	FILA *f = malloc(sizeof(FILA));
	f->first = NULL;
	f->last = NULL;
	return f;
}

int vazia(FILA *f){
	return f->first == NULL;
}

void insereFinal(FILA *f, int x){
	if(f != NULL){
		NO_FILA *no = alocaNoFila();
		no->id = x;
		if(vazia(f)){
			f->first = no;
			f->last = no;
		}
		else{
			f->last->next = no;
			f->last = no;
		}
	}
	else{
		printf("ERRO\n");
	}
}

void removeComeco(FILA *f){
	NO_FILA *aux = f->first;
	if(f->first == f->last){
		free(aux);
		f->first = NULL;
		f->last = NULL;
	}
	else{
		f->first = aux->next;
		free(aux);
	}
}

void imprimeFila(FILA *f){
	if(vazia(f)){
		printf("A lista esta vazia.\n");
	}	
	else{
		NO_FILA *aux;
		for(aux = f->first; aux != NULL; aux = aux->next){
            printf("%d\n", aux->id);
		}
	}
}

void buscaLargura(GRAFO *g, VERTICE *v){
    int *cor = (int* ) malloc((g->numVertices)*sizeof(int));
   
    int i;

    VERTICE *u;

    FILA *f = alocaFila();

    for(i = 0; i < g->numVertices; i++){
        cor[i] = BRANCO;
    }  

    cor[v->id] = CINZA;
    insereFinal(f, v->id);

    printf("%d", f->first->id);

    while(!vazia(f)){

        u = retornaVertice(g, f->first->id);

        for(i = 0; i < u->numArestas; i++){
            if(cor[u->vetArestas[i].verticeDestino->id] == BRANCO){
                cor[u->vetArestas[i].verticeDestino->id] = CINZA;
                insereFinal(f, u->vetArestas[i].verticeDestino->id);
            }
        }
        removeComeco(f);

        if(f->first!= NULL){
            printf(" - %d", f->first->id);
        }
    }  

    printf("\n");

    free(cor);
    free(f->first);
    free(f->last);
    free(f);
}