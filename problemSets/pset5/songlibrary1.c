// Programa que maneja una lista enlazada de canciones

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

const int BIG = 64;
const int SHR = 32;

typedef struct node
{
    char title[BIG];
    char artst[BIG];
    char album[BIG];
    char label[SHR];
    int year;
    float duration;
    char genre[SHR];
    struct node *next;
}
song;

int length(char *data, int size);
void liberar(song* lista);

int main(void)
{
    song *list = NULL;
    song *buf = malloc(sizeof(song));

    if (buf == NULL)
    {
        printf("Error 1: Pointer to NULL.");
        return 1;
    }

    char *ttmp;
    char *atmp;
    int big = BIG;
    int shr = SHR;

    // Checar el tamano del titulo
    do
    { ttmp = get_string("Title: "); }
    while (length(ttmp, big) == 0);

    for (int i = 0; i < length(ttmp, big); i++)
    {
        buf -> title[i] = ttmp[i];
    }

    // Checar el tamano del artista
    do
    { atmp = get_string("Artist: "); }
    while (length(atmp, big) == 0);

    for (int i = 0; i < length(atmp, big); i++)
    {
        buf -> artst[i] = atmp[i];
    }

    buf -> next = NULL;

    list = buf;

    printf("\n");

    song *fer = malloc(sizeof(song));

    if (fer == NULL)
    {
        printf("Error 1: Pointer to NULL.");
        liberar(list);
        return 1;
    }

    // Checar el tamano del titulo
    do
    { ttmp = get_string("Title: "); }
    while (length(ttmp, big) == 0);

    for (int i = 0; i < length(ttmp, big); i++)
    {
        fer -> title[i] = ttmp[i];
    }

    // Checar el tamano del artista
    do
    { atmp = get_string("Artist: "); }
    while (length(atmp, big) == 0);

    for (int i = 0; i < length(atmp, big); i++)
    {
        fer -> artst[i] = atmp[i];
    }

    fer -> next = buf;

    list = fer;

    printf("\n");

    buf = malloc(sizeof(song));
    if (buf == NULL)
    {
        printf("Error 1: Pointer to NULL.");
        liberar(list);
        return 1;
    }

    // Checar el tamano del titulo
    do
    { ttmp = get_string("Title: "); }
    while (length(ttmp, big) == 0);

    for (int i = 0; i < length(ttmp, big); i++)
    {
        buf -> title[i] = ttmp[i];
    }

    // Checar el tamano del artista
    do
    { atmp = get_string("Artist: "); }
    while (length(atmp, big) == 0);

    for (int i = 0; i < length(atmp, big); i++)
    {
        buf -> artst[i] = atmp[i];
    }

    buf -> next = fer;

    list = buf;

    printf("\n");

    fer = malloc(sizeof(song));
    if (fer == NULL)
    {
        printf("Error 1: Poniter to NULL.");
        liberar(list);
        return 1;
    }

    // Checar el tamano del titulo
    do
    { ttmp = get_string("Title: "); }
    while (length(ttmp, big) == 0);

    for (int i = 0; i < length(ttmp, big); i++)
    {
        fer -> title[i] = ttmp[i];
    }

    // Checar el tamano del artista
    do
    { atmp = get_string("Artist: "); }
    while (length(atmp, big) == 0);

    for (int i = 0; i < length(atmp, big); i++)
    {
        fer -> artst[i] = atmp[i];
    }

    fer -> next = buf;

    list = fer;

    printf("\n");
    printf("Outcome:\n");

    // Mostrar elementos de la lista

    for (song *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        printf("%s\n", tmp -> title);
        printf("%s\n", tmp -> artst);
        printf("\n");
    }

    // Liberar memoria ocupada
    while (list != NULL)
    {
        song *tmp = list -> next;
        free(list);
        list = tmp;
    }

    return 0;
}

int length(char *data, int size)
{
    int ctr = 0;
    bool found = false;

    do
    {
        if (data[ctr] == '\0')
        {
            found = true;
            ctr++;
            break;
        }
        ctr++;
    }
    while (ctr < size);

    if (found)
    { return ctr; }
    else
    {
        printf("Invalid format.\n");
        return 0;
    }
}

void liberar(song *lista)
{
    if (lista -> next == NULL)
    {
        free(lista);
        return;
    }
    else
    {
        liberar(lista -> next);
    }
}