//TAD Complexos - Implementação

#include <stdio.h>
#include <stdlib.h>
#include "Complexos.h"

void leComplexo(Complexos *z){
	printf("Parte real:");
	scanf("%f", &z->re);
              //(*z).re
    printf("Parte imaginária:");
    scanf("%f", &z->im);
}

void escreveComplexo(Complexos *z){
	printf("%g", z->re);
	if(z->im>0)
	   printf("+%gi", z->im);
	else 
	   if(z->im<0) printf("%gi", z->im);
}
//Função que faz a soma entre dois números complexos
void somaComplexos(Complexos z1, Complexos z2, Complexos *res){
	(*res).re=z1.re+z2.re;
	(*res).im=z1.im+z2.im;
}
//Função que realiza a subtração entre dois números complexos
void subtraiComplexos(Complexos z1, Complexos z2, Complexos *res){
	(*res).re=z1.re-z2.re;
	(*res).im=z1.im-z2.im;
}
//Função que realiza a multiplicação de dois números complexos
void multiplicaComplexos(Complexos z1, Complexos z2, Complexos *res){
	(*res).re=z1.re*z2.re-z1.im*z2.im;
	(*res).im= z1.re*z2.im+z1.im*z2.re;
}

//Função que realiza a divisão entre dois números complexos
void divideComplexos (Complexos z1, Complexos z2, Complexos *res){
	float d;
	d = (z2.re*z2.re)+(z2.im*z2.im);
    if(d == 0){
      printf(" A divisao nao pode se realizada.\n"); 
      exit(0);//Em caso de d ser igual a 0 o programa termina
    }
    else {
	 
	//Complexos divisao;

	z2.im = -1*z2.im; //calcular o conjugado
	
	multiplicaComplexos (z1, z2, res); //produto
		
	(*res).re = (*res).re / d; //vamos buscar o (*res).re à multiplicação e dividimos por d para ter a parte real da divisão
	(*res).im = (*res).im / d;//vamos buscar o (*res).im à multiplicação e dividimos por d para ter a parte imaginária da divisão
 }
}
 
