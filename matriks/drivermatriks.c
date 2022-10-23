/* DRIVER UNTUK ADT MATRIKS */
/* COMPILE MESSAGE
gcc drivermatriks.c matriks.c ../string/string.c ../liststring/liststring.c ../mesinkarakter/charmachine.c -o a
*/

#include "matriks.h"
#include <stdio.h>
#include "../string/string.h"
#include "../liststring/liststring.h"
#include "../mesinkarakter/charmachine.h"
#include <stdlib.h>

int main()
{
    Matrix m;

    String filename;
    CreateEmptyString(&filename, 15);
    setLiteral(&filename, "peta.txt");

    readMatrix(&m, filename);
    displayMatrix(m);

    return 0;
}