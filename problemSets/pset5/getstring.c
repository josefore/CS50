#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char* palabra = get_string("Escribe la palabra: ");

    printf("%i\n", (int)palabra[strlen(palabra) - 1]);
}