#include "Complexos.h"

#if !defined PILHAS
#define PILHAS

// Definição de nó

typedef struct noPilha {
  Complexos elems;
  struct noPilha* prox;
} NoPilha;

// Uma pilha é um ponteiro para nó
typedef NoPilha* Pilha;

// Cria a pilha vazia
void criaPilha (Pilha*);

// Dado um elemento e uma pilha, insere o eemento no topo da pilha
void push (Complexos, Pilha*);

// Devolve o elemento no topo da pilha
Complexos top (Pilha);

// Retira o elemento do topo da pilha (não vazia)
void pop (Pilha*);

// Verifica se uma pilha está (ou não) vazia
int pilhaVazia (Pilha); 

#endif
