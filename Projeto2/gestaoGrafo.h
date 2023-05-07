/*********************************/
/* ESPECIFICAÇÃO - gestaoGrafo.h*/
/*******************************/
//Faz a gest˜ao do grafo:utilizando o T.A.D. Grafo, um interface minimal,
// lê/escreve do ficheiro e faz a manipulaç˜ao do grafo

#if !defined GESTAOGRAFO
#define GESTAOGRAFO

#include "TADGrafo.h"

//Função que dado um ficheiro mapa.dados que contém a matriz de adjacência 
//referente ao grafo vai fazer a leitura dessa mesma matriz
void lerMatriz(Grafo *);

//Função que permite manipular/alterar o grafo utilizando as funções do
// "TADGrafo.h" de forma mais eficiente e compacta
Grafo manipularGrafo();

//Função que permite alojar as novas alterações no ficheiro mapa.dados
void escreverFicheiro(Grafo *);




//Função que escreve a Matriz: usada apenas durante a criação do programa
// para verificar o funcionamento do mesmo
//void escreverMatriz(Grafo *); 

#endif
