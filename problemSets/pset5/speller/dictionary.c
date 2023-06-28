// Implements a dictionary's functionality
// <strings.h> got from The IEEE and The Open Group

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Number of buckets in hash table
const unsigned int N = 28;

// Represents a node in a hash table
typedef struct node
{
    char c;
    struct node *next[N];
}
node;

// Local functions
void release(node *list);
bool correct(node *list, const char *word, int pos);
unsigned int ind(const char character);
void place(node **list, char *s, int pos);
node *newnode(char *s, int pos);

// Dictionary size
int sz = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    /*  cada vez que se compruebe que si existe una lista con esa letra, se
        repite la funcion hash (TRIE)
    */
    node *w = table[ind(word[0])];

    return correct(w, word, 0);
}

// NEW
// Recursively look for a word in the list
bool correct(node *list, const char *s, int pos)
{
    if (list == NULL)
    {
        return false;
    }

    bool b = false;

    if (pos > (int)strlen(s) || tolower(s[pos]) != list -> c)
    {
        return false;
    }

    if (s[pos] == '\0' && list -> c == '\0')
    {
        return true;
    }

    if (s[pos] != '\0' && pos < (int)strlen(s))
    {
        b = correct(list -> next[ind(s[pos + 1])], s, pos + 1);
    }

    return b;
}

unsigned int hash(const char *word)
{
    return 0;
}

// NEW
// Hashes word to a number
unsigned int ind(const char character)
{
    // TODO
    /*  Solo es necesario saber la primer letra en teoria, pero lo mas
        conveniente seria que esta funcion se repita con cada letra de la
        palabra hasta llegar a un caracter que no sea alfanumerico.
    */
    char car = tolower(character);

    switch (car)
    {
        case '\'':
            return 26;

        case '\0':
            return 27;

        default:
            return (int)car - 97;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    /*  La clave para la solucion a esta funcion puede estar justo en la parte
        de main en la que cargan todas las palabras del texto (text).
    */
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH];
    node *current = NULL;

    // Copy each word into hash table
    while (fscanf(file, "%s", word) != EOF) // Checar si no es necesario decirle a la maquina cuando terminar la palabra
    {
        current = table[ind(word[0])];
        place(&current, word, 0);
        table[ind(word[0])] = current;
        sz++; // Habria que manejar excepciones?
    }

    if (ferror(file))
    {
        return false;
    }

    fclose(file);

    return true;
}

// NEW
// Place every character into its corresponding place in the trie
void place(node **list, char *s, int pos)
{
    // Si no hay nada, hay que asignar memoria para uno nuevo
    if (*list == NULL)
    {
        *list = newnode(s, pos);
        return;
    }

    // Si se llega al final del string
    if (s[pos] == '\0' || pos > (int)strlen(s))
    {
        return;
    }

    node *tmp = *list;

    // Pasar al siguiente nodo
    place(&tmp -> next[ind(s[pos + 1])], s, pos + 1);
}

// NEW
// Allocate a new node
node *newnode(char *s, int pos)
{
    // Caso base 1: ya llego al limite de longitud
    if (pos > (int)strlen(s))
    {
        return NULL;
    }

    // Asignar memoria para el nuevo nodo
    node *nuevo = malloc(sizeof(node));
    if (nuevo == NULL)
    {
        return NULL;
    }

    // Asignar el valor de num de ese nodo
    nuevo -> c = tolower(s[pos]);

    for (int i = 0; i < N; i++)
    {
        nuevo -> next[i] = NULL;
    }

    // Caso recursivo: alamcenar en el next correspondiente la informacion del siguiente nodo
    if (s[pos] != '\0' && pos < (int)strlen(s))
    {
        nuevo -> next[ind(s[pos + 1])] = newnode(s, pos + 1);
    }

    return nuevo;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return sz;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Loop over the array and delete each list calling another funtion
    node *trv = NULL;

    // Bool to return
    for (int i = 0; i < N; i++)
    {
        trv = table[i]; // VEr si esto es necesario

        release(trv);
    }
    return true;
}

// Releases used memory
void release(node *list)
{
    // Caso base: no hay nada en table
    if (list == NULL)
    {
        return;
    }

    // Buscar cuales de los punteros apuntan a algo y ver a donde nos llevan
    for (int i = 0; i < N; i++)
    {
        release(list -> next[i]);
    }
    free(list);
}