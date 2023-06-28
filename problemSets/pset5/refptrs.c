// Programa de prueba para conocer como funcionan los argumentos por referencias por pointers

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct nd
{
    int a;
    struct nd *next;
}
node;

void release(node *lista);
void showlist(node *l);
void add(node **lista);

int main(void)
{
    node *lista = NULL;

    node *nuevo = malloc(sizeof(node));
    if (nuevo == NULL)
    {
        printf("Error 1: memory not allocated.\n");
        return 1;
    }

    nuevo -> a = 1;
    nuevo -> next = NULL;

    node *brand = malloc(sizeof(node));
    if (brand == NULL)
    {
        printf("Error 1: memory not allocated.\n");
        return 1;
    }

    brand -> a = 2;
    brand -> next = nuevo;
    lista = brand;

    nuevo = malloc(sizeof(node));
    if (nuevo == NULL)
    {
        printf("Error 1: memory not allocated.\n");
        return 1;
    }

    nuevo -> a = 3;
    nuevo -> next = brand;
    lista = nuevo;

    brand = malloc(sizeof(node));
    if (brand == NULL)
    {
        printf("Error 1: memory not allocated.\n");
        return 1;
    }

    brand -> a = 4;
    brand -> next = nuevo;
    lista = brand;

    showlist(lista);

    add(&lista);

    showlist(lista);

    release(lista);
}

// Mostrar lista
void showlist(node *l)
{
    for (node *tmp = l; tmp != NULL; tmp = tmp -> next)
    {
        printf("%i\n", tmp -> a);
    }
    printf("\n");
}

void release(node *lista)
{
    // Base case
    if (lista == NULL)
    {
        return;
    }

    release(lista -> next);
    free(lista);
}

void add(node **lista)
{
    int b = get_int("New node: ");

    node *cpy = *lista;
    node *nuevo = malloc(sizeof(node));

    nuevo -> a = b;
    nuevo -> next = cpy;
    *lista = nuevo;
}