#include "view.h"


int main(int argc, char **argv){
    GRAFO g;

    if(argc != 2){
        printf("Quantidade de argumentos invalida.\n");
        exit(1);
    }

    g = lerArquivo(argv[1]);
    imprimeGrafo(g);

    int resposta;

    resposta = menuInicial();


    while(resposta){
        switch(resposta){
            case 1:
                //buscaProfundidade
                break;
            case 2:
                //buscaLargura
                break;
            case 3:
                //bellmanFord
                break;       
            case 4:
                //Kruskal
                break;                             
        }
        
        resposta = menuInicial();
    }

    printf("Encerrando programa.\n");
    return 0;
}