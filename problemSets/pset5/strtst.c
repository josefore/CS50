// Programa de prueba para delimitar tamanos de los strings

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    string str = get_string("Type in a word: \n");

    int *n;

    printf("%lu\n", sizeof(str));
    printf("%lu\n", sizeof(n));
}