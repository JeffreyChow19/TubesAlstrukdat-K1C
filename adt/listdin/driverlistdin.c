#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* DRIVER LIST DIN */
/* COMPILE MESSAGE
gcc driverlistdin.c listdin.c ../tree/tree.c -o driverlistdin
*/

int main()
{
    ListDin l;
    CreateListDin(&l, 100);

    printf("Is Empty : %d\n", isEmptyDin(l));

    insertLastDin(&l, 1);
    insertLastDin(&l, 2);
    insertLastDin(&l, 3);

    printf("Index 2 : %d\n", indexOfDin(l, 2));

    deleteAtDin(&l, 1);

    printf("Index 2 : %d\n", indexOfDin(l, 2));

    printf("Last index : %d\n", getLastIdxDin(l));

    return 0;
}
