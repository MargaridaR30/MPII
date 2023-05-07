#Makefile para o projeto 1 - Calculadora de complexos em notação polaca inversa

CC	= gcc
OPC	= -Wall

.PHONY: clean all

all: calculadoraComplexos

clean:
	-rm *.o calculadoraComplexos
	
calculadoraComplexos: pilhaComplexos.o Complexos.o calculadoraComplexos.c
		${CC} -o $@ $@.c pilhaComplexos.o Complexos.o ${OPC}
