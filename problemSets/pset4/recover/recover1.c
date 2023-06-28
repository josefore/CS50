#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//Function prototypes
bool header(uint8_t b[]);

int main(int argc, char *argv[])
{
    // Check for valid usage
    if (argc != 2)
    {
        printf("Usage: ./recover [file name]\n");
        return 1;
    }

    // Open file
    FILE *image = fopen(argv[1], "r");
    if (image == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Buffer
    uint8_t buffer[512];
    uint8_t h_buffer[4];
    int i = 0;
    bool start = false;
    FILE *img = 0;
    // Loop until end of file
    while (fread(&buffer, (sizeof(uint8_t) * 512), 1, image))
    {
        int end = (int)fread;
        // Check first 4 bytes
        h_buffer[0] = buffer[0];
        h_buffer[1] = buffer[1];
        h_buffer[2] = buffer[2];
        h_buffer[3] = buffer[3];
        // First JPEG
        // Checar si es el principio de un jpeg
        if (header(h_buffer))
        {
        // Checar si es el primero
            if (!start)
            {
                char filename[8];
                sprintf(filename, "%03i.jpg", i);
                img = fopen(filename, "w");
                fwrite(&buffer, (sizeof(uint8_t) * 512), 1, img);
                start = true;
            }
            else
            {
                fclose(img);
                i++;
                char filename[8];
                sprintf(filename, "%03i.jpg", i);
                img = fopen(filename, "w");
                fwrite(&buffer, (sizeof(uint8_t) * 512), 1, img);
            }
        }

        // No es el primero
        // No es el principio de un JPEG
        else
        {
            if (start)
            {
                fwrite(&buffer, (sizeof(uint8_t) * 512), 1, img);
            }
        }

        // Close last file
        if (end != 512)
        {
            fclose(img);
            break;
        }

    }
    fclose(image);
}


// Header signature
bool header(uint8_t b[])
{
    if (b[0] == 0xff && b[1] == 0xd8 &&
        b[2] == 0xff && (b[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


