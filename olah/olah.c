#include "../adt/simulator/simulator.h"
#include "../data/data.h"
#include "../adt/liststring/liststring.h"
#include "../adt/boolean.h"
#include "../adt/mesinkata/wordmachine.h"
#include "../color/color.h"
#include <stdio.h>

boolean processFood(String process)
{
    // print header
    blue(false);
    int i;
    for (i = 0; i < process.nEff + 12; i++)
    {
        printf("=");
    }
    printf("\n");
    printf("=     %s     =\n", process.buffer);
    for (i = 0; i < process.nEff + 12; i++)
    {
        printf("=");
    }
    printf("\n");
    reset();

    // print list bahan makanan
    printf("List bahan makanan yang bisa di %s:\n", process.buffer);

    int j = 1;

    ListDin menus;
    CreateListDin(&menus, recipes.nEff);

    for (i = getFirstIdxDin(recipes); i <= getLastIdxDin(recipes); ++i)
    {
        Address node = ELMT(recipes, i);

        if (isStringEqualLiteral(ACTION(INFO(node)), process.buffer))
        {
            // print number
            printf("%d. ", j);

            // print menu
            printf("%s\n", SBUFFER(NAME(INFO(node))));

            // insert to menu
            insertLastDin(&menus, node);
            j++;
        }
    }

    printf("\nKirim 0 untuk exit.\n");

    // input command
    printf("\n");
    int command = readIntWithRange(0, menus.nEff);

    if (command != 0)
    {
        // recipe chosen
        Address recipe = ELMT(menus, command - 1);

        // handling bahan notFound
        boolean notFound = false;
        int idxNotFound = 1;

        int j;

        // check whether bahan is available and if not available, print bahan that is not available
        for (j = getFirstIdxDin(CHILDREN(recipe)); j <= getLastIdxDin(CHILDREN(recipe)); ++j)
        {
            int idToSearch = INFO(ELMT(CHILDREN(recipe), j)).id;

            if (searchIdx(simulator.Inv, idToSearch) == IDX_UNDEF && searchIdxKulkas(Fridge(simulator), idToSearch) == IDX_UNDEF_K)
            {
                if (!notFound)
                {
                    red(false);
                    printf("\nGagal membuat %s karena kamu tidak memiliki bahan berikut:\n", recipe->info.name.buffer);
                    reset();
                    notFound = true;
                }
                printf("%d. %s\n", idxNotFound, INFO(ELMT(CHILDREN(recipe), j)).name.buffer);
                idxNotFound++;
            }
        }

        // if all bahan available, remove bahan from inventory, add new item to inventory
        if (!notFound)
        {
            // remove bahan from inventory
            for (j = getFirstIdxDin(CHILDREN(recipe)); j <= getLastIdxDin(CHILDREN(recipe)); ++j)
            {
                int idToRemove = INFO(ELMT(CHILDREN(recipe), j)).id;
                int indexInQueue = searchIdx(Inv(simulator), idToRemove);

                QElType val;

                // remove item from inventory or fridge
                if (indexInQueue != IDX_UNDEF)
                {
                    removeByIndex(&Inv(simulator), &val, indexInQueue);
                }
                else
                {
                    removeItemKulkas(&Fridge(simulator), &val, idToRemove);
                }
            }

            // add makanan to queue
            enqueue(&(simulator.Proc), recipe->info);

            // success message
            green(false);
            printf("%s sedang diproses. %s akan selesai dalam ", SBUFFER(NAME(INFO(recipe))), SBUFFER(NAME(INFO(recipe))));

            int length = LENGTH(NAME(INFO(recipe))) + LENGTH(ACTION(INFO(recipe)));

            char text[39 + length];
            sprintf(text, "%s makanan %s masuk ke dalam process list.", SBUFFER(ACTION(INFO(recipe))), SBUFFER(NAME(INFO(recipe))));
            String notif;
            CreateEmptyString(&notif, 39 + length);
            setLiteral(&notif, text);
            addNotif(&simulator, notif, false);

            char undoText[22 + length];
            sprintf(undoText, "%s makanan %s dibatalkan.", SBUFFER(ACTION(INFO(recipe))), SBUFFER(NAME(INFO(recipe))));
            String undoNotif;
            CreateEmptyString(&undoNotif, 22 + length);
            setLiteral(&undoNotif, undoText);
            addNotif(&simulator, undoNotif, true);

            WriteDuration(DELIVERY(INFO(recipe)));
            reset();
            printf("\n");
        }

        printf("\n");
        return !notFound;
    }

    return false;
}