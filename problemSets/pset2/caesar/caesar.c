#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void crypt(int k, char pt, int ctn);

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
                int ctn = (int) pt;
                crypt(k, pt, ctn);
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

//Encriptado
void crypt(int key, char plaintext, int carnum)
{
    if (isalpha(plaintext) != 0)
    {
        //MAYUSCULAS
        if (isupper(plaintext) != 0)
        {
            int pf = ((key + (carnum - 64)) % 26) + 64;
            char upc = (char) pf;
            printf("%c", upc);
        }
        else
        {
            //minusculas
            int lf = ((key + (carnum - 96))  % 26) + 96;
            char lpc = (char) lf;
            printf("%c", lpc);
        }
    }
    else
    {
        printf("%c", plaintext);
    }
}