// Calculates the length of a file

#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for valid usage
    if (argc != 2)
    {
        printf("Usage: ./flength [file name]\n");
        return 1;
    }

    int len;

    // Check for valid file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File not found\n");
        return 2;
    }

    // Set pointer to the end of file
    fseek(file, 0, SEEK_END);
    len = ftell(file);
    printf("File length: %i bytes.\n", len);

    fclose(file);
}