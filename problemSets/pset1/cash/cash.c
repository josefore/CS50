#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float i;
    do
    {
        i = get_float("Change owed: ");
    }
    while (i <= 0);
    int j = round(i * 100);
    int d = (j / 25);
    int c = (j % 25);
    int b = (c % 10);
    int a = (b % 5);
    int f = (d + (c / 10) + (b / 5) + a);
    printf("%i\n", f);
}