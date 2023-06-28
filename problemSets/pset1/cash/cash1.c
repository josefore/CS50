#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float i;
    do
    {
        i = get_float("Change owed: \n");
    }
    while (i <= 0);
    float d = round(i / 0.25);
    float c = round(fmod(i, 0.25));
    float b = round(fmod(c, 0.10));
    float a = round(fmod(b, 0.05));
    float f = round(d + c / 0.10 + b / 0.5 + a);
    printf("%.2f\n", f);
}