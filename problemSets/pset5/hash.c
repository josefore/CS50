// Programa de prueba de hash tables con numeros

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

const int DEC = 11, COD = 5;

typedef struct node
{
    char num;
    bool exists;
    struct node *next[DEC];
}
cifra;

void newnode(cifra **table, char *s, uint8_t pos);
void see(cifra *list);
void release(cifra *list);

int main(void)
{
    // El mero inicio del array de listas de arrays
    cifra *table[DEC];

    // Crear hash table
    for (uint8_t i = 0; i < (DEC - 1); i++)
    {
        table[i] = malloc(sizeof(cifra));
        if (table[i] == NULL)
        {
            printf("Error 1: could not allocate memory.\n");
            return 1;
        }

        table[i] -> num = i + '0';
        table[i] -> exists = false;
        for (uint8_t g = 0; g < DEC; g++)
        {
            table[i] -> next[g] = NULL;
        }
    }
    table[DEC - 1] = malloc(sizeof(cifra));
    if (table[DEC - 1] == NULL)
    {
        printf("Error 1: could not allocate memory.\n");
        return 1;
    }
    table[DEC - 1] -> num = '\0';
    table[DEC - 1] -> exists = false;
    for (uint8_t q = 0; q < DEC; q++)
    {
        table[DEC - 1] -> next[q] = NULL;
    }

    // Pedirle al usuario que introduzca 10 numeros de 4 cifras en code
    char code[DEC][COD];

    for (uint8_t i = 0; i < DEC; i++)
    {
        char buffer[16];
        do
        {
            printf("Type in number %i: ", (i + 1));
            scanf("%s", buffer);
        }
        while ((int)strlen(buffer) != COD - 1);
        buffer[COD - 1] = '\0';
        strcpy(code[i], buffer);
    }
    printf("\n");

    // Acomodarlos en un hash table
    for (uint8_t m = 0; m < DEC; m++)
    {
        uint8_t ctr = 0;
        bool found = false;
        do
        {
            if (code[m][0] == table[ctr] -> num)
            {
                newnode(&table[ctr], code[m], 0);
                found = true;
            }
            ctr++;
        }
        while (ctr < DEC && !found);
    }

    // Mostrar lista
    for (uint8_t i = 0; i < DEC; i++)
    {
        see(table[i]);
        printf("\n");
    }

    // Liberar espacio mallocado
    for (uint8_t i = 0; i < DEC; i++)
    {
        release(table[i]);
    }
}

/*  1. Para la primera letra, checar si hay alguna lista que empiece con
    esa letra, es decir, cuyo indice ya este ocupado.
    2. En caso de que este ocupado, ir a esa lista y checar si la segunda letra
    ya existe en esa rama, y hacer eso hasta que se llegue a una letra diferente
    o termine la palabra.
    3. En caso de que este desocupado, empezar una nueva lista
*/

// Funcion que encuentra el lugar del hash table dobde debe ser colocado newnode



// Acomodar un nuevo nodo
void newnode(cifra **table, char *s, uint8_t pos)
{
    if (*table == NULL)
    {
        return;
    }
    cifra *tmp = *table;
    bool rexist = false;
    for (uint8_t h = 0; h < DEC; h++)
    {
        if (tmp -> next[h] != NULL)
        {
            rexist = true;
        }
    }
    // Casos base
    // Caso base: se encontro el caracter nul o no hay nada mas que leer
    if (rexist)
    {
        bool found = false;
        uint8_t i = 0;
        do
        {
            if (tmp -> next[i] -> num == s[pos + 1])
            {
                newnode(&tmp -> next[i], s, pos + 1);
                found = true;
            }
            i++;
        }
    while (i < DEC && !found);
    }
    // Corroborar que los punteros next tienen algo almacenado

    // Si existe pero "existe" = false (o no hay nada en los punteros):
    tmp -> exists = true;
    // Generar y asignar un nodo en cada puntero
    for (uint8_t i = 0; i < DEC - 1; i++)
    {
        tmp -> next[i] = malloc(sizeof(cifra));
        if (tmp -> next[i] == NULL)
        {
            return;
        }
        tmp -> next[i] -> num = i + '0';
        tmp -> next[i] -> exists = false;
        for (uint8_t g = 0; g < DEC; g++)
        {
            tmp -> next[i] -> next[g] = NULL;
        }
    }
    tmp -> next[DEC - 1] = malloc(sizeof(cifra));
    if (tmp -> next[DEC - 1] == NULL)
    {
        return;
    }
    tmp -> next[DEC - 1] -> num = '\0';
    tmp -> next[DEC - 1] -> exists = false;

    *table = tmp;
}


// Si no acepta el tipo de dato "array of ptrs", probar con cada lista del array
void see(cifra *list)
{
    // Base case: si se llega a nul
    if (list == NULL)
    {
        return;
    }

    bool rexist = true;
    for (uint8_t h = 0; h < DEC; h++)
    {
        if (list -> next[h] == NULL)
        {
            rexist = false;
        }
    }

    if (rexist)
    {
        for (uint8_t i = 0; i < DEC; i++)
        {
            see(list -> next[i]);
        }
    }

    if (list -> exists == true)
    {
        printf("%c ", list -> num); // hay que ver si esto va aqui o arriba o abajo
    }
}

void release(cifra *list)
{
    if (list == NULL)
    {
        return;
    }

    bool rexist = false;
    for (uint8_t h = 0; h < DEC; h++)
    {
        if (list -> next[h] != NULL)
        {
            rexist = true;
        }
    }

    if (rexist)
    {
        for (uint8_t i = 0; i < DEC; i++)
        {
            release(list -> next[i]);
        }
    }
    free(list); // hay que ver si esto va aqui o arriba
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


