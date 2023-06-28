// Programa que prueba como funciona fscanf

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 48

typedef struct node
{
    char word[LENGTH];
    struct node *next;
}
str;

// Function prototypes
void release(str *list);
void see(str *list);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./fscanftest [TextFile] ...\n");
        return 1;
    }
    // Generar lista
    str *list = NULL;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not load file.\n");
        return 2;
    }

    char palabra[LENGTH];

    while (fscanf(file, "%s", palabra) != EOF)
    {
        str *newnode = malloc(sizeof(str));
        if (newnode == NULL)
        {
            fclose(file);
            printf("Could not allocate memory.\n");
            return 3;
        }

        strcpy(newnode -> word, palabra);
        newnode -> next = list;
        list = newnode;
    }

    if (ferror(file))
    {
        fclose(file);
        release(list);
        printf("File error.\n");
        return 4;
    }

    fclose(file);

    see(list);

    release(list);

    return 0;
}

void release(str *list)
{
    if (list == NULL)
    {
        return;
    }

    release(list -> next);

    free(list);
}

void see(str *list)
{
    if (list == NULL)
    {
        return;
    }

    see(list -> next);

    printf("%s ", list -> word);
}