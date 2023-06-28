#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n = get_int("How many words are you typing in?\n");

    char *s[n];
    int m[n];
    int *o;

    for (int i = 0; i < n; i++)
    {
        s[i] = get_string("Type in the word %i: ", (i + 1));
        m[i] = strlen(s[i]);
    }

    printf("%s\n", s[1]);

    for (int j = 0; j < n; j++)
    {
        printf("Word %i: %s\n", (j + 1), s[j]);
    }
}