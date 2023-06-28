// Prueba para saber como leen y tratan las funciones informacion de structs
// Que pasan en un puntero como argumento la funcion que crea ese struct

#include <stdio.h>
#include <stdlib.h>

// Definicion de node
typedef struct nodo
{
    int a;
    struct nodo *next;
}
node;

void see(node *list);
void edit(node *list);
void release(node *list);

int main(void)
{
    node *list = NULL;

    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Error 1.\n");
        return 1;
    }

    newnode -> a = 10;
    newnode -> next = NULL;
    list = newnode;

    node *nvonode = malloc(sizeof(node));
    if (nvonode == NULL)
    {
        printf("Error 1.\n");
        return 1;
    }

    nvonode -> a = 20;
    nvonode -> next = newnode;
    list = nvonode;

    newnode = malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Error 1.\n");
        return 1;
    }

    newnode -> a = 30;
    newnode -> next = nvonode;
    list = newnode;

    see(list);

    edit(list);

    see(list);

    edit(list);

    see(list);

    release(list);
}

// Muestra cada nodo usando recursividad
void see(node *list)
{
    // Caso base
    if (list == NULL)
    {
        return;
    }

    // Caso recursivo: pasar al que sigue y despues mostrar
    see(list -> next);

    printf("%i\n", list -> a);
}

// Edita cada nodo multiplicando el valor de a 10 veces
void edit(node *list)
{
    if (list == NULL)
    {
        return;
    }

    edit(list -> next);

    list -> a = list -> a * 10;
}

// Elimina todos los nodos
void release(node *list)
{
    if (list == NULL)
    {
        return;
    }

    release(list -> next);

    free(list);
}