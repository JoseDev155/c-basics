# Estructuras

Se representan con la palabra clave `struct` y son una forma de
agrupar diferentes tipos de datos relacionados entre sí, bajo un
solo nombre.

Las **estructuras** serían equivalentes a las **clases**. El propósito
en ambos casos es organizar y manipular datos.

`typedef` nos permite crear alías para un tipo de dato concreto y es
interesante utilizarlo con estructuras para mejorar su uso y legibilidad.

## Ejemplos

Importamos las siguientes librerías:

```c
// Nos permite imprimir por consola
#include <stdio.h>
/*
Para utilizar la funcion strcpy() para definir las propiedades
de nuestro struct
*/
#include <string.h>
```

Creamos el `struct`:

```c
struct Persona
{
    // Propiedades
    char nombre[50];
    int edad;
    float altura;
};
```

Por convenio el nombre de los struct debe ser en mayusculas.
Todas las propiedades van entre llaves y es muy importante poner un
`;` al final.

Para invocar el `struct`:

```c
struct Persona p1;
```

Para darle valor a cada una de las propiedades:

```c
strcpy(p1.nombre, "Juan");
p1.edad = 30;
p1.altura = 1.75;
```

Para el nombre, al ser un **string** no podemos darle el valor
directamente, eso nos dará un error al compilar. Para eso usaremos la
función `strcpy()`.

`strcpy()` nos copia un **string** del parámetro2 al parámetro1. `strcpy()` solo
sirve para **strings**.

Ahora, imprimimos las propiedades por pantalla:

```c
printf("Nombre: %s\n", p1.nombre);
printf("Edad: %d\n", p1.edad);
printf("Altura: %f\n", p1.altura);
```

Ahora, esto tiene un problema, ya que es ineficiente. Porque cada vez que
utilizamos un `struct`, estamos creando un copia de cada uno de los
datos. Es mucho más eficiente utilizar punteros.

También, crearemos otra función:

```c
void print_data(struct Persona *p) 
{
	printf("Nombre: %s\n", (*p).nombre);
	printf("Edad: %d\n", (*p).edad);
	printf("Altura: %f\n", (*p).altura);
}
```

Para pasar un struct como argumento de una funcion, hay varias maneras
de hacerlo.

### Primera forma

```c
struct Persona p1;
struct Persona *p = &p1;
```

Para acceder a los datos de un puntero, haríamos:

```c
strcpy((*p).nombre, "Kevin");
(*p).edad = 25;
(*p).altura = 1.79;

print_data(p);
```

### Segunda forma

Función `main()`:

```c
strcpy(p->nombre, "Kevin");
p->edad = 25;
p->altura = 1.79;

print_data(p);
```

Función `print_data()`:

```c
void print_data(struct Persona *p)
{
	printf("Nombre: %s\n", p->nombre);
	printf("Edad: %d\n", p->edad);
	printf("Altura: %f\n", p->altura);
}
```

### Tercera forma

Función `main()`:

```c
struct Persona p1;

strcpy(p1.nombre, "Juan");
p1.edad = 30;
p1.altura = 1.75;

print_data(&p1);
```

En la función `print_data()` no modificaremos nsda, ya que al pasar `&p1`
estamos apuntando a la dirección de memoria de la variable `p1`.

### typedef

Para no acceder a nuestro tipo de dato `Persona` usando la palabra
reservada `struct`, usaremos `typedef`:

```c
typedef struct Persona
{
	char nombre[50];
	int edad;
	float altura;
} Persona;
```

Ahora usaremos `Persona`, que es el alías que hemos creado:

```c
Persona p1;

strcpy(p1.nombre, "Juan");
p1.edad = 30;
p1.altura = 1.75;

print_data(&p1);
```

También, ya que hemos creado el alías, podriamos dejar el nombre anónimo,
ya que a lo que estamos llamando en el `main()` es al alías:

```c
// struct anonimo
typedef struct
{
	char nombre[50];
	int edad;
	float altura;
} Persona;
```