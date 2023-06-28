#include <stdio.h>
#include <cs50.h>

void hashm(int i, int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        for (int k = n - i - 1; k > 0; k = k - 1)
        {
            printf(" ");
        }
        hashm(i, n);
        printf("  ");
        hashm(i, n);
        printf("\n");
    }
}

void hashm(int i, int n)
{
    for (int j = 0; j <= i; j++)
    {
        printf("#");
    }
}