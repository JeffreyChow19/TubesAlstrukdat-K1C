#include "buy.h"
#include "../data/data.h"
#include "../adt/simulator/simulator.h"
#include <stdio.h>

void buy(Sim *S)
{
    int com, i;

    printf("====================\n");
    printf("==      BUY       ==\n");
    printf("====================\n");

    printf("List Bahan Makanan:\n");
    printf("nama (delivery time)\n");
    /* List Bahan Makanan */
    for (i = 0; i < listLength(rawFoods); i++)
    {
        printf("%d. ", i + 1);
        printWithDelivery(StELMT(rawFoods, i));
    }
    printf("\n");

    printf("Kirim 0 untuk exit.\n");
    printf("\n");
    if (listLength(rawFoods) == 0)
        printf("Tidak ada bahan yang dapat dibeli.\n");
    else
    {
        printf("Enter Command (0-%d): ", listLength(rawFoods));
        scanf("%d", &com);

        if ((com < 1) || (com > listLength(rawFoods)))
            printf("Invalid command.\n");
        else
        {
            addDelv(S, StELMT(rawFoods, com - 1));
            printf("Berhasil memesan %s. %s akan diantar dalam ", SBUFFER(NAME(StELMT(rawFoods, com - 1))), SBUFFER(NAME(StELMT(rawFoods, com - 1))));
            WriteDuration(DELIVERY(StELMT(rawFoods, com - 1)));
            printf(".\n\n");
        }
    }
}