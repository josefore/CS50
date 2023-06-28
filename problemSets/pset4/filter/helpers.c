#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Get the value of current pixel
            float blue = image[h][w].rgbtBlue;
            float green = image[h][w].rgbtGreen;
            float red = image[h][w].rgbtRed;

            // Get the average of color value
            float av = (blue + green + red) / 3;
            float avg = roundf(av);
            int gray = (int)avg;

            // Change the color value of pixel
            image[h][w].rgbtBlue = gray;
            image[h][w].rgbtGreen = gray;
            image[h][w].rgbtRed = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Get the value of current pixel
            float blue = image[h][w].rgbtBlue;
            float green = image[h][w].rgbtGreen;
            float red = image[h][w].rgbtRed;

            // Sepia algorithm
            float sBlue = 0.272 * red + 0.534 * green + 0.131 * blue;
            if (sBlue > 255)
            {
                sBlue = 255;
            }
            float br = roundf(sBlue);
            int sb = (int)br;

            float sGreen = 0.349 * red + 0.686 * green + 0.168 * blue;
            if (sGreen > 255)
            {
                sGreen = 255;
            }
            float gr = roundf(sGreen);
            int sg = (int)gr;

            float sRed = 0.393 * red + 0.769 * green + 0.189 * blue;
            if (sRed > 255)
            {
                sRed = 255;
            }
            float rr = roundf(sRed);
            int sr = (int)rr;

            // Change color value of pixel
            image[h][w].rgbtBlue = sb;
            image[h][w].rgbtGreen = sg;
            image[h][w].rgbtRed = sr;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each row
    for (int h = 0; h < height; h++)
    {
        // Allocate memory for current row
        RGBTRIPLE *wptr = malloc(sizeof(RGBTRIPLE) * width);

        // Decreasing "width" value
        int wd = width - 1;
        // Store each pixel in reverse order in wptr
        for (int w = 0; w < width; w++)
        {
            wptr[wd] = image[h][w];
            wd--;
        }

        // Copy array wptr into row
        for (int i = 0; i < width; i++)
        {
            image[h][i] = wptr[i];
        }

        // Free memory
        free(wptr);
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory for a copy of the image
    RGBTRIPLE copy[height][width];
    float px[3][9];

    for (int k = 0; k < height; k++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[k][j].rgbtBlue = image[k][j].rgbtBlue;
            copy[k][j].rgbtGreen = image[k][j].rgbtGreen;
            copy[k][j].rgbtRed = image[k][j].rgbtRed;
        }
    }

    // Iterate over each pixel
    for (int y = 0; y < height; y++)
    {
        for (int z = 0; z < width; z++)
        {
            if (y != 0 && y < (height - 1) && z != 0 && z < (width - 1))
            {
                px[0][0] = copy[y - 1][z - 1].rgbtBlue;
                px[0][1] = copy[y - 1][z].rgbtBlue;
                px[0][2] = copy[y - 1][z + 1].rgbtBlue;
                px[0][3] = copy[y][z - 1].rgbtBlue;
                px[0][4] = copy[y][z].rgbtBlue;
                px[0][5] = copy[y][z + 1].rgbtBlue;
                px[0][6] = copy[y + 1][z - 1].rgbtBlue;
                px[0][7] = copy[y + 1][z].rgbtBlue;
                px[0][8] = copy[y + 1][z + 1].rgbtBlue;

                px[1][0] = copy[y - 1][z - 1].rgbtGreen;
                px[1][1] = copy[y - 1][z].rgbtGreen;
                px[1][2] = copy[y - 1][z + 1].rgbtGreen;
                px[1][3] = copy[y][z - 1].rgbtGreen;
                px[1][4] = copy[y][z].rgbtGreen;
                px[1][5] = copy[y][z + 1].rgbtGreen;
                px[1][6] = copy[y + 1][z - 1].rgbtGreen;
                px[1][7] = copy[y + 1][z].rgbtGreen;
                px[1][8] = copy[y + 1][z + 1].rgbtGreen;

                px[2][0] = copy[y - 1][z - 1].rgbtRed;
                px[2][1] = copy[y - 1][z].rgbtRed;
                px[2][2] = copy[y - 1][z + 1].rgbtRed;
                px[2][3] = copy[y][z - 1].rgbtRed;
                px[2][4] = copy[y][z].rgbtRed;
                px[2][5] = copy[y][z + 1].rgbtRed;
                px[2][6] = copy[y + 1][z - 1].rgbtRed;
                px[2][7] = copy[y + 1][z].rgbtRed;
                px[2][8] = copy[y + 1][z + 1].rgbtRed;

                // Get averages
                float avgBlue = (px[0][0] + px[0][1] + px[0][2] +
                                 px[0][3] + px[0][4] + px[0][5] +
                                 px[0][6] + px[0][7] + px[0][8]) / 9;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1][0] + px[1][1] + px[1][2] +
                                  px[1][3] + px[1][4] + px[1][5] +
                                  px[1][6] + px[1][7] + px[1][8]) / 9;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[2][0] + px[2][1] + px[2][2] +
                                px[2][3] + px[2][4] + px[2][5] +
                                px[2][6] + px[2][7] + px[2][8]) / 9;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }
            // Left top corner
            else if (y == 0 && z == 0)
            {
                px[0][4] = copy[y][z].rgbtBlue;
                px[0][5] = copy[y][z + 1].rgbtBlue;
                px[0][7] = copy[y + 1][z].rgbtBlue;
                px[0][8] = copy[y + 1][z + 1].rgbtBlue;

                px[1][4] = copy[y][z].rgbtGreen;
                px[1][5] = copy[y][z + 1].rgbtGreen;
                px[1][7] = copy[y + 1][z].rgbtGreen;
                px[1][8] = copy[y + 1][z + 1].rgbtGreen;

                px[2][4] = copy[y][z].rgbtRed;
                px[2][5] = copy[y][z + 1].rgbtRed;
                px[2][7] = copy[y + 1][z].rgbtRed;
                px[2][8] = copy[y + 1][z + 1].rgbtRed;

                float avgBlue = (px[0][4] + px[0][5] + px[0][7] +
                                 px[0][8]) / 4;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1][4] + px[1][5] + px[1][7] +
                                  px[1][8]) / 4;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[2][4] + px[2][5] + px[2][7] +
                                px[2][8]) / 4;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Top edge
            else if (y == 0 && z != 0 && z < (width - 1))
            {
                px[0][3] = copy[y][z - 1].rgbtBlue;
                px[0][4] = copy[y][z].rgbtBlue;
                px[0][5] = copy[y][z + 1].rgbtBlue;
                px[0][6] = copy[y + 1][z - 1].rgbtBlue;
                px[0][7] = copy[y + 1][z].rgbtBlue;
                px[0][8] = copy[y + 1][z + 1].rgbtBlue;

                px[1][3] = copy[y][z - 1].rgbtGreen;
                px[1][4] = copy[y][z].rgbtGreen;
                px[1][5] = copy[y][z + 1].rgbtGreen;
                px[1][6] = copy[y + 1][z - 1].rgbtGreen;
                px[1][7] = copy[y + 1][z].rgbtGreen;
                px[1][8] = copy[y + 1][z + 1].rgbtGreen;

                px[2][3] = copy[y][z - 1].rgbtRed;
                px[2][4] = copy[y][z].rgbtRed;
                px[2][5] = copy[y][z + 1].rgbtRed;
                px[2][6] = copy[y + 1][z - 1].rgbtRed;
                px[2][7] = copy[y + 1][z].rgbtRed;
                px[2][8] = copy[y + 1][z + 1].rgbtRed;

                float avgBlue = (px[0][3] + px[0][4] + px[0][5] +
                                 px[0][6] + px[0][7] + px[0][8]) / 6;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1][3] + px[1][4] + px[1][5] +
                                  px[1][6] + px[1][7] + px[1][8]) / 6;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[2][3] + px[2][4] + px[2][5] +
                                px[2][6] + px[2][7] + px[2][8]) / 6;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Right top corner
            else if (y == 0 && z == (width - 1))
            {
                px[0][3] = copy[y][z - 1].rgbtBlue;
                px[0][4] = copy[y][z].rgbtBlue;
                px[0][6] = copy[y + 1][z - 1].rgbtBlue;
                px[0][7] = copy[y + 1][z].rgbtBlue;

                px[1][3] = copy[y][z - 1].rgbtGreen;
                px[1][4] = copy[y][z].rgbtGreen;
                px[1][6] = copy[y + 1][z - 1].rgbtGreen;
                px[1][7] = copy[y + 1][z].rgbtGreen;

                px[2][3] = copy[y][z - 1].rgbtRed;
                px[2][4] = copy[y][z].rgbtRed;
                px[2][6] = copy[y + 1][z - 1].rgbtRed;
                px[2][7] = copy[y + 1][z].rgbtRed;

                float avgBlue = (px[0][3] + px[0][4] + px[0][6] +
                                 px[0][7]) / 4;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1][3] + px[1][4] + px[1][6] +
                                  px[1][7]) / 4;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[2][3] + px[2][4] + px[2][6] +
                                px[2][7]) / 4;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Left edge
            else if (y != 0 && y < (height - 1) && z == 0)
            {
                px[0][1] = copy[y - 1][z].rgbtBlue;
                px[0][2] = copy[y - 1][z + 1].rgbtBlue;
                px[0][4] = copy[y][z].rgbtBlue;
                px[0][5] = copy[y][z + 1].rgbtBlue;
                px[0][7] = copy[y + 1][z].rgbtBlue;
                px[0][8] = copy[y + 1][z + 1].rgbtBlue;

                px[1][1] = copy[y - 1][z].rgbtGreen;
                px[1][2] = copy[y - 1][z + 1].rgbtGreen;
                px[1][4] = copy[y][z].rgbtGreen;
                px[1][5] = copy[y][z + 1].rgbtGreen;
                px[1][7] = copy[y + 1][z].rgbtGreen;
                px[1][8] = copy[y + 1][z + 1].rgbtGreen;

                px[2][1] = copy[y - 1][z].rgbtRed;
                px[2][2] = copy[y - 1][z + 1].rgbtRed;
                px[2][4] = copy[y][z].rgbtRed;
                px[2][5] = copy[y][z + 1].rgbtRed;
                px[2][7] = copy[y + 1][z].rgbtRed;
                px[2][8] = copy[y + 1][z + 1].rgbtRed;

                float avgBlue = (px[0][1] + px[0][2] + px[0][4] +
                                 px[0][5] + px[0][7] + px[0][8]) / 6;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1][1] + px[1][2] + px[1][4] +
                                  px[1][5] + px[1][7] + px[1][8]) / 6;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[2][1] + px[2][2] + px[2][4] +
                                px[2][5] + px[2][7] + px[2][8]) / 6;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Right edge
            else if (y != 0 && y < (height - 1) && z == (width - 1))
            {
                px[0][0] = copy[y - 1][z - 1].rgbtBlue;
                px[0][1] = copy[y - 1][z].rgbtBlue;
                px[0][3] = copy[y][z - 1].rgbtBlue;
                px[0][4] = copy[y][z].rgbtBlue;
                px[0][6] = copy[y + 1][z - 1].rgbtBlue;
                px[0][7] = copy[y + 1][z].rgbtBlue;

                px[1][0] = copy[y - 1][z - 1].rgbtGreen;
                px[1][1] = copy[y - 1][z].rgbtGreen;
                px[1][3] = copy[y][z - 1].rgbtGreen;
                px[1][4] = copy[y][z].rgbtGreen;
                px[1][6] = copy[y + 1][z - 1].rgbtGreen;
                px[1][7] = copy[y + 1][z].rgbtGreen;

                px[2][0] = copy[y - 1][z - 1].rgbtRed;
                px[2][1] = copy[y - 1][z].rgbtRed;
                px[2][3] = copy[y][z - 1].rgbtRed;
                px[2][4] = copy[y][z].rgbtRed;
                px[2][6] = copy[y + 1][z - 1].rgbtRed;
                px[2][7] = copy[y + 1][z].rgbtRed;

                float avgBlue = (px[0][0] + px[0][1] + px[0][3] +
                                 px[0][4] + px[0][6] + px[0][7]) / 6;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1][0] + px[1][1] + px[1][3] +
                                  px[1][4] + px[1][6] + px[1][7]) / 6;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[2][0] + px[2][1] + px[2][3] +
                                px[2][4] + px[2][6] + px[2][7]) / 6;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Bottom left corner
            else if (y == (height - 1) && z == 0)
            {
                px[0][1] = copy[y - 1][z].rgbtBlue;
                px[0][2] = copy[y - 1][z + 1].rgbtBlue;
                px[0][4] = copy[y][z].rgbtBlue;
                px[0][5] = copy[y][z + 1].rgbtBlue;

                px[1][1] = copy[y - 1][z].rgbtGreen;
                px[1][2] = copy[y - 1][z + 1].rgbtGreen;
                px[1][4] = copy[y][z].rgbtGreen;
                px[1][5] = copy[y][z + 1].rgbtGreen;

                px[2][1] = copy[y - 1][z].rgbtRed;
                px[2][2] = copy[y - 1][z + 1].rgbtRed;
                px[2][4] = copy[y][z].rgbtRed;
                px[2][5] = copy[y][z + 1].rgbtRed;

                float avgBlue = (px[0][1] + px[0][2] + px[0][4] +
                                 px[0][5]) / 4;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1][1] + px[1][2] + px[1][4] +
                                  px[1][5]) / 4;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[2][1] + px[2][2] + px[2][4] +
                                px[2][5]) / 4;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Bottom edge
            else if (y == (height - 1) && z != 0 && z < (width - 1))
            {
                px[0][0] = copy[y - 1][z - 1].rgbtBlue;
                px[0][1] = copy[y - 1][z].rgbtBlue;
                px[0][2] = copy[y - 1][z + 1].rgbtBlue;
                px[0][3] = copy[y][z - 1].rgbtBlue;
                px[0][4] = copy[y][z].rgbtBlue;
                px[0][5] = copy[y][z + 1].rgbtBlue;

                px[1][0] = copy[y - 1][z - 1].rgbtGreen;
                px[1][1] = copy[y - 1][z].rgbtGreen;
                px[1][2] = copy[y - 1][z + 1].rgbtGreen;
                px[1][3] = copy[y][z - 1].rgbtGreen;
                px[1][4] = copy[y][z].rgbtGreen;
                px[1][5] = copy[y][z + 1].rgbtGreen;

                px[2][0] = copy[y - 1][z - 1].rgbtRed;
                px[2][1] = copy[y - 1][z].rgbtRed;
                px[2][2] = copy[y - 1][z + 1].rgbtRed;
                px[2][3] = copy[y][z - 1].rgbtRed;
                px[2][4] = copy[y][z].rgbtRed;
                px[2][5] = copy[y][z + 1].rgbtRed;

                float avgBlue = (px[0][0] + px[0][1] + px[0][2] +
                                 px[0][3] + px[0][4] + px[0][5]) / 6;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1][0] + px[1][1] + px[1][2] +
                                  px[1][3] + px[1][4] + px[1][5]) / 6;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[2][0] + px[2][1] + px[2][2] +
                                px[2][3] + px[2][4] + px[2][5]) / 6;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Bottom right corner
            else if (y == (height - 1) && z == (width - 1))
            {
                px[0][0] = copy[y - 1][z - 1].rgbtBlue;
                px[0][1] = copy[y - 1][z].rgbtBlue;
                px[0][3] = copy[y][z - 1].rgbtBlue;
                px[0][4] = copy[y][z].rgbtBlue;

                px[1][0] = copy[y - 1][z - 1].rgbtGreen;
                px[1][1] = copy[y - 1][z].rgbtGreen;
                px[1][3] = copy[y][z - 1].rgbtGreen;
                px[1][4] = copy[y][z].rgbtGreen;

                px[2][0] = copy[y - 1][z - 1].rgbtRed;
                px[2][1] = copy[y - 1][z].rgbtRed;
                px[2][3] = copy[y][z - 1].rgbtRed;
                px[2][4] = copy[y][z].rgbtRed;

                float avgBlue = (px[0][0] + px[0][1] + px[0][3] +
                                 px[0][4]) / 4;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1][0] + px[1][1] + px[1][3] +
                                  px[1][4]) / 4;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[2][0] + px[2][1] + px[2][3] +
                                px[2][4]) / 4;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }
        }
    }

    return;
}