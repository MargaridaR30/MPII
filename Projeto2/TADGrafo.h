/**********************************************************/
/* ESPECIFICAÇÃO - TAD GRAFOS (com matriz de adjacências)*/
/********************************************************/


#if !defined GRAFO
#define GRAFO

#define MAXNOS 100

#define INFINITO 9999

typedef struct arco{
	int dist;
	char estrada[20];
}Arco;

//grafo como matriz de adjacencia
typedef struct grafo{
	char infoNos[40][30];
	Arco matAdj[MAXNOS][MAXNOS];
	int numNos;
}Grafo;

/*
 * cria grafo
 * ->
 * <- grafo vazio
 */
Grafo criaGrafo();

/*
 * Insere um novo nó ( sem ligações)
 * ->grafo
 * <- grafo (grafo com mais um nó, sem arcos)
 */
void inserirNo(Grafo *, char []);

/*
 * retira um nó e todas as suas ligações
 * assume-se que se retira o último nó
 * -> grafo
 *<- grafo (sem o último nó, retirando os arcos respetivos)
 */
void retirarNo(Grafo *,int);

/*
 *dado um nó que corresponde a uma cidade, altera o nome da cidade 
 */
void editarInfoNo(Grafo *, int, char []);

/*
 * Insere um arco entre dois nós
 * ->grafo, noPartida, noDestino, arco
 * <- grafo + arco entre nós partida e destino
 */
void inserirArco(Grafo *, int, int, int, char []);

/*
 * retira um arco entre dois nós
 * ->grafo, noPartida, noDestino
 * <- grafo - arco entre nós partida e destino
 */
void retirarArco(Grafo*, int, int);


/*
 * ->grafo, noPartida, noDestino
 * dado um arco altera a informação desse arco, neste caso os kms e a estrada
 */
void editarInfoArco(Grafo *, int, int, int, char []);


void caminhoMaisCurto(Grafo , int ,int, int str[MAXNOS]);
/*
 * ->grafo, noPartida, noDestino, vetor onde guardamos os dados
 * Dado um nó de partida e um nó de destino vai calcular 
 * o caminho cuja distância é menor
 */
void caminhosMaisCurtos(Grafo , int , int , int str[2][MAXNOS]);
#endif
