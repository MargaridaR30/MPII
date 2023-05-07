CC     = gcc
OPC    = -Wall -lm

.PHONY: clean all

all: calculadoradeRotas 


clean:
	-rm *.o calculadoradeRotas

calculadoradeRotas: TADGrafo.o gestaoGrafo.o calculadoradeRotas.c 
	${CC} -o $@ $@.c TADGrafo.o gestaoGrafo.o ${OPC}

