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

    // Print out current calue and position
    printf("Value stored in this 8bit variable (0): %u\n", h_buffer);
    int position0 = ftell(input);
    printf("Current position in file: %i\n", position0);

    // ** Go to current position [cur + 0] and print its value **
    fseek(input, 0, SEEK_CUR);
    int16_t value1;
    fread(&value1, sizeof(int16_t), 1, input);
    printf("Value stored in this 16 bit variable (1): %d\n", value1);
    int position1 = ftell(input);
    printf("Current position in file: %i\n", position1);

    // ** Check if it's current position and print its value **
    fseek(input, 20, SEEK_SET);
    int16_t value2;
    fread(&value2, sizeof(int16_t), 1, input);
    printf("Value stored in this 16bit variable (2): %d\n", value2);
    int position2 = ftell(input);
    printf("Current position in file: %i\n", position2);
    
    // ** Check vaalue of 8bit buffer 3 **
    fseek(input, 1000, SEEK_SET);
    uint8_t value3;
    fread(&value3, sizeof(uint8_t), 1, input);
    printf("Value stored in this 8bit variable (3): %u\n", value3);
    int position3 = ftell(input);
    printf("Current position in this file: %i\n", position3);
    
    // ** Check vaalue of 8bit buffer 3 **
    int block = position3 + 8;
    for (int i = position3; i <= block; i++)
    {
        uint8_t cont_v;
        fseek(input, i, SEEK_SET);
        fread(&cont_v, sizeof(uint8_t), 1, input);
        int cont_p = ftell(input);
        printf("Value: %u\n", cont_v);
        printf("Position: %i\n", cont_p);
    }

    // TODO: Read samples from input file and write updated data to output file


    // Close files
    fclose(input);
    fclose(output);
}

