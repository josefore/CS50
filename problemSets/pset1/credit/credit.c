#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long number = get_long("Number: ");

    //Arithmetics
    long bx = (fmod(number, pow(10, 15)));
    long cx = (fmod(bx, pow(10, 14)));
    long dx = (fmod(cx, pow(10, 13)));
    long ex = (fmod(dx, pow(10, 12)));
    long fx = (fmod(ex, pow(10, 11)));
    long gx = (fmod(fx, pow(10, 10)));
    long hx = (fmod(gx, pow(10, 9)));
    long ix = (fmod(hx, pow(10, 8)));
    long jx = (fmod(ix, pow(10, 7)));
    long kx = (fmod(jx, pow(10, 6)));
    long lx = (fmod(kx, pow(10, 5)));
    long mx = (fmod(lx, 10000));
    long nx = (fmod(mx, 1000));
    long ox = (fmod(nx, 100));
    long px = (fmod(ox, 10));

    //Digits
    int a = (number / pow(10, 15));
    int b = (bx / pow(10, 14));
    int c = (cx / pow(10, 13));
    int d = (dx / pow(10, 12));
    int e = (ex / pow(10, 11));
    int f = (fx / pow(10, 10));
    int g = (gx / pow(10, 9));
    int h = (hx / pow(10, 8));
    int i = (ix / pow(10, 7));
    int j = (jx / pow(10, 6));
    int k = (kx / pow(10, 5));
    int l = (lx / 10000);
    int m = (mx / 1000);
    int n = (nx / 100);
    int o = (ox / 10);
    int p = (px % 10);

    int ay = (a * 2);
    int cy = (c * 2);
    int ey = (e * 2);
    int gy = (g * 2);
    int iy = (i * 2);
    int ky = (k * 2);
    int my = (m * 2);
    int oy = (o * 2);

    //Checksum
    int oz = ((oy / 10) + (oy % 10));
    int mz = ((my / 10) + (my % 10));
    int kz = ((ky / 10) + (ky % 10));
    int iz = ((iy / 10) + (iy % 10));
    int gz = ((gy / 10) + (gy % 10));
    int ez = ((ey / 10) + (ey % 10));
    int cz = ((cy / 10) + (cy % 10));
    int az = ((ay / 10) + (ay % 10));

    int csum = (p + oz + n + mz + l + kz + j + iz + h + gz + f + ez + d + cz + b + az);
    int csumx = (csum % 10);

    //Booleans, What kind of card?
    bool visa = ((a == 4) || ((a == 0) && (b == 0) && (c == 0) && (d == 4)));
    bool mcard = ((a == 5) && ((b > 0) && (b < 6)));
    bool amex = ((a == 0) && (b == 3) && ((c == 4) || (c == 7)));

    //Conditions
    if (visa && csumx == 0)
    {
        printf("VISA\n");
    }
    else if (mcard && csumx == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (amex && csumx == 0)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}