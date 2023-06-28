 // Upper row
            if (y == 0)
            {
                h = copy[y + 1][z];
                // Left
                if (z == 0)
                {
                    f = copy[y][z + 1];
                    i = copy[y + 1][z + 1];

                    // Calculate averages
                    float avgBlue = (e.rgbtBlue + f.rgbtBlue + h.rgbtBlue + i.rgbtBlue) / 4;
                    float aB = roundf(avgBlue);
                    int newBlue = (int)aB;

                    float avgGreen = (e.rgbtGreen + f.rgbtGreen + h.rgbtGreen + i.rgbtGreen) / 4;
                    float aG = roundf(avgGreen);
                    int newGreen = (int)aG;

                    float avgRed = (e.rgbtRed + f.rgbtRed + h.rgbtRed + i.rgbtRed) / 4;
                    float aR = roundf(avgRed);
                    int newRed = (int)aR;

                    // Update pixel values
                    image[y][z].rgbtBlue = newBlue;
                    image[y][z].rgbtGreen = newGreen;
                    image[y][z].rgbtRed = newRed;
                }
                // Right
                else if (z == (width - 1))
                {
                    // Surrounding pixels
                    d = copy[y][z - 1];
                    g = copy[y + 1][z - 1];

                    // Calculate averages
                    float avgBlue = (d.rgbtBlue + e.rgbtBlue + g.rgbtBlue + h.rgbtBlue) / 4;
                    float aB = roundf(avgBlue);
                    int newBlue = (int)aB;

                    float avgGreen = (d.rgbtGreen + e.rgbtGreen + g.rgbtGreen + h.rgbtGreen) / 4;
                    float aG = roundf(avgGreen);
                    int newGreen = (int)aG;

                    float avgRed = (d.rgbtRed + e.rgbtRed + g.rgbtRed + h.rgbtRed) / 4;
                    float aR = roundf(avgRed);
                    int newRed = (int)aR;

                    // Update pixel values
                    image[y][z].rgbtBlue = newBlue;
                    image[y][z].rgbtGreen = newGreen;
                    image[y][z].rgbtRed = newRed;
                }
                // Middle
                else
                {
                    f = copy[y][z + 1];
                    i = copy[y + 1][z + 1];
                    d = copy[y][z - 1];
                    g = copy[y + 1][z - 1];

                     // Calculate averages
                    float avgBlue = (d.rgbtBlue + e.rgbtBlue + f.rgbtBlue +
                    g.rgbtBlue + h.rgbtBlue + i.rgbtBlue) / 6;
                    float aB = roundf(avgBlue);
                    int newBlue = (int)aB;

                    float avgGreen = (d.rgbtGreen + e.rgbtGreen + f.rgbtGreen +
                    g.rgbtGreen + h.rgbtGreen + i.rgbtGreen) / 6;
                    float aG = roundf(avgGreen);
                    int newGreen = (int)aG;

                    float avgRed = (d.rgbtRed + e.rgbtRed + f.rgbtRed +
                    g.rgbtRed + h.rgbtRed + i.rgbtRed) / 6;
                    float aR = roundf(avgRed);
                    int newRed = (int)aR;

                    // Update pixel values
                    image[y][z].rgbtBlue = newBlue;
                    image[y][z].rgbtGreen = newGreen;
                    image[y][z].rgbtRed = newRed;
                }
            }
            // Left column
            else if (z == 0 && y != 0)
            {
                f = copy[y][z + 1];

                // Bottom
                if (y == (height - 1))
                {
                    b = copy[y - 1][z];
                    c = copy[y - 1][z + 1];

                    // Calculate averages
                    float avgBlue = (b.rgbtBlue + c.rgbtBlue + e.rgbtBlue + f.rgbtBlue) / 4;
                    float aB = roundf(avgBlue);
                    int newBlue = (int)aB;

                    float avgGreen = (b.rgbtGreen + c.rgbtGreen + e.rgbtGreen + f.rgbtGreen) / 4;
                    float aG = roundf(avgGreen);
                    int newGreen = (int)aG;

                    float avgRed = (b.rgbtRed + c.rgbtRed + e.rgbtRed + f.rgbtRed) / 4;
                    float aR = roundf(avgRed);
                    int newRed = (int)aR;

                    // Update pixel values
                    image[y][z].rgbtBlue = newBlue;
                    image[y][z].rgbtGreen = newGreen;
                    image[y][z].rgbtRed = newRed;
                }
                // Middle
                else
                {
                    // Surrounding pixels
                    b = copy[y - 1][z];
                    c = copy[y - 1][z + 1];
                    h = copy[y + 1][z];
                    i = copy[y + 1][z + 1];

                    // Calculate averages
                    float avgBlue = (b.rgbtBlue + c.rgbtBlue + e.rgbtBlue +
                    f.rgbtBlue + h.rgbtBlue + i.rgbtBlue) / 6;
                    float aB = roundf(avgBlue);
                    int newBlue = (int)aB;

                    float avgGreen = (b.rgbtGreen + c.rgbtGreen + e.rgbtGreen +
                    f.rgbtGreen + h.rgbtGreen + i.rgbtGreen) / 6;
                    float aG = roundf(avgGreen);
                    int newGreen = (int)aG;

                    float avgRed = (b.rgbtRed + c.rgbtRed + e.rgbtRed +
                    f.rgbtRed + h.rgbtRed + i.rgbtRed) / 6;
                    float aR = roundf(avgRed);
                    int newRed = (int)aR;

                    // Update pixel values
                    image[y][z].rgbtBlue = newBlue;
                    image[y][z].rgbtGreen = newGreen;
                    image[y][z].rgbtRed = newRed;
                }
            }
            // Right column
            else if (y != 0 && z == (width - 1))
            {
                d = copy[y][z - 1];

                // Bottom
                if (y == (height - 1))
                {
                    a = copy[y - 1][z - 1];
                    b = copy[y - 1][z];

                    // Calculate averages
                    float avgBlue = (a.rgbtBlue + b.rgbtBlue + d.rgbtBlue + e.rgbtBlue) / 4;
                    float aB = roundf(avgBlue);
                    int newBlue = (int)aB;

                    float avgGreen = (a.rgbtGreen + b.rgbtGreen + d.rgbtGreen + e.rgbtGreen) / 4;
                    float aG = roundf(avgGreen);
                    int newGreen = (int)aG;

                    float avgRed = (a.rgbtRed + b.rgbtRed + d.rgbtRed + e.rgbtRed) / 4;
                    float aR = roundf(avgRed);
                    int newRed = (int)aR;

                    // Update pixel values
                    image[y][z].rgbtBlue = newBlue;
                    image[y][z].rgbtGreen = newGreen;
                    image[y][z].rgbtRed = newRed;
                }
                // Middle
                else
                {
                    // Surrounding pixels
                    a = copy[y - 1][z - 1];
                    b = copy[y - 1][z];
                    g = copy[y + 1][z - 1];
                    h = copy[y + 1][z];

                    // Calculate averages
                    float avgBlue = (a.rgbtBlue + b.rgbtBlue + d.rgbtBlue +
                    e.rgbtBlue + g.rgbtBlue + h.rgbtBlue) / 6;
                    float aB = roundf(avgBlue);
                    int newBlue = (int)aB;

                    float avgGreen = (a.rgbtGreen + b.rgbtGreen + d.rgbtGreen +
                    e.rgbtGreen + g.rgbtGreen + h.rgbtGreen) / 6;
                    float aG = roundf(avgGreen);
                    int newGreen = (int)aG;

                    float avgRed = (a.rgbtRed + b.rgbtRed + d.rgbtRed +
                    e.rgbtRed + g.rgbtRed + h.rgbtRed) / 6;
                    float aR = roundf(avgRed);
                    int newRed = (int)aR;

                    // Update pixel values
                    image[y][z].rgbtBlue = newBlue;
                    image[y][z].rgbtGreen = newGreen;
                    image[y][z].rgbtRed = newRed;
                }
            }
            // Lower row
            else if (y == (height - 1) && z != 0 && z != (width - 1))
            {
                a = copy[y - 1][z - 1];
                b = copy[y - 1][z];
                c = copy[y - 1][z + 1];
                d = copy[y][z - 1];
                f = copy[y][z + 1];

                // Calculate averages
                float avgBlue = (a.rgbtBlue + b.rgbtBlue + c.rgbtBlue +
                d.rgbtBlue + e.rgbtBlue + f.rgbtBlue) / 6;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (a.rgbtGreen + b.rgbtGreen + c.rgbtGreen +
                d.rgbtGreen + e.rgbtGreen + f.rgbtGreen) / 6;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (a.rgbtRed + b.rgbtRed + c.rgbtRed +
                d.rgbtRed + e.rgbtRed + f.rgbtRed) / 6;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                // Update pixel values
                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }
            // Rest of image
            else
            {
                // Surrounding pixels
                a = copy[y - 1][z - 1];
                b = copy[y - 1][z];
                c = copy[y - 1][z + 1];
                d = copy[y][z - 1];
                f = copy[y][z + 1];
                g = copy[y + 1][z - 1];
                h = copy[y + 1][z];
                i = copy[y + 1][z + 1];

                // Calculate averages
                float avgBlue = (a.rgbtBlue + b.rgbtBlue + c.rgbtBlue +
                d.rgbtBlue + e.rgbtBlue + f.rgbtBlue + g.rgbtBlue +
                h.rgbtBlue + i.rgbtBlue) / 9;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (a.rgbtGreen + b.rgbtGreen + c.rgbtGreen +
                d.rgbtGreen + e.rgbtGreen + f.rgbtGreen + g.rgbtGreen +
                h.rgbtGreen + i.rgbtGreen) / 9;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (a.rgbtRed + b.rgbtRed + c.rgbtRed +
                d.rgbtRed + e.rgbtRed + f.rgbtRed + g.rgbtRed +
                h.rgbtRed + i.rgbtRed) / 9;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                // Update pixel values
                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }
        }
    }
    return;
}

/*



*/

// Left top corner
            if (y == 0 && z == 0)
            {
                px[4] = copy[y][z];
                px[5] = copy[y][z + 1];
                px[7] = copy[y + 1][z];
                px[8] = copy[y + 1][z + 1];

                float avgBlue = (px[4].rgbtBlue + px[5].rgbtBlue + px[7].rgbtBlue +
                    px[8].rgbtBlue) / 4;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[4].rgbtGreen + px[5].rgbtGreen + px[7].rgbtGreen +
                    px[8].rgbtGreen) / 4;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[4].rgbtRed + px[5].rgbtRed + px[7].rgbtRed +
                    px[8].rgbtRed) / 4;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Top edge
            else if (y == 0 && z != 0 && z > (width - 1))
            {
                px[3] = copy[y][z - 1];
                px[4] = copy[y][z];
                px[5] = copy[y][z + 1];
                px[6] = copy[y + 1][z - 1];
                px[7] = copy[y + 1][z];
                px[8] = copy[y + 1][z + 1];

                float avgBlue = (px[3].rgbtBlue + px[4].rgbtBlue + px[5].rgbtBlue +
                    px[6].rgbtBlue + px[7].rgbtBlue + px[8].rgbtBlue) / 6;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[3].rgbtGreen + px[4].rgbtGreen + px[5].rgbtGreen +
                    px[6].rgbtGreen + px[7].rgbtGreen + px[8].rgbtGreen) / 6;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[3].rgbtRed + px[4].rgbtRed + px[5].rgbtRed +
                    px[6].rgbtRed + px[7].rgbtGreen + px[8].rgbtGreen) / 6;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Right top corner
            else if (y == 0 && z == (width - 1))
            {
                px[3] = copy[y][z - 1];
                px[4] = copy[y][z];
                px[6] = copy[y + 1][z - 1];
                px[7] = copy[y + 1][z];

                float avgBlue = (px[3].rgbtBlue + px[4].rgbtBlue + px[6].rgbtBlue +
                    px[7].rgbtBlue) / 4;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[3].rgbtGreen + px[4].rgbtGreen + px[6].rgbtGreen +
                    px[7].rgbtGreen) / 4;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[3].rgbtRed + px[4].rgbtRed + px[6].rgbtRed +
                    px[7].rgbtRed) / 4;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Left edge
            else if (y == 0 && z != 0 && z < (width - 1))
            {
                px[1] = copy[y - 1][z];
                px[2] = copy[y - 1][z + 1];
                px[4] = copy[y][z];
                px[5] = copy[y][z + 1];
                px[7] = copy[y + 1][z];
                px[8] = copy[y + 1][z + 1];

                float avgBlue = (px[1].rgbtBlue + px[2].rgbtBlue + px[4].rgbtBlue +
                    px[5].rgbtBlue + px[7].rgbtBlue + px[8].rgbtBlue) / 6;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1].rgbtGreen + px[2].rgbtGreen + px[4].rgbtGreen +
                    px[5].rgbtGreen + px[7].rgbtGreen + px[8].rgbtGreen) / 6;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[1].rgbtRed + px[2].rgbtRed + px[4].rgbtRed +
                    px[5].rgbtRed + px[7].rgbtGreen + px[8].rgbtGreen) / 6;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Right edge
            else if (y != 0 && y < (height - 1) && z == (width - 1))
            {
                px[0] = copy[y - 1][z - 1];
                px[1] = copy[y - 1][z];
                px[3] = copy[y][z - 1];
                px[4] = copy[y][z];
                px[6] = copy[y + 1][z - 1];
                px[7] = copy[y + 1][z];

                float avgBlue = (px[0].rgbtBlue + px[1].rgbtBlue + px[3].rgbtBlue +
                    px[4].rgbtBlue + px[6].rgbtBlue + px[7].rgbtBlue) / 6;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[0].rgbtGreen + px[1].rgbtGreen + px[3].rgbtGreen +
                    px[4].rgbtGreen + px[6].rgbtGreen + px[7].rgbtGreen) / 6;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[0].rgbtRed + px[1].rgbtRed + px[3].rgbtRed +
                    px[4].rgbtRed + px[6].rgbtGreen + px[7].rgbtGreen) / 6;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Bottom left corner
            else if (y == (height - 1) && z == 0)
            {
                px[1] = copy[y - 1][z];
                px[2] = copy[y - 1][z + 1];
                px[4] = copy[y][z];
                px[5] = copy[y][z + 1];

                float avgBlue = (px[1].rgbtBlue + px[2].rgbtBlue + px[4].rgbtBlue +
                    px[5].rgbtBlue) / 4;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[1].rgbtGreen + px[2].rgbtGreen + px[4].rgbtGreen +
                    px[5].rgbtGreen) / 4;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[1].rgbtRed + px[2].rgbtRed + px[4].rgbtRed +
                    px[5].rgbtRed) / 4;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Bottom edge
            else if (y == (height - 1) && z != 0 && z < (width - 1))
            {
                px[0] = copy[y - 1][z - 1];
                px[1] = copy[y - 1][z];
                px[2] = copy[y - 1][z + 1];
                px[3] = copy[y][z - 1];
                px[4] = copy[y][z];
                px[5] = copy[y][z + 1];

                float avgBlue = (px[0].rgbtBlue + px[1].rgbtBlue + px[2].rgbtBlue +
                    px[3].rgbtBlue + px[4].rgbtBlue + px[5].rgbtBlue) / 6;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[0].rgbtGreen + px[1].rgbtGreen + px[2].rgbtGreen +
                    px[3].rgbtGreen + px[4].rgbtGreen + px[5].rgbtGreen) / 6;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[0].rgbtRed + px[1].rgbtRed + px[2].rgbtRed +
                    px[3].rgbtRed + px[4].rgbtGreen + px[5].rgbtGreen) / 6;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }

            // Bottom right corner
            else if (y == (height - 1) && z == (width - 1))
            {
                px[0] = copy[y - 1][z - 1];
                px[1] = copy[y - 1][z];
                px[3] = copy[y][z - 1];
                px[4] = copy[y][z];

                float avgBlue = (px[0].rgbtBlue + px[1].rgbtBlue + px[3].rgbtBlue +
                    px[4].rgbtBlue) / 4;
                float aB = roundf(avgBlue);
                int newBlue = (int)aB;

                float avgGreen = (px[0].rgbtGreen + px[1].rgbtGreen + px[3].rgbtGreen +
                    px[4].rgbtGreen) / 4;
                float aG = roundf(avgGreen);
                int newGreen = (int)aG;

                float avgRed = (px[0].rgbtRed + px[1].rgbtRed + px[3].rgbtRed +
                    px[4].rgbtRed) / 4;
                float aR = roundf(avgRed);
                int newRed = (int)aR;

                image[y][z].rgbtBlue = newBlue;
                image[y][z].rgbtGreen = newGreen;
                image[y][z].rgbtRed = newRed;
            }
        }
    }


    for (int y = 0; y < height; y++)
    {
        for (int z = 0; z < width; z++)
        {
            if (y != 0 && y < (height - 1) && z != 0 && z < (width - 1))
            {
                pxB[0] = copy[y - 1][z - 1].rgbtBlue;
                pxB[1] = copy[y - 1][z].rgbtBlue;
                pxB[2] = copy[y - 1][z + 1].rgbtBlue;
                pxB[3] = copy[y][z - 1].rgbtBlue;
                pxB[4] = copy[y][z].rgbtBlue;
                pxB[5] = copy[y][z + 1].rgbtBlue;
                pxB[6] = copy[y + 1][z - 1].rgbtBlue;
                pxB[7] = copy[y + 1][z].rgbtBlue;
                pxB[8] = copy[y + 1][z + 1].rgbtBlue;

                pxG[0] = copy[y - 1][z - 1].rgbtGreen;
                pxG[1] = copy[y - 1][z].rgbtGreen;
                pxG[2] = copy[y - 1][z + 1].rgbtGreen;
                pxG[3] = copy[y][z - 1].rgbtGreen;
                pxG[4] = copy[y][z].rgbtGreen;
                pxG[5] = copy[y][z + 1].rgbtBlue;
                pxG[6] = copy[y + 1][z - 1].rgbtBlue;
                pxG[7] = copy[y + 1][z].rgbtBlue;
                pxG[8] = copy[y + 1][z + 1].rgbtBlue;
                // Regular pixels
            if (y != 0 && y < (height - 1) && z != 0 && z < (width - 1))
            {
                // Vertical
                px[0][0] = copy[y - 1][z - 1].rgbtBlue * -1;
                px[0][1] = 0;
                px[0][2] = copy[y - 1][z + 1].rgbtBlue;
                px[0][3] = copy[y][z - 1].rgbtBlue * -2;
                px[0][4] = 0;
                px[0][5] = copy[y][z + 1].rgbtBlue * 2;
                px[0][6] = copy[y + 1][z - 1].rgbtBlue * -1;
                px[0][7] = 0;
                px[0][8] = copy[y + 1][z + 1].rgbtBlue;

                px[1][0] = copy[y - 1][z - 1].rgbtGreen * -1;
                px[1][1] = 0;
                px[1][2] = copy[y - 1][z + 1].rgbtGreen;
                px[1][3] = copy[y][z - 1].rgbtGreen * -2;
                px[1][4] = 0;
                px[1][5] = copy[y][z + 1].rgbtGreen * 2;
                px[1][6] = copy[y + 1][z - 1].rgbtGreen * -1;
                px[1][7] = 0;
                px[1][8] = copy[y + 1][z + 1].rgbtGreen;

                px[2][0] = copy[y - 1][z - 1].rgbtRed * -1;
                px[2][1] = 0;
                px[2][2] = copy[y - 1][z + 1].rgbtRed;
                px[2][3] = copy[y][z - 1].rgbtRed * -2;
                px[2][4] = 0;
                px[2][5] = copy[y][z + 1].rgbtRed * 2;
                px[2][6] = copy[y + 1][z - 1].rgbtRed * -1;
                px[2][7] = 0;
                px[2][8] = copy[y + 1][z + 1].rgbtRed;

                // Horizontal
                py[0][0] = copy[y - 1][z - 1].rgbtBlue * -1;
                py[0][1] = copy[y - 1][z].rgbtBlue * -2;
                py[0][2] = copy[y - 1][z + 1].rgbtBlue * -1;
                py[0][3] = 0;
                py[0][4] = 0;
                py[0][5] = 0;
                py[0][6] = copy[y + 1][z - 1].rgbtBlue;
                py[0][7] = copy[y + 1][z].rgbtBlue * 2;
                py[0][8] = copy[y + 1][z + 1].rgbtBlue;

                py[1][0] = copy[y - 1][z - 1].rgbtGreen * -1;
                py[1][1] = copy[y - 1][z].rgbtGreen * -2;
                py[1][2] = copy[y - 1][z + 1].rgbtGreen * -1;
                py[1][3] = 0;
                py[1][4] = 0;
                py[1][5] = 0;
                py[1][6] = copy[y + 1][z - 1].rgbtGreen;
                py[1][7] = copy[y + 1][z].rgbtGreen * 2;
                py[1][8] = copy[y + 1][z + 1].rgbtGreen;

                py[2][0] = copy[y - 1][z - 1].rgbtRed * -1;
                py[2][1] = copy[y - 1][z].rgbtRed * -2;
                py[2][2] = copy[y - 1][z + 1].rgbtRed * -1;
                py[2][3] = 0;
                py[2][4] = 0;
                py[2][5] = 0;
                py[2][6] = copy[y + 1][z - 1].rgbtRed;
                py[2][7] = copy[y + 1][z].rgbtRed * 2;
                py[2][8] = copy[y + 1][z + 1].rgbtRed;
            }

            // Left top corner
            else if (y == 0 && z == 0)
            {
                // Vertical
                px[0][4] = 0;
                px[0][5] = copy[y][z + 1].rgbtBlue * 2;
                px[0][7] = 0;
                px[0][8] = copy[y + 1][z + 1].rgbtBlue;

                px[1][4] = 0;
                px[1][5] = copy[y][z + 1].rgbtGreen * 2;
                px[1][7] = 0;
                px[1][8] = copy[y + 1][z + 1].rgbtGreen;

                px[2][4] = 0;
                px[2][5] = copy[y][z + 1].rgbtRed * 2;
                px[2][7] = 0;
                px[2][8] = copy[y + 1][z + 1].rgbtRed;

                // Horizontal
                py[0][4] = 0;
                py[0][5] = 0;
                py[0][7] = copy[y + 1][z].rgbtBlue * 2;
                py[0][8] = copy[y + 1][z + 1].rgbtBlue;

                py[1][4] = 0;
                py[1][5] = 0;
                py[1][7] = copy[y + 1][z].rgbtGreen * 2;
                py[1][8] = copy[y + 1][z + 1].rgbtGreen;

                py[2][4] = 0;
                py[2][5] = 0;
                py[2][7] = copy[y + 1][z].rgbtRed * 2;
                py[2][8] = copy[y + 1][z + 1].rgbtRed;
            }

            // Top edge
            else if (y == 0 && z != 0 && z < (width - 1))
            {
                // Vertical
                px[0][3] = copy[y][z - 1].rgbtBlue * -2;
                px[0][4] = 0;
                px[0][5] = copy[y][z + 1].rgbtBlue * 2;
                px[0][6] = copy[y + 1][z - 1].rgbtBlue * -1;
                px[0][7] = 0;
                px[0][8] = copy[y + 1][z + 1].rgbtBlue;

                px[1][3] = copy[y][z - 1].rgbtGreen * -2;
                px[1][4] = 0;
                px[1][5] = copy[y][z + 1].rgbtGreen * 2;
                px[1][6] = copy[y + 1][z - 1].rgbtGreen * -1;
                px[1][7] = 0;
                px[1][8] = copy[y + 1][z + 1].rgbtGreen;

                px[2][3] = copy[y][z - 1].rgbtRed * -2;
                px[2][4] = 0;
                px[2][5] = copy[y][z + 1].rgbtRed * 2;
                px[2][6] = copy[y + 1][z - 1].rgbtRed * -1;
                px[2][7] = 0;
                px[2][8] = copy[y + 1][z + 1].rgbtRed;

                // Horizontal
                py[0][3] = 0;
                py[0][4] = 0;
                py[0][5] = 0;
                py[0][6] = copy[y + 1][z - 1].rgbtBlue;
                py[0][7] = copy[y + 1][z].rgbtBlue * 2;
                py[0][8] = copy[y + 1][z + 1].rgbtBlue;

                py[1][3] = 0;
                py[1][4] = 0;
                py[1][5] = 0;
                py[1][6] = copy[y + 1][z - 1].rgbtGreen;
                py[1][7] = copy[y + 1][z].rgbtGreen * 2;
                py[1][8] = copy[y + 1][z + 1].rgbtGreen;

                py[1][3] = 0;
                py[1][4] = 0;
                py[1][5] = 0;
                py[1][6] = copy[y + 1][z - 1].rgbtRed;
                py[1][7] = copy[y + 1][z].rgbtRed * 2;
                py[1][8] = copy[y + 1][z + 1].rgbtRed;
            }

            // Right top corner
            else if (y == 0 && z == (width - 1))
            {
                // Vertical
                px[0][3] = copy[y][z - 1].rgbtBlue * -2;
                px[0][4] = 0;
                px[0][6] = copy[y + 1][z - 1].rgbtBlue * -1;
                px[0][7] = 0;

                px[1][3] = copy[y][z - 1].rgbtGreen * -2;
                px[1][4] = 0;
                px[1][6] = copy[y + 1][z - 1].rgbtGreen * -1;
                px[1][7] = 0;

                px[0][3] = copy[y][z - 1].rgbtBlue * -2;
                px[0][4] = 0;
                px[0][6] = copy[y + 1][z - 1].rgbtBlue * -1;
                px[0][7] = 0;

                // Horizontal
            }

            // Left edge
            else if (y != 0 && y < (height - 1) && z == 0)
            {
                px[0][1] = 0;
                px[0][2] = copy[y - 1][z + 1].rgbtBlue;
                px[0][4] = 0;
                px[0][5] = copy[y][z + 1].rgbtBlue * 2;
                px[0][7] = 0;
                px[0][8] = copy[y + 1][z + 1].rgbtBlue;

                px[1][1] = 0;
                px[1][2] = copy[y - 1][z + 1].rgbtGreen;
                px[1][4] = 0;
                px[1][5] = copy[y][z + 1].rgbtGreen * 2;
                px[1][7] = 0;
                px[1][8] = copy[y + 1][z + 1].rgbtGreen;

                px[2][1] = 0;
                px[2][2] = copy[y - 1][z + 1].rgbtRed;
                px[2][4] = 0;
                px[2][5] = copy[y][z + 1].rgbtRed * 2;
                px[2][7] = 0;
                px[2][8] = copy[y + 1][z + 1].rgbtRed;
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
