#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int i;
    do
    {
        i = get_int("Change owed: ");
    }
    while (i <= 0);
    int d = (i / 25);
    int c = (i % 25);
    int b = (c % 10);
    int a = (b % 5);
    int f = (d + round(c / 10) + round(b / 5) + a);
    printf("%i\n", f);
}