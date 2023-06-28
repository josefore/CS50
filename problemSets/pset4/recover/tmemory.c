// Calculates the length of a file and looks into specific bytes
// by Jose Contreras

#include <stdio.h>
#include <stdint.h>
#include <cs50.h>

// Function prototypes
void flength(FILE *file);
void valuecheck(FILE *file);

int main(int argc, char *argv[])
{
    // Check for valid usage
    if (argc != 2)
    {
        printf("Usage: ./flength [file name]\n");
        return 1;
    }

    // Check for valid file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File not found\n");
        return 2;
    }

    flength(file);

    valuecheck(file);

    fclose(file);
}

// Calculate file length
void flength(FILE *file)
{
    fseek(file, 0, SEEK_END);
    int len = ftell(file);
    printf("File length: %i bytes.\n", len);
    printf("\n");
}

void valuecheck(FILE *file)
{
    // Prompt user for byte location in file
    int byte_loc = get_int("Byte location: ");

    // Prompt user for array length of displayed bytes
    int arr_len = get_int("Length of the array of displayed bytes: ");
    int byte_arr = byte_loc + arr_len;
    printf("\n");

    // Print value of each byte and its position
    for (int i = (byte_loc - 1); i <=  (byte_arr - 2); i++)
    {
        int buffer[4];
        int block[4];
        fseek(file, i, SEEK_SET);
        fread(&buffer, sizeof(block), 1, file);
        printf("Byte location: %i\n", (i + 1));
        printf("Byte value: %p\n", buffer);
        printf("\n");
    }
}