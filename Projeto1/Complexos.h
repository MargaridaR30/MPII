 #if !defined COMPLEXO
#define COMPLEXO

//Estrutura COMPLEXO
typedef struct Complexo{
	float re, im;
}Complexos;

Complexos constroiComplexo(float , float);
/*Constroi complexo - dados dois reais constroi um complexo => r,i. r a parte real e i a parte imaginaria
 * <= c=r+i
*/

/**Funções adicionais**/

Complexos lerComplexo(); 
/*lerComplexos, lê o complexo
 * Não entra nada, faz a leitura de dois reais e sai um complexo
*/
void escreveComplexo (Complexos *);

/**OPERAÇÕES INTERNAS**/


void somaComplexos (Complexos, Complexos, Complexos*);
/*Soma, dados dois complexos, calcular a sua soma
 * --> cc1, c2: Complexo
 * <-- c3=c1+c2
 */

void subtraiComplexos (Complexos, Complexos, Complexos*);
/*subtrairComplexo, dados dois complexos, faz a sua subtração
 * --> c1, c2: Complexo
 * <-- c3=c1-c2
 */
 
void multiplicaComplexos (Complexos, Complexos, Complexos*);
/*multiplicarComplexo, dados dois complexos, multiplica-os
 * --> c1, c2: Complexo
 * <-- c3=c1*c2
 */
 
void divideComplexos (Complexos, Complexos, Complexos*);
/*dividirComplexo, dados dois complecos, divide-os
 * --> cf1, c2: Complexo
 * <-- c3=c1/c2
 */
 
#endif

