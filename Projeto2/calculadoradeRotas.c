#include <stdio.h>
#include "TADGrafo.h"
#include "gestaoGrafo.h"

int main(){
	Grafo g;
    int i,j,str[2][MAXNOS];
    int noPartida,noDestino;
    //informação estritamente necessária para o utilizador
    printf("Ordem das cidades: 0-Porto/1-Aveiro/2-Viseu/3-Guarda/4-Covilha/5-Castelo Branco");
    printf("\n                   6-Coimbra/7-Figueira da Foz/8-Leiria/9-Santarem/10-Lisboa");


    g=manipularGrafo(g);

    for(j=0;j<2;j++){
        for(i=0;i<MAXNOS;i++){
            str[j][i]=INFINITO;}}

    printf("\nQual é o nó de partida e o nó de destino cujo caminho mais curto pretende achar?        ");

    scanf("%d %d",&noPartida, &noDestino);
    caminhosMaisCurtos(g,noPartida,noDestino,str);

    for(i=0;i<g.numNos;i++){
        for(j=0;j<g.numNos;j++){
            printf("%d ",str[i][j]);} printf("\n");}

        printf("O caminho mais curto tem a distancia de %d e e:\n", str[0][0]);

        int aux=str[0][1]-1;

        printf("%s->", g.infoNos[6]);
        for(i=aux; i>2; i--){
            printf("%s->", g.infoNos[str[0][i]]);
        }
        printf("%s\n", g.infoNos[4]);

        printf(" estradas\n");

        printf("(%s", g.matAdj[str[0][aux]][str[0][aux+1]].estrada);
        for(i=aux; i>3; i--){
            printf(",%s", g.matAdj[str[0][i]][str[0][i-1]].estrada);
        }
        printf(",%s)\n", g.matAdj[str[0][3]][str[0][2]].estrada);

        printf("Segundo caminho mais curto: %d e e:\n", str[1][0]);

        aux=str[1][1]-1;

        printf("%s->", g.infoNos[6]);
        for(i=aux; i>2; i--){
            printf("%s->", g.infoNos[str[1][i]]);
        }
        printf("%s\n", g.infoNos[4]);

        printf(" estradas\n");

        printf("(%s", g.matAdj[str[1][aux]][str[1][aux+1]].estrada);
        for(i=aux; i>3; i--){
            printf(",%s", g.matAdj[str[1][i]][str[1][i-1]].estrada);
        }
        printf(",%s)\n", g.matAdj[str[1][3]][str[1][2]].estrada);



	
	
	return 0;
}
