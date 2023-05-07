#include "pilhaComplexos.h"
#include "Complexos.h"
#include <stdlib.h>
#include <stdio.h>

#define PILHAVAZIA 1

/*
 * Função auxiliar
 * Cria a memória necessária para o nó
 */

Pilha afetapilha (void){
	return (Pilha) malloc (sizeof (NoPilha));
	}
	
/*
 * Cria a pilha vazia (ponteiro NULL)
 */
 
void criaPilha (Pilha* p){
	(*p)=NULL;
	}

/*
 * Dado um elemnto e uma pilha, coloca o elemento no topo da pilha
 */
 
void push ( Complexos elem, Pilha* p){
	Pilha novo;
	
    novo = (Pilha)malloc( sizeof(NoPilha)); //damos o espaço para a variável novo tipo pilha  e iniciamos 
	novo -> elems = elem;
	novo -> prox = (*p);
	(*p) = novo;
 }

/*
 * retira um elemento do topo da pilha (não vazia)
 */

void pop(Pilha* p){
	Pilha aux;
	aux = (*p);
	(*p) = (*p)->prox; 
	free(aux);
	}
	
/*
 * Devolve o elemento no topo da pilha (não vazia)
 * Dado se tratar de uma pilha de complexos não é possível definir um
 * código de erro
 *  
 * Esta função não deve ser usada com pilhas vazias
 */

Complexos top (Pilha p){
	return (p->elems);
	}
	
//Verifica se uma pilha está vazia(ou não)
int pilhaVazia (Pilha p){
	return (p==NULL);
}

