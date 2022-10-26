/* DRIVER CHAR MACHINE UNTUK MEMBACA FILE DAN STDIN */
/* FILE : test.txt */

/* COMPILE MESSAGE
gcc driverchar.c charmachine.c ../string/string.c -o a
*/

#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include "../string/string.h"
#include "../boolean.h"

int main()
{
    printf("DRIVER FILE \n");
    printf("=========== \n");

    String filename;
    CreateEmptyString(&filename, 15);
    SBUFFER(filename) = "../../data/peta.txt";

    START(fopen(SBUFFER(filename), "r"), true);

    while (!EOP)
    {
        printf("%c", currentChar);
        ADV();
    }

    printf("\n");

    printf("\n\nDRIVER STDIN \n");
    printf("============ \n");
    printf("Input sesuatu, lalu press enter : ");
    START(stdin, false);

    while (!EOP)
    {
        printf("%c", currentChar);
        ADV();
    }

    return 0;
}