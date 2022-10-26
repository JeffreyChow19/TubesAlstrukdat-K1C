/* DRIVER UNTUK ADT MATRIKS */
/* COMPILE MESSAGE
gcc drivermatriks.c matriks.c ../string/string.c ../mesinkarakter/charmachine.c -o a
*/

#include "matriks.h"
#include <stdio.h>
#include "../string/string.h"
#include "../mesinkarakter/charmachine.h"
#include <stdlib.h>

int main()
{
    Matrix m;

    String filename;
    CreateEmptyString(&filename, 15);

    readMatrix(&m, "../../data/peta.txt");

    printf("\n");

    displayMatrix(m);

    return 0;
}