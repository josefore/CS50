#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc == 2)
    {
        int k = atoi(key);
        int i = strlen(key);
        int a = 0;
        for (int n = 0; n < i; n++)
        {
            char c = key[n];
            if (isdigit(c) == 0)
            {
                a++;
            }
        }
        if (a == 0)
        {
            string p = get_string("plaintext: ");
            printf("ciphertext: ");
            int l = strlen(p);
            for (int m = 0; m < l; m++)
            {
                char pt = p[m];
                if (isalpha(pt) != 0)
                {
                    int ctn = (int) pt;
                    if (isupper(pt) != 0)
                    {
                        //CAPITALES
                        int pf = ((k + (ctn - 64)) % 26) + 64;
                        char upc = (char) pf;
                        printf("%c", upc);
                    }
                    else
                    {
                        //minusculas
                        int lf = ((k + (ctn - 96))  % 26) + 96;
                        char lpc = (char) lf;
                        printf("%c", lpc);
                    }
                }
                else
                {
                    printf("%c", pt);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}