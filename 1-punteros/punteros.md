# Punteros

**Puntero**: Variable que apunta a una dirección de memoria.

Al ser direcciones de memoria, podemos decirle a un puntero
que a ese lugar que esta apuntando almacene un valor.

| Dirección de memoria | Variable | Valor |
|----------------------|----------|-------|
| 0x123456781          | num1     | 1     |
| 0x123456782          | text     | "dos" |
| 0x123456783          | bol1     | true  |

## Ventajas de trabajar con punteros

- **Manipulación de memoria dinámica**: A través de funciones como `malloc()`, `calloc()`, `realloc()` o `free()`.
- **Pasar datos por referencia a funciones**: Nos permite modificar el
valor de una variable en su ubicación original de la memoria.
- **Eficiencia**: Al poder trabajar directamente con la memoria, podemos
evitar capas innecesarias de datos y permitir el acceso directo a los
valores en memoria.
- **Manipulación de estructuras de datos complejas**: Como listas enlazadas, árboles y grafos.

## Declaración de un puntero en C

```c
int *puntero;
```

### Operadores básicos

- __carácter *__: Accede al valor de la variable a la que estamos apuntando.
- __carácter &__: Obtiene la dirección de memoria de la variable a la que se está apuntando.

## Ejemplos

**Puntero y puntero que apunta a otro puntero**:

```c
int valor = 10;
// Acceder al espacio en memoria de valor
int *puntero = &valor;
// Acceder al espacio en memoria de puntero
int **puntero_a_puntero = &puntero;

printf("La direccion de memoria de puntero es: %p\n", puntero);
```

**Importancia de pasar el valor por referencia a una función**:

Definimos la siguiente función:

```c
void change_value(char letter) {
	letter = 'b';
}
```
Función `main()`:

```c
char l;
l = 'a';

change_value(l);
printf("Valor de l: %c\n", l);
```

Esto devolverá `a`, ya que cuando pasamos un argumento de una
variable normal, crea una copia (otro espacio en memoria), no lo
estamos cambiando en el espacio en memoria que sería la variable
original (en este caso `l`).

Para esto, debemos modificar `change_value()`, en lugar de pasarle una variable normal como argumento, vamos a pasarle un puntero:

```c
void change_value(char *letter) {
	*letter = 'b';
}
```

Y en el `main()`, para poder acceder al valor del puntero de `change_value()`:

```c
// Acceder al espacio en memoria de l
change_value(&l);
```

Ahora ya no estamos creando una copia u espacio en memoria, sino
que está modificando directamente el espacio en memoria en el que
se encuentra `l`.

Y esto devolverá `b`.

**Pasar datos por referencia con manipulación de memoria dinámica**:

Creamos un puntero y reservamos la memoria correspondiente con `malloc()` (**memory allocator**):

```c
// malloc(1) porque es lo que ocupa un caracter -> 1 byte
char *l2 = malloc(1)
```

Otra manera de hacer esto:

```c
// malloc(1) = malloc(sizeof(char))
char *l2 = malloc(sizeof(char))
```

Para usar `malloc()` y `free()`, debemos importar la librería correspondiente:

```c
#include <stdlib.h>
```

Aunque ya tenemos nuestra memoria asignada, debemos controlar errores
como evitar salirnos de la memoria para evitar comportamientos no
deseados. Entonces, si usamos `malloc()`, debemos validar errores:

```c
// Evaluar si nos hemos salido de la cantidad de memoria asignada
// l2 == NULL, significa verificar si l2 se ha salida de la cantidad asignada
if(l2 == NULL){
	fprintf(stderr, "Error: Could not allocate memory\n");
    // Detenemos la ejecucion del programa
	return (1);
}
```

Le asignamos un valor al puntero, llamamos a `change_value()` y pasamos `l2`:

```c
*l2 = 'a';
// Al ser un puntero, directamente pasamos el espacio en memoria, no necesitamos &l2
change_value(l2);
printf("Valor de l2: %c\n", *l2);
```

Ahora, lo único que queda es liberar memoria, con `malloc()` asignamos
un espacio en memoria y lo liberamos con `free()`:

```c
// Liberar memoria
// No necesitamos especificar puntero de l2, ya que lo definimos como puntero
free(l2);
```

Y si ejecutamos el programa, esto devolverá `b`.

**Puntero para trabajar con string**:

Definir un string y un puntero:

```c
// Al final de una cadena, C agrega '\0'
char str[] = "Hello world!";
// *ptr apunta al primer caracter de str[]
char *ptr = str;
```

Ahora imprimiremos los caracteres de la cadena:

```c
printf("Caracteres de la cadena: ");
while(*ptr != '\0') {
	printf("%c", *ptr);
	ptr++;
}
printf("\n\n");
```

Esto devolverá `Caracteres de la cadena: Hello world!`.

Otra manera de hacerlo, sería con un contador:

```c
// Con las cadenas no es necesario usar malloc ni free, se asigna automaticamente
char str[] = "Hello world!";
char *ptr = str;

printf("Caracteres de la cadena: ");
int i;
i = 0;

while(ptr[i] != '\0') {
	printf("%c", ptr[i]);
	i++;
}
printf("\n");
```

En este caso, no tenemos que utilizar ni `malloc()` ni `free()`, porque
no estamos reservando memoria de un puntero, sino que hemos creado un
puntero que apunta hacia una cadena de caracteres.

Y al crear la cadena de caracteres, la memoria se asigna automáticamente.