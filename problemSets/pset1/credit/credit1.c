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
    int a = ((number / pow(10, 15)) * 2);
    int b = (bx / pow(10, 14));
    int c = ((cx / pow(10, 13)) * 2);
    int d = (dx / pow(10, 12));
    int e = ((ex / pow(10, 11)) * 2);
    int f = (fx / pow(10, 10));
    int g = ((gx / pow(10, 9)) * 2);
    int h = (hx / pow(10, 8));
    int i = ((ix / pow(10, 7)) * 2);
    int j = (jx / pow(10, 6));
    int k = ((kx / pow(10, 5)) * 2);
    int l = (lx / 10000);
    int m = ((mx / 1000) * 2);
    int n = (nx / 100);
    int o = ((ox / 10) * 2);
    int p = (px % 10);

    //Checksum
    int oz = ((o / 10) + (o % 10));
    int mz = ((m / 10) + (m % 10));
    int kz = ((k / 10) + (k % 10));
    int iz = ((i / 10) + (i % 10));
    int gz = ((g / 10) + (g % 10));
    int ez = ((e / 10) + (e % 10));
    int cz = ((c / 10) + (c % 10));
    int az = ((a / 10) + (a % 10));

    int csum = (p + oz + n + mz + l + kz + j + iz + h + gz + f + ez + d + cz + b + az);
    int csumx = (csum % 10);

    //Booleans, What kind of card?
    bool visa = ((a == 8) || ((a == 0) && (b == 0) && (c == 0) && (d == 8)));
    bool mcard = ((a == 10) && ((b > 0) && (b < 6)));
    bool amex = ((a == 0) && (b == 3) && ((c == 8) || (c == 14)));

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