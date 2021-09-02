#include "arquivo.h"


int main(){
    GRAFO g;
    g = lerArquivo("exemplo.txt");
    imprimeGrafo(g);
    return 0;
}