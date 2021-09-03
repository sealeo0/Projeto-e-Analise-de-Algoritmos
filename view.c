#include "view.h"

int menuInicial(){
	int resposta;
	
	printf("==============================================================\n");		
	printf("|                                                            |\n");
	printf("|                           Grafos                           |\n");	
	printf("|                                                            |\n");
	printf("==============================================================\n");	
	printf("|                        Menu inicial                        |\n");	
	printf("|                                                            |\n");
	printf("|   (1) Busca em profundidade                                |\n");	
	printf("|   (2) Busca em largura                                     |\n");
	printf("|   (3) Algoritmo de Bellman-Ford                            |\n");	
	printf("|   (4) Algoritmo de kruskal                                 |\n");	
	printf("|                                                            |\n");
	printf("|                 [0] Encerrar programa                      |\n");
	printf("|                                                            |\n");
	printf("==============================================================\n");
	scanf("%d%*c", &resposta);
	return resposta;
}

int sairPrograma(){
	int opcao;
	
	printf("\x1B[1;31m");
	printf("=====================================\n");		
	printf("|                                   |\n");
	printf("|            Livraria AED           |\n");	
	printf("|                                   |\n");
	printf("=====================================\n");	
	printf("|                                   |\n");
	printf("|      Deseja sair do programa?     |\n");
	printf("|         (1) SIM   (2)NÃO          |\n");
	printf("|                                   |\n");
	printf("=====================================\n");
	printf("\x1B[0;0m");
	scanf("%d", &opcao);
	
	return opcao;
}