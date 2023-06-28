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

// Convert image to black and white
void blackwhite(int height, int width, RGBTRIPLE image[height][width])
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
            if (gray < 128)
            {
                image[h][w].rgbtBlue = 221;
                image[h][w].rgbtGreen = 150;
                image[h][w].rgbtRed = 48;
            }
            else
            {
                image[h][w].rgbtBlue = 35;
                image[h][w].rgbtGreen = 178;
                image[h][w].rgbtRed = 198;
            }
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory for a copy of the image
    RGBTRIPLE copy[height][width];
    float px[3][9];
    float py[3][9];

    for (int k = 0; k < height; k++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[k][j].rgbtBlue = image[k][j].rgbtBlue;
            copy[k][j].rgbtGreen = image[k][j].rgbtGreen;
            copy[k][j].rgbtRed = image[k][j].rgbtRed;
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int z = 0; z < width; z++)
        {
            // Set all pixels (3x3) to black
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 9; b++)
                {
                    px[a][b] = 0;
                    py[a][b] = 0;
                }
            }

            // Not top edge
            if (y != 0)
            {
                // Justo el de arriba px[x][1]
                py[0][1] = copy[y - 1][z].rgbtBlue * -2;
                py[1][1] = copy[y - 1][z].rgbtGreen * -2;
                py[2][1] = copy[y - 1][z].rgbtRed * -2;

                // Not left edge
                if (z != 0)
                {
                    px[0][0] = copy[y - 1][z - 1].rgbtBlue * -1;
                    px[1][0] = copy[y - 1][z - 1].rgbtGreen * -1;
                    px[2][0] = copy[y - 1][z - 1].rgbtRed * -1;

                    py[0][0] = copy[y - 1][z - 1].rgbtBlue * -1;
                    py[1][0] = copy[y - 1][z - 1].rgbtGreen * -1;
                    py[2][0] = copy[y - 1][z - 1].rgbtRed * -1;
                }

                // Not right edge
                if (z < (width - 1))
                {
                    px[0][2] = copy[y - 1][z + 1].rgbtBlue;
                    px[1][2] = copy[y - 1][z + 1].rgbtGreen;
                    px[2][2] = copy[y - 1][z + 1].rgbtRed;

                    py[0][2] = copy[y - 1][z + 1].rgbtBlue * -1;
                    py[1][2] = copy[y - 1][z + 1].rgbtGreen * -1;
                    py[2][2] = copy[y - 1][z + 1].rgbtRed * -1;
                }
            }

            // Not bottom edge
            if (y < (height - 1))
            {
                py[0][7] = copy[y + 1][z].rgbtBlue * 2;
                py[1][7] = copy[y + 1][z].rgbtGreen * 2;
                py[2][7] = copy[y + 1][z].rgbtRed * 2;

                // Not left edge
                if (z != 0)
                {
                    px[0][6] = copy[y + 1][z - 1].rgbtBlue * -1;
                    px[1][6] = copy[y + 1][z - 1].rgbtGreen * -1;
                    px[2][6] = copy[y + 1][z - 1].rgbtRed * -1;

                    py[0][6] = copy[y + 1][z - 1].rgbtBlue;
                    py[1][6] = copy[y + 1][z - 1].rgbtGreen;
                    py[2][6] = copy[y + 1][z - 1].rgbtRed;
                }

                // Not right edge
                if (z < (width - 1))
                {
                    px[0][8] = copy[y + 1][z + 1].rgbtBlue;
                    px[1][8] = copy[y + 1][z + 1].rgbtGreen;
                    px[2][8] = copy[y + 1][z + 1].rgbtRed;

                    py[0][8] = copy[y + 1][z + 1].rgbtBlue;
                    py[1][8] = copy[y + 1][z + 1].rgbtGreen;
                    py[2][8] = copy[y + 1][z + 1].rgbtRed;
                }
            }

            // Not left egde
            if (z != 0)
            {
                px[0][3] = copy[y][z - 1].rgbtBlue * -2;
                px[1][3] = copy[y][z - 1].rgbtGreen * -2;
                px[2][3] = copy[y][z - 1].rgbtRed * -2;
            }

            // Not right edge
            if (z < (width - 1))
            {
                px[0][5] = copy[y][z + 1].rgbtBlue * 2;
                px[1][5] = copy[y][z + 1].rgbtGreen * 2;
                px[2][5] = copy[y][z + 1].rgbtRed * 2;
            }

            // Copmute weughted sum
            //Vertical
            float wsBlue_x = pow((px[0][0] + px[0][1] + px[0][2] +
                                  px[0][3] + px[0][4] + px[0][5] +
                                  px[0][6] + px[0][7] + px[0][8]), 2);

            float wsGreen_x = pow((px[1][0] + px[1][1] + px[1][2] +
                                   px[1][3] + px[1][4] + px[1][5] +
                                   px[1][6] + px[1][7] + px[1][8]), 2);

            float wsRed_x = pow((px[2][0] + px[2][1] + px[2][2] +
                                 px[2][3] + px[2][4] + px[2][5] +
                                 px[2][6] + px[2][7] + px[2][8]), 2);

            // Horizontal
            float wsBlue_y = pow((py[0][0] + py[0][1] + py[0][2] +
                                  py[0][3] + py[0][4] + py[0][5] +
                                  py[0][6] + py[0][7] + py[0][8]), 2);

            float wsGreen_y = pow((py[1][0] + py[1][1] + py[1][2] +
                                   py[1][3] + py[1][4] + py[1][5] +
                                   py[1][6] + py[1][7] + py[1][8]), 2);

            float wsRed_y = pow((py[2][0] + py[2][1] + py[2][2] +
                                 py[2][3] + py[2][4] + py[2][5] +
                                 py[2][6] + py[2][7] + py[2][8]), 2);

            // Operator
            float sobelBlue = sqrtf(wsBlue_x + wsBlue_y);
            float aB = roundf(sobelBlue);
            int newBlue = (int)aB;
            if (newBlue > 255)
            {
                newBlue = 255;
            }

            float sobelGreen = sqrtf(wsGreen_x + wsGreen_y);
            float aG = roundf(sobelGreen);
            int newGreen = (int)aG;
            if (newGreen > 255)
            {
                newGreen = 255;
            }

            float sobelRed = sqrtf(wsRed_x + wsRed_y);
            float aR = roundf(sobelRed);
            int newRed = (int)aR;
            if (newRed > 255)
            {
                newRed = 255;
            }

            // Update color values
            image[y][z].rgbtBlue = newBlue;
            image[y][z].rgbtGreen = newGreen;
            image[y][z].rgbtRed = newRed;
        }
    }
    return;
}
