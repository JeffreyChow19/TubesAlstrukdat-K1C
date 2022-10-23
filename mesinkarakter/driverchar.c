/* DRIVER CHAR MACHINE UNTUK MEMBACA FILE DAN STDIN */
/* FILE : test.txt */

/* COMPILE MESSAGE
gcc driverchar.c charmachine.c ../string/string.c ../liststring/liststring.c -o a
*/

#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("DRIVER FILE \n");
    printf("=========== \n");

    LString l;
    String filename;
    CreateEmptyString(&filename, 15);
    SBUFFER(filename) = "peta.txt";
    ReadFile(filename, &l);

    printf("Items : %d\n", l.nEff);

    int i;
    for (i = 0; i < l.nEff; i++)
    {
        printf("Index-%d : %s", i, SBUFFER(ELMTLString(l, i)));
    }

    printf("\n\nDRIVER STDIN \n");
    printf("============ \n");
    printf("Input sesuatu, MARK = '.' : ");
    START();

    return 0;
}