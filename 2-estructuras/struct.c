#include <stdio.h>
#include <string.h>

// struct anonimo
typedef struct {
	char nombre[50];
	int edad;
	float altura;
} Persona;

void print_data(Persona *p) {
	printf("Nombre: %s\n", p->nombre);
	printf("Edad: %d\n", p->edad);
	printf("Altura: %f\n", p->altura);
}

int main(void) {
	Persona p1;
	// struct Persona *p = &p1;
	
	strcpy(p1.nombre, "Kevin");
	p1.edad = 25;
	p1.altura = 1.79;
	
	print_data(&p1);
	
	return (0);
}
