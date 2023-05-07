/*
* Calculadora em notação polaca inversa de complexos
* Operações: adição, subtração, divisão e multiplicação.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pilhaComplexos.h"
#include "Complexos.h"


int main () {
	Pilha p1;
	char aux[10];
	Complexos operando, op1, op2, *res;
	
	res=(Complexos*)malloc(sizeof(Complexos)); //cria espaço de memória para o resultado

	printf ("Introduza uma expressao em notacao polaca inversa: ");
	printf ("\nIntroduza '.' para terminar");
	
	scanf ("%s", aux);
	if (strcmp (aux, ".")==0) { // verifica se a expressão inserida é vazia ou não, se deve ser realizada alguma operação
		printf ("Expressao vazia:");
		return 1;
		}
		else {
			while (strcmp (aux, ".")!=0) {
				//se é um operando
				
			if (strcmp(aux,"+")==0 || strcmp(aux,"*")==0 || strcmp(aux,"-")==0 || strcmp(aux,"/")==0) {
				//retira da pilha os dois operandos
				op2 = top (p1);
				pop(&p1);
				op1 = top(p1);
				pop(&p1);
				//faz o cálculo
			if (strcmp(aux,"+")==0){
			    somaComplexos (op1, op2, res);
			    }
			if (strcmp(aux,"-")==0){
				subtraiComplexos (op1, op2, res);
				}
			if (strcmp(aux,"*")==0){
			    multiplicaComplexos (op1, op2, res);
				}
			if (strcmp(aux,"/")==0){
				divideComplexos (op1, op2, res);
			    }
			//coloca o resultado na pilha
			push(*res, &p1);
			}
			else {
				//é um operando (complexo)
				operando.re = atoi(aux);
					scanf("%s",aux);
					operando.im=atoi(aux);
				//coloca-o na pilha
				push(operando, &p1);
			}
			//lê um novo elemento da expressão
			scanf("%s", aux);
		}
		//Após terminar o ciclo o resultado está no topo da pilha (que aliás só contém esse elemento)
		*res = top(p1);
		printf(" Resultado da expressao : ");
		escreveComplexo(res);
		
		
		return 0;
				
				}
			}
	
