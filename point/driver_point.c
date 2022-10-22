// ADT Sederhana : ADT point
/* ADT Point wajib memiliki koordinat X dan Y. ADT ini digunakan untuk
merepresentasikan lokasi. */

/* Driver ADT Point */

#include "point.h"
#include <stdio.h>

int main()
{
    int x, y;
    Point P;

    /* Konstruktor */
    scanf("%d", &x);
    scanf("%d", &y);
    CreatePoint(&P, x, y);

    /* Input Output */
    WritePoint(P);

    /* Validasi Point */
    printf("Valid? %d\n", isPointValid(x, y));

    /* Operasi Point*/
    nextPoint(&P, 1, 0);
    WritePoint(P);
    nextPoint(&P, -10, -5);
    WritePoint(P);
    nextPoint(&P, 0, -20);
    WritePoint(P);

    Point F;
    CreatePoint(&F, 10, 10);
    printf("Adjacent %d\n", isAdj(P, F));

    return 0;
}