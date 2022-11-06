#include "buy.h"
#include "../data/data.h"
#include "../adt/simulator/simulator.h"
#include "../adt/mesinkata/wordmachine.h"
#include <stdio.h>
#include "../color/color.h"

/* Aksi membeli bahan */
boolean buy()
{
    int com, i;

    printf("====================\n");
    printf("==      BUY       ==\n");
    printf("====================\n");

    if (listLength(rawFoods) == 0)
    {
        red(false);
        printf("Tidak ada bahan yang dapat dibeli.\n");
        reset();
        return false;
    }
    else
    {
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
        com = readIntWithRange(0, listLength(rawFoods));

        if (com == 0)
            return false;
        Makanan m = StELMT(rawFoods, com - 1);

        addDelv(&simulator, m);
        green(false);
        printf("\nBerhasil memesan %s. %s akan diantar dalam ", SBUFFER(NAME(m)), SBUFFER(NAME(m)));

        WriteDuration(DELIVERY(StELMT(rawFoods, com - 1)));
        printf(".\n");
        reset();

        int length = LENGTH(NAME(m));

        char text[31 + length];
        sprintf(text, "%s masuk ke dalam delivery list.", SBUFFER(NAME(m)));
        String notif;
        CreateEmptyString(&notif, 31 + length);
        setLiteral(&notif, text);
        addNotif(&simulator, notif, false);

        char textUndo[31 + length];
        sprintf(textUndo, "Pembelian makanan %s dibatalkan.", SBUFFER(NAME(m)));
        String notifUndo;
        CreateEmptyString(&notifUndo, 31 + length);
        setLiteral(&notifUndo, textUndo);
        addNotif(&simulator, notifUndo, true);
        return true;
    }
}