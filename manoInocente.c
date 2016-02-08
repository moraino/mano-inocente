#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

#define LONG_MAX_CADENA_ENTRADA 255

typedef enum { FALSE, TRUE } bool;

int num_max = 0;
char cadena_inelegibles[LONG_MAX_CADENA_ENTRADA];
int numero = 0;
int inelegibles[LONG_MAX_CADENA_ENTRADA];
int tamanho_inelegibles = 0;

// Función de comparación de enteros para la función de búsqueda en el array de inelegibles
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void muestra_menu() {
	printf("Elija el número máximo: ");
	scanf("%d", &num_max);
	printf("Introduzca los números inelegibles separados por comas \",\": ");
	scanf("%s", &cadena_inelegibles);
}

void crea_array_inelegibles() {
	char * token; //palabra extraída de la cadena de inelegibles
	int i = 0;
	char * puntero; //puntero al inicio de la siguiente palabra de la cadena de inelegibles
	char * puntero_strtol; //puntero necesario para usar la función strtol

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

	aleatorio = rand() % num_max + 1;
	encontrado = lfind(&aleatorio, inelegibles, &tamanho_inelegibles, sizeof(int), cmpfunc);
	while (encontrado != NULL) {
		printf("\nResultado inelegible: %d", *encontrado);
		aleatorio = rand() % num_max + 1;
		encontrado = lfind(&aleatorio, inelegibles, &tamanho_inelegibles, sizeof(int), cmpfunc);
	}

	return aleatorio;
}

int main (int argc, char** argv) {
	int i = 0;
	char seguimos;

	// Generamos la semilla
	srand(time(NULL));

	muestra_menu();
	printf ("Número máximo: %d", num_max);
	
	crea_array_inelegibles();

	printf ("\nNúmeros inelegibles:");
	for (i = 0; i < tamanho_inelegibles; i++) {
		printf(" %d", inelegibles[i]);
	}

	do {
		numero = genera_num_aleatorio();
		printf ("\nEl elegido es: %d", numero);
		printf ("\n¿Desea volver a elegir otro número? (S/N) ");
		scanf("%s", &seguimos);
	} while (seguimos == 's' || seguimos == 'S' || seguimos == 'y' || seguimos == 'Y');

	return 0;
}