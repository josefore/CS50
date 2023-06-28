#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int ltct(string t, int i);

int main(void)
{
    string t = get_string("Text: ");
    int i = strlen(t);
    float lnum = 0;
    float wnum = 0;
    float snum = 0;
    for (int n = 0; n <= i; n++)
    {
        char let = t[n];
        char plt = t[n - 1];
        if (isalpha(let) != 0)
        {
            lnum++;
        }
        else
        {
            if ((let != '-') && (isalpha(plt) != 0))
            {
                wnum++;
                if (((let == '.') || (let == '?') || (let == '!')) && (isalpha(plt) != 0))
                {
                snum++;
                }
            }
        }
    }
    float L = lnum / wnum * 100;
    float S = snum / wnum * 100;
    float CLI = 0.0588 * L - 0.296 * S - 15.8;
    if (CLI < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (CLI > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(CLI));
    }
}

