// Program that stores a song library in a .CSV

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include "song.h"
#include "menu.h"

bool exitprogram(int option);

int main(void)
{
    FILE *mlib = fopen("songlibrary.csv", "a+");
    if (mlib == NULL)
    {
        return 1;
    }

    int opt = 0;

    // Display menu
    menu();

    do
    {
        opt = get_int("Option: ");

        switch (opt)
        {
           /* case 1:
                see(mlib);
                break;

            case 2:
                add();
                break;

            case 3:
                edt();
                break;

            case 4:
                dlt();
                break; */

            default:
                if (exitprogram(opt))
                    return 0;
                break;
        }
    }
    while (opt < 1 || opt > 5);
}

// Exit program
bool exitprogram(int option)
{
    if (option == 5)
    {
        printf("Are you sure you want to exit? y/n\n");
        char *optYN = get_string("Are you sure you want to exit? y/n: ");
        if (optYN[0] == 'Y' || optYN[0] == 'y')
        {
            return true;
        }
    }

    return false;
}

void see(FILE *mlib)
{
    
}