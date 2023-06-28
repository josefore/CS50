#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("Type in whatever: \n");
    char *s = "0";
    scanf("%s", s);
    int *ptr = malloc(strlen(s) + 1);
    if (s == NULL)
        return 1;
    printf("%s", s);
    free(ptr);
}