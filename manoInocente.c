#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define LONG_MAX_CADENA_ENTRADA 255

int num_max = 0;
char cadena_inelegibles[LONG_MAX_CADENA_ENTRADA];
int numero = 0;
int inelegibles[LONG_MAX_CADENA_ENTRADA];

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

	token = strtok_r(cadena_inelegibles, ",", &puntero);
	while (token != NULL) {
		//inelegibles[i] = scanf("%d", &token);
		printf ("\n%d", strtol(token);
		token = strtok_r(NULL, ",", &puntero);
		i++;
	}
}

void genera_num_aleatorio() {
	numero = rand() % (num_max + 1);
}

int main (int argc, char** argv) {
	// Generamos la semilla
	srand(time(NULL));

	muestra_menu();
	printf ("Número máximo: %d", num_max);
	printf ("\nNúmeros inelegibles: %s", cadena_inelegibles);
	crea_array_inelegibles();
	genera_num_aleatorio();
	printf ("\nEl elegido es: %d", numero);
	printf ("\n");

	return 0;
}