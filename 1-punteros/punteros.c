#include <stdio.h>
#include <stdlib.h>

void change_value(char *letter) {
	*letter = 'b';
}

int main(void) {
	int valor = 10;
	// Acceder al espacio en memoria de valor
	int *puntero = &valor;
	// Acceder al espacio en memoria de puntero
	int **puntero_a_puntero = &puntero;
	
	printf("La direccion de memoria de puntero es: %p\n", puntero);
	printf("La direccion de memoria de puntero_a_puntero es: %p\n", puntero_a_puntero);
	printf("----------------------------------------------------------------------\n");
	
	// VALORES POR REFERENCIA
	char l;
	l = 'a';
	
	change_value(&l);
	printf("Valor de l: %c\n", l);
	printf("----------------------------------------------------------------------\n");
	
	// VALORES POR REFERENCIA CON MEMORIA DINAMICA
	char *l2 = malloc(sizeof(char));

	if(l2 == NULL){
		fprintf(stderr, "Error: Could not allocate memory\n");
		return (1);
	}
	
	*l2 = 'a';
	change_value(l2);
	printf("Valor de l2: %c\n", *l2);
	free(l2);
	printf("----------------------------------------------------------------------\n");
	
	// STRINGS
	// Primera forma
	char str[] = "Hello world!";
	char *ptr = str;
	
	printf("Primera Forma\n");
	printf("Caracteres de la cadena: ");
	while(*ptr != '\0') {
		printf("%c", *ptr);
		ptr++;
	}
	printf("\n\n");

	// Segunda forma
	char str2[] = "Hello world 2!";
	char *ptr2 = str2;
	
	printf("Segunda Forma\n");
	printf("Caracteres de la cadena: ");
	int i = 0;
	
	while(ptr2[i] != '\0') {
		printf("%c", ptr2[i]);
		i++;
	}
	printf("\n");
	
	return (0);
}
