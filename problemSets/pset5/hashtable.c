// Programa de prueba de hash tables con numeros

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <cs50.h>

const int DEC = 11, COD = 5;

typedef struct node
{
    char num;
    struct node *next[DEC];
}
cifra;

uint8_t ind(char c);
cifra *newnode(char *s, uint8_t pos);
void place(cifra **table, char *s, uint8_t pos);
void see(cifra *table);
void release(cifra *table);
bool correct(cifra *table, char *s, uint8_t pos);

int main(void)
{
    // El mero inicio del array de listas de arrays
    cifra *table[DEC];

    for (uint8_t i = 0; i < DEC; i++)
    {
        table[i] = NULL;
    }

    char *code[DEC];

    for (uint8_t i = 0; i < DEC; i++)
    {
        code[i] = get_string("Type in number %i: ", i + 1);
    }
    printf("\n");

    // Acomodarlos en un hash table
    for (uint8_t m = 0; m < DEC; m++)
    {
        place(&table[ind(code[m][0])], code[m], 0);
    }

    // Mostrar
    for (uint8_t i = 0; i < DEC; i++)
    {
        see(table[i]);
        printf("\n");
    }

    char *w = malloc(sizeof(char) * 24);

    // Checar si el numero introducido por el usuario es correcto
    do
    {
        printf("Type in one of the former numbers: ");
        scanf("%s", w);
        w[strlen(w)] = '\0';
    }
    while (!correct(table[ind(w[0])], w, 0));

    printf("Entry correct.\nGoodbye.\n");

    // Liberar espacio mallocado
    for (uint8_t i = 0; i < DEC; i++)
    {
        release(table[i]);
    }

    free(w);

    return 0;
}

/*  1. Para la primera letra, checar si hay alguna lista que empiece con
    esa letra, es decir, cuyo indice ya este ocupado.
    2. En caso de que este ocupado, ir a esa lista y checar si la segunda letra
    ya existe en esa rama, y hacer eso hasta que se llegue a una letra diferente
    o termine la palabra.
    3. En caso de que este desocupado, empezar una nueva lista
*/

// Funcion que encuentra el lugar del hash table dobde debe ser colocado newnode

uint8_t ind(char c)
{
    switch (c)
    {
        // Si es el caracter null
        case '\0':
            return 10;

        default:
            return (uint8_t)c - 48;
    }
}

// Acomodar un nuevo nodo
cifra *newnode(char *s, uint8_t pos)
{
    // Caso base 1: ya llego al limite de longitud
    if (pos > (uint8_t)strlen(s)) // Checar si no esta conflictuada con la de abajo
    {
        return NULL;
    }

    // Asignar memoria para el nuevo nodo
    cifra *nuevo = malloc(sizeof(cifra));
    if (nuevo == NULL)
    {
        return NULL;
    }

    // Asignar el valor de num de ese nodo
    nuevo -> num = s[pos];

    for (uint8_t i = 0; i < DEC; i++)
    {
        nuevo -> next[i] = NULL;
    }

    // Caso recursivo: alamcenar en el next correspondiente la informacion del siguiente nodo
    if (s[pos] != '\0' && pos < (uint8_t)strlen(s))
    {
        nuevo -> next[ind(s[pos + 1])] = newnode(s, pos + 1);
    }

    return nuevo;
}


// Encontrar posicion para nuevo
void place(cifra **table, char *s, uint8_t pos) // checar si no es con doble *
{
    // Si no hay nada, hay que asignar memoria para uno nuevo
    if (*table == NULL)
    {
        *table = newnode(s, pos);
        return;
    }

    // Si se llega al final del string
    if (s[pos] == '\0' || pos > (uint8_t)strlen(s))
    {
        return;
    }

    cifra *tmp = *table;

    // Pasar al siguiente nodo
    place(&tmp -> next[ind(s[pos + 1])], s, pos + 1);
}

// Si no acepta el tipo de dato "array of ptrs", probar con cada lista del array
void see(cifra *table)
{
    // Caso base: no hay nada en table
    if (table == NULL)
    {
        return;
    }

    printf("%c ", table -> num); // Checar si esto debe ir aqui o antes de la recursion

    // Buscar cuales de los punteros apuntan a algo y ver a donde nos llevan
    for (uint8_t i = 0; i < DEC; i++)
    {
        see(table -> next[i]);
    }

    printf(" ");
}

void release(cifra *table)
{
    // Caso base: no hay nada en table
    if (table == NULL)
    {
        return;
    }

    // Buscar cuales de los punteros apuntan a algo y ver a donde nos llevan
    for (uint8_t i = 0; i < DEC; i++)
    {
        release(table -> next[i]);
    }
    free(table);
}

// Probar si la contrasena que introduce el usuario es correta
bool correct(cifra *table, char *s, uint8_t pos)
{
    if (table == NULL)
    {
        return false;
    }

    bool b = false;

    if (pos > (uint8_t)strlen(s) || s[pos] != table -> num)
    {
        return false;
    }

    if (s[pos] == '\0' && table -> num == '\0')
    {
        return true;
    }

    if (s[pos] != '\0' && pos < (uint8_t)strlen(s))
    {
        b = correct(table -> next[ind(s[pos + 1])], s, pos + 1);
    }

    return b;
}

/* Hay 2 posibles formas este problema:
    1. La forma rapida que consume mas memoria:
        * Todos los nodos van a generar y asignar automaticamente un nodo
          por cada pointer del array next.
        * La tabla misma empieza por un array de nodos, en vez de un array de
          punteros.
        * Cada nuevo nodo -> next va a tener 3 valores asignados al momento
          de generarse:
          - datos (indice)
          - bool existe = false
          - array de punteros next = NULL
        * Para lo que sirve iniciar el indice de los next es para poder saber
          de forma mas organica a que apunta cada puntero del array con una
          busqueda simple
        * El bool sirve para saber de forma inmediata si detras de ese nodo
          hay una lista (o mas nodos).
        * Para navegar en la tabla lo unico que se tiene que hacer es checar
          si el nodo apuntado tiene en true el bool existe, y de esa forma se
          sabra que direccioin tomar, es decir, por que puntero del array seguir.
        * Para saber de forma rapida que apunta cada puntero del array next, se
          puede buscar (por iteracion) por su indice.
        * Cada nodo va a ser creado desde la configuracion de su antecesor, de tal
          manera que lo que debe hacer es tomar ese puntero ya existente y
          configurarlo.
        * Como el puntero ya esta generado, la funcion que lo crea mas bien
          deberia tomarlo como referencia, asi que el tipo que devuelve no
          seria node*.
        * La ventaja que tiene es que presuntamente es el que tendria manejo mas
          sencillo y rapido al momento de buscar, y en caso de tener muchos
          elementos almacenados en la tabla, el espacio se ahorraria considera-
          blemente (segun mis calculos, una constante [O(1)] en memoria y tiempo).
        * La desventaja es que cada nuevo nodo consume la misma cantidad de
          espacio que cada elemento del array de punteros next.

          ** Este metodo podria parecer de los mas sencillos, el problema es que
          aparentemente las funciones no pueden leer datos de un struct que estan
          inicializados en otra funcion, a pesar de que este metodo
          tenga un mecanismo que corrobora que esa informacion deberia existir.
          El problema muy probablemente se deba a que, para usar informacion sobre
          un puntero (en casos de que el puntero ya este asignado y se quiera leer
          lo que contiene), se tendria que asegurar que esa informacion existe, y
          la unica forma que la funcion tiene de hacerlo es que ese puntero y
          su informacion se hayan asignado en esa misma funcion.


    2. La forma mas lenta pero consume menos memoria.
        * Cada nodo se define al momento de crearse, dejando todos sus punteros
          next[] en NULL.
        * Los punteros del array next solo van a apuntar a algo en caso de que
          se cree un nodo especificamente en ese puntero.
        * Los nodos van a tener solo 2 partes:
          - datos
          - array de punteros next[]
        * Cuando se configura, el nodo a penas se acaba de crear, asi que la
          funcion que lo crea deberia devolver un nuevo nodo*
        * Para poder saber si hay una lista u otros nodos detrás de un puntero,
          lo unico que se debe hacer es verificar si no es NULL.
        * Para poder identificar en donde deberia estar almacenado un dato
          especifico (es decir, que punteros seguir, ya sea para localizarlo o
          para almacenar el dato correcto en el), como en este caso no
          tenemos un indice para buscarlo, deberia estar hardcodeado por el
          programador, ya sea con un tedioso switch (que bien podria estar
          resumido a una sola funcion), o con un array de structs que relacione
          cada dato con un [indice] del array de punteros next.
        * Para saber a que apunta cada puntero del array, es igual de facil que
          en la otra alternativa, solo que en este caso, es muy probable que
          algunos punteros apunten hacia NULL, y de esta forma no podriamos saber
          de forma sencilla que deberia estar almacenado en un puntero vacio.
        * La ventaja de esta alternativa es que consume mucha menos memoria y
          ademas es mas sencillo crear y liberar nodos. Ademas, en cuanto a
          tiempo de ejecucion, no pareceria empeorar mucho respecto a la otra
          alternativa que consume mucha mas memoria.
        * Las desventajas son que en realidad si tarda mas la ejecucion de
          determinados procesos, como identificar el dato que debe estar
          almacenado en un puntero del array vacio. Esto ademas representa un
          problema mayor, ya que para determinar en que puntero va cada dato
          se necesita implementar una funcion switch que regrese un [indice(int)],
          o un array de structs que relacione un dato con un indice. */


