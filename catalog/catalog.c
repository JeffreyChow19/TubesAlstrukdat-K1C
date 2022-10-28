#include <stdio.h>
#include "../adt/liststatik/liststatik.h"
#include "../data/data.h"

void displayCatalog()
{
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");

    int i;

    for (i = 0; i < foods.Neff; i++)
    {
        printf("%d. ", i + 1);
        printf("%s - ", foods.buffer[i].name.buffer);
        WriteDuration(foods.buffer[i].expiry);
        printf(" - %s - ", foods.buffer[i].action.buffer);
        WriteDuration(foods.buffer[i].delivery);
        printf("\n");
    }
}