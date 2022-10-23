/* DRIVER LIST STRING */

/* COMPILE MESSAGE
gcc driverListString.c liststring.c ../string/string.c -o a
*/

#include "liststring.h"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../string/string.h"

int main()
{
    LString l;
    CreateLString(&l, 3);
    String a, b, c, d;
    CreateEmptyString(&a, 2);
    CreateEmptyString(&b, 10);
    CreateEmptyString(&c, 10);
    CreateEmptyString(&d, 10);

    setLiteral(&a, "Hello Alstrukdat");
    setLiteral(&b, "Hello World");
    setLiteral(&c, "Hello Tubes");
    setLiteral(&d, "Hello Tubes Alstrukdets");

    insertLastString(&l, a);
    insertLastString(&l, b);
    insertLastString(&l, c);
    insertLastString(&l, d);

    int i = 0;
    for (i; i < l.nEff; i++)
    {
        printf("%s\n", SBUFFER(ELMTLString(l, i)));
    }

    return 0;
}