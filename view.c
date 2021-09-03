#include "view.h"

int menuInicial(){
	int resposta;
	
	printf("==============================================================\n");		
	printf("|                                                            |\n");
	printf("|                           Grafos                           |\n");	
	printf("|                                                            |\n");
	printf("==============================================================\n");	
	printf("|                           Menu inicial                     |\n");	
	printf("|                                                            |\n");
	printf("|   (1) %c Busca em profundidade                               |\n", 187);	
	printf("|   (2) %c Busca em largura                                    |\n", 187);
	printf("|   (3) %c Algoritmo de Bellman-Ford                           |\n", 187);	
	printf("|   (4) %c Algoritmo de kruskal                                |\n", 187);	
	printf("|                                                            |\n");
	printf("|                 [0] %c Encerrar programa                     |\n", 187);
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