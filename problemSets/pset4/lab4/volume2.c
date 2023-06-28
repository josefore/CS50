// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t position_count = 0;
    uint8_t h_buffer;
    while (fread(&h_buffer, sizeof(uint8_t), 1, input) && position_count < HEADER_SIZE)
    {
        fwrite(&h_buffer, sizeof(uint8_t), 1, output);
        position_count++;
    }
    
    int position0 = ftell(input);
    printf("Current byte position (0): %i\n", position0);

    uint8_t buffer;
    fread(&buffer, sizeof(uint8_t), 1, input);
    printf("Current 16 byte value: %u\n", buffer);
    int position1 = ftell(input);
    printf("Current byte position (1): %i\n", position1);

    // TODO: Read samples from input file and write updated data to output file


    // Close files
    fclose(input);
    fclose(output);
}

