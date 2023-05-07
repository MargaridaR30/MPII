/*********************************/
/* IMPLEMENTAÇÃO - gestaoGrafo.h*/
/*******************************/
//Faz a gest˜ao do grafo:utilizando o T.A.D. Grafo, um interface minimal,
// lê/escreve do ficheiro e faz a manipulaç˜ao do grafo


#include <stdio.h>
#include <stdlib.h>

#include "TADGrafo.h"
#include "gestaoGrafo.h"

//Função que faz a leitura da matriz de adjacência do ficheiro mapa.dados	
void lerMatriz(Grafo *g){
    FILE *fdados;
    int i,j;
    fdados=fopen("mapa.dados","r"); //abrir e ler ficheiro
    fscanf(fdados,"%d",&g->numNos);
    for (i=0;i<g->numNos;i++){
        for (j=0;j<g->numNos;j++){
            fscanf(fdados,"%d",&g->matAdj[i][j].dist);
            fscanf(fdados,"%s",g->matAdj[i][j].estrada);
    }}
    for (i=0;i<g->numNos;i++){
        fgets(g->infoNos[i],20,fdados);
    }
    fclose(fdados);

}

//Função que escreve a Matriz
void escreverMatriz(Grafo *g){
	
    int i,j;
    printf("Matriz:\n");
        for (i=0;i < g->numNos;i++){
        for (j=0;j < g->numNos;j++){
            printf("(%d %s)",g->matAdj[i][j].dist,g->matAdj[i][j].estrada);//representação da informação de cada arco (distancia estrada)
          }printf("\n");
       }
    for (i=0;i<g->numNos;i++){
        printf("%s ", g->infoNos[i]);
    }
}
/*
//Função que permite alojar as novas alterações no ficheiro mapa.dados-apenas usada para verificar se funcionava o código
void escreverFicheiro(Grafo *g){
	FILE *fdados;
    int i,j;
    fdados=fopen("mapa.dados","w"); //abrir e escrever no ficheiro
    fprintf(fdados,"%d\n",g->numNos);
    for (i=0;i<g->numNos;i++){
        for (j=0;j<g->numNos;j++){
            fprintf(fdados,"%d ",g->matAdj[i][j].dist);
            fprintf(fdados,"%s ",g->matAdj[i][j].estrada);
             } 
            fprintf(fdados,"\n");
          }
    for (i=0;i<g->numNos;i++){
        fprintf(fdados, "%s \n", g->infoNos[i]);
       }
    fclose(fdados);
}*/

//Função que permite manipular/alterar o grafo
Grafo manipularGrafo( ){
	
	int choice=-1;
	char caux[20];//variavel char para cidades e para estradas
	int noPartida, noDestino, distancia;
	
	Grafo g;
	g=criaGrafo();
	lerMatriz(&g);

	printf ("\nQue opcao deseja?");
	while (choice!=0){ //o 0 faz com que o ciclo pare de correr
		//especificação das opções ao utilizador
		printf ("\n0-Nao continuar a manipular o grafo.\n");
		printf ("1-Inserir No.\n");
		printf ("2-Retirar No.\n");
		printf ("3-Editar a informacao do No.\n");
		printf ("4-Inserir Arco.\n");
		printf ("5-Retirar Arco.\n");
		printf ("6-Editar a informacao do Arco.\n");

		scanf("%d", &choice);
		switch (choice){
			case 0:
				break;
			case 1:		//inserir nó
			
			    printf("Informacao do No: \n");
			    scanf("%s",caux);
				inserirNo(&g, caux);
				
				break;
				
			case 2:		//retirar nó
			
				printf("Numero do no a retirar: \n");
				scanf("%d", &noPartida);
				retirarNo(&g, noPartida);
				
				break;
				
			case 3:		//editar a informação do nó
		
				printf("Numero do no a alterar e o novo nome:   \n");
				scanf("%d %s", &noPartida, caux);
				editarInfoNo(&g, noPartida, caux);
				
				break;
				
			case 4:		//inserir arco
			
			    printf("Insira o noPartida, o noDestino, a distancia e o novo nome:        \n");
			    scanf("%d %d %d %s", &noPartida, &noDestino, &distancia, caux);
				inserirArco(&g, noPartida, noDestino, distancia, caux);
				
				break;
				
			case 5:		//retirar arco
			
				printf("Insira o noPartida e o noDestino:    \n");
				scanf("%d %d", &noPartida, &noDestino);
				retirarArco(&g, noPartida, noDestino);
				
				break;
				
			case 6:		//editar a informação do arco
			
				printf("Insira o noPartida, o noDestino, a nova distancia e o novo nome:        \n");
				scanf("%d %d %d %s", &noPartida, &noDestino, &distancia, caux);
				editarInfoArco(&g, noPartida, noDestino, distancia, caux);
			
				break;
			
			default:		//caso o utilizador insira um número diferente das opções irá dar aviso de erro - opção desconhecida
				printf("Opcao desconhecida \n");
				break;
		}
		if (choice != 0){
			printf("\nInsira ENTER para regressar ao Menu."); //opção fornecida ao utilizador caso pretenda voltar ao menu
			scanf("%*c");
		}
	}
	return g;
}


