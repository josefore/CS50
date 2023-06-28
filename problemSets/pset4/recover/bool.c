#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

bool bl(char *s);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid usage.\n");
        return 1;
    }
    if (bl(argv[1]))
    {
        printf("Ok.\n");
        return 0;
    }
    else
    {
        printf(":(\n");
        return 0;
    }
}

bool bl(char *s)
{
    if (s[0] == 'y' && s[1] == 'e'
    &&  s[2] == 's' && s[3] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}