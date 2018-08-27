#include "tp0.h"
#include <stdbool.h>

// CONSTANTES
const int MAYOR= 1;
const int MENOR= -1;
const int IGUAL= 0;

/* ******************************************************************
 *                     FUNCIONES AUXILIARES
 * *****************************************************************/

bool verificacion_de_topes(int tope_1, int tope_2) {
	return (tope_1 > 0 && tope_2 > 0);
}

/* ******************************************************************
 *                     FUNCIONES A COMPLETAR
 * *****************************************************************/

/* swap() intercambia dos valores enteros.
 */
void swap (int* x, int* y) {
	int aux= *x;
	*x= *y;
	*y= aux;
}

/* maximo() busca el mayor elemento del arreglo y devuelve su posicion.
 * Si el vector es de largo 0, devuelve -1.
 */
int maximo(int vector[], int n) {
	
	int mayor= 0;
	
	if(n > 0) {
		for(int i= 0; i < n; i++) {
			if(vector[i] > vector[mayor]) {
				mayor= i;
			}
		}
		return mayor;
	}
	
	return -1;
}

/* La función comparar recibe dos vectores y sus respectivas longitudes
 * y devuelve -1 si el primer vector es menor que el segundo; 0 si son
 * iguales; y 1 si el segundo es menor.
 *
 * Un vector es menor a otro cuando al compararlos elemento a elemento,
 * el primer elemento en el que difieren no existe o es menor.
 */
int comparar(int vector1[], int n1, int vector2[], int n2) {
	
	if(verificacion_de_topes(n1, n2)) {
		for(int i= 0; i < n1 && i < n2; i++) {
			if(vector1[i] >  vector2[i]) {
				return MAYOR;
			}else if(vector1[i] < vector2[i]) {
				return MENOR;
			}
		}
	}
	//Si alguno de los vectores no termino de recorrer
	if(n1 > n2) {
		return MAYOR;
	}else if( n1 < n2) {
		return MENOR;
	}
	return IGUAL;
}

/* selection_sort() ordena el arreglo recibido mediante el algoritmo de
 * selección.
 */
void seleccion(int vector[], int n) {
	
	for(int i= n; i > 0; i--) {
		int mayor= maximo(vector, i);
		swap(&vector[i-1], &vector[mayor]);
	}
}
