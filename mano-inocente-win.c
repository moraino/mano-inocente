#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include "strtok_r.h"

#define LONG_MAX_CADENA_ENTRADA 255

int num_max = 0;
char cadena_inelegibles[LONG_MAX_CADENA_ENTRADA];
int numero = 0;
int inelegibles[LONG_MAX_CADENA_ENTRADA];
int tamanho_inelegibles = 0;

// Funci�n de comparaci�n de enteros para la funci�n de b�squeda en el array de inelegibles
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void muestra_menu() {
	do {
		printf("Select the maximum number (less than 256): ");
		scanf("%d", &num_max);
	} while (num_max < 1 || num_max > LONG_MAX_CADENA_ENTRADA);
	printf("Write the non-elegible numbers separated by comma \",\": ");
	scanf("%s", &cadena_inelegibles);
}

void crea_array_inelegibles() {
	char * token; //palabra extra�da de la cadena de inelegibles
	int i = 0;
	char * puntero; //puntero al inicio de la siguiente palabra de la cadena de inelegibles
	char * puntero_strtol; //puntero necesario para usar la funci�n strtol

	token = strtok_r(cadena_inelegibles, ",", &puntero);
	while (token != NULL) { 
		inelegibles[i] = strtol(token, &puntero_strtol, 10);
		i++;
		token = strtok_r(NULL, ",", &puntero);
	}
	tamanho_inelegibles = i;
}

int genera_num_aleatorio() {
	int aleatorio = 0;
	int * encontrado;

	do {
		aleatorio = rand() % num_max + 1;
		encontrado = lfind(&aleatorio, inelegibles, &tamanho_inelegibles, sizeof(int), cmpfunc);
	} while (encontrado != NULL);
	inelegibles[tamanho_inelegibles] = aleatorio;
	tamanho_inelegibles++;

	return aleatorio;
}

int main (int argc, char** argv) {
	int i = 0;
	char seguimos;

	// Generamos la semilla
	srand(time(NULL));

	muestra_menu();
	
	crea_array_inelegibles();

	do {
		numero = genera_num_aleatorio();
		printf ("\nThe chosen number is: %d", numero);
		printf ("\nWould you like to choose another number? (Y/N) ");
		scanf("%s", &seguimos);
	} while ((seguimos == 's' 
				|| seguimos == 'S' 
				|| seguimos == 'y' 
				|| seguimos == 'Y') 
				&& tamanho_inelegibles < num_max);
	if (tamanho_inelegibles == num_max) {
		printf ("Sorry, but there are no more numbers.\n");
	}

	return 0;
}