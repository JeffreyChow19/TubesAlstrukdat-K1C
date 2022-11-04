/* DRIVER UNTUK ADT MATRIKS */
/* COMPILE MESSAGE
gcc drivermatriks.c matriks.c ../string/string.c ../mesinkarakter/charmachine.c ../mesinkata/wordmachine.c ../../color/color.c ../../error/error.c -o drivermatriks
*/

#include "matriks.h"
#include <stdio.h>
#include "../string/string.h"
#include "../mesinkarakter/charmachine.h"
#include <stdlib.h>

int main()
{
    Matrix m;
    Point a;
    a.X = 1;
    a.Y = 1;

    readMatrix(&m, "../../data/peta.txt", &a);

    printf("\n");

    displayMatrix(m, a);

    return 0;
}