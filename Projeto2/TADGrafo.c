#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TADGrafo.h"

#define INFINITO 9999

//Função que cria um grafo
Grafo criaGrafo (){ //Temos de pôr tudo a zero
	int i,j;
	Grafo g;
	g.numNos = 0;
	for (i=0;i<MAXNOS;i++){
		for (j=0;j<MAXNOS;j++){
	g.matAdj[i][j].dist= 0;
	strcpy (g.matAdj[i][j].estrada,"0"); 
    }
       }
	return g;
};

//Função para inserir um novo nó no grafo
void inserirNo (Grafo *g, char cidade[20]) {
	int a;
        strcpy(g->infoNos[g->numNos], cidade);
        for(a=0; a <= g->numNos; a++){
           g->matAdj[g->numNos][a].dist = 0;
           strcpy(g->matAdj[g->numNos][a].estrada,"0");//colocar a linha correspondente ao novo nó a zeros
           g->matAdj[a][g->numNos].dist = 0;
           strcpy(g->matAdj[a][g->numNos].estrada,"0");//colocar a coluna correspondente ao novo nó a zeros
         }
        g->numNos++;
        
};
		
//Função para retirar um nó do grafo		
void retirarNo(Grafo *g,int n){
	int i;
	
	// remover o nó
        while (n < g->numNos) { //a coluna e linha associada ao nó é eliminada fazendo recuar uma posição todas as colunas e linhas que se seguem
            
             // mover os elementos da linha para uma posição acima
             for (i = 0; i < g->numNos; i++){
                g->matAdj[n][i].dist = g->matAdj[n+1][i].dist;
                strcpy(g->matAdj[n][i].estrada, g->matAdj[n+1][i].estrada);
                  } 
            
            
            
            // mover os elementos da coluna uma posição para a esquerda
            for (i = 0; i < g->numNos; i++) {
                g->matAdj[i][n].dist = g->matAdj[i][n + 1].dist;
                strcpy(g->matAdj[i][n].estrada, g->matAdj[i][n + 1].estrada);
                      }
 
          
             for(i=n; i< g->numNos; i++ ){
				  strcpy(g->infoNos[i], g->infoNos[i+1]); 
		    }
            n++;
        }
        g->numNos--; //diminuir o número de nós
};

//Função que permite editar a informação de um nó, neste caso o nome da cidade
void editarInfoNo(Grafo *g, int n, char novo[]){
	strcpy(g->infoNos[n],novo);//no nó altera o nome de uma cidade para o novo nome
};

//Função para inserir um novo arco no grafo
void inserirArco (Grafo *g, int noPartida, int noDestino, int km, char road[20]){
	g->matAdj[noPartida][noDestino].dist = km; //iguala a informação respetiva à dist à nova quilometragem km
	strcpy(g->matAdj[noPartida][noDestino].estrada,road); //altera a estrada para a nova road	
};
	
//Função para retirar um arco de um grafo
void retirarArco(Grafo *g, int noPartida, int noDestino){
	g->matAdj[noPartida][noDestino].dist = 0;//zera a quilometragem, km
	strcpy(g->matAdj[noDestino][noPartida].estrada,"0");//apaga a via usada, road	
};

//Função que permite editar a informação de um arco, neste caso a distância e a estrada usada
void editarInfoArco(Grafo *g, int noPartida, int noDestino, int distancia, char rodovia [20]){
	//editar a dist
	g->matAdj[noPartida][noDestino].dist = distancia;
	g->matAdj[noDestino][noPartida].dist = distancia;
	//editar a informação da estrada
	strcpy(g->matAdj[noDestino][noPartida].estrada, rodovia);	
	strcpy(g->matAdj[noPartida][noDestino].estrada, rodovia);
};


//Função que fornece o caminho mais curto(com menos distância a percorrer) entre uma cidade/nó e outra cidade/nó 
void caminhoMaisCurto(Grafo g, int noPartida, int noDestino,int str[MAXNOS]){
    int i,dist, custo[g.numNos], ant[g.numNos],atual=noPartida,aux;
    int v[g.numNos];


        for(i=0;i<g.numNos;i++){
        custo[i]=INFINITO;
        ant[i]=g.numNos;
        v[i]=0;}

    custo[noPartida]=0;
    custo[g.numNos]=INFINITO;

    while((atual!=noPartida)&&(atual!=g.numNos)) {
        for(i=0; i<g.numNos; i++){
            if((g.matAdj[atual][i].dist!=0)&&(v[i]==0)){
            dist=g.matAdj[atual][i].dist+custo[atual];

            if(dist<custo[i]){
                custo[i]=dist;
                ant[i]=atual;}}}
                v[atual]=1;

        atual=g.numNos;
        for(i=0; i<g.numNos; i++){
            if(v[i]==0){//verificamos se o nó ainda não foi visitado
            if(custo[i]<custo[atual]){//verificamos se o temos um caminho mais curto
                atual=i;}

            }}
        };

        if(str[0]>custo[noDestino]){
        str[0]=custo[noDestino];
        atual=noDestino;
        aux=1;
        while(atual!=noPartida){
            aux++;
            str[aux]=atual;
            atual=ant[atual];
            }
            aux++;
        str[1]=aux;

        str[aux]=noPartida;}
}

void caminhosMaisCurtos(Grafo g, int noPartida, int noDestino, int str[2][MAXNOS]){
    int i;
    Arco aux;
        caminhoMaisCurto(g,noPartida,noDestino, str[0]);
        for(i=2;i<str[0][1];i++){
        aux=g.matAdj[str[0][i]][str[0][i+1]];
        retirarArco(&g,str[0][i],str[0][i+1]);
        caminhoMaisCurto(g,noPartida,noDestino, str[1]);
        inserirArco(&g,str[0][i],str[0][i+1],aux.dist,aux.estrada);
    }
}
