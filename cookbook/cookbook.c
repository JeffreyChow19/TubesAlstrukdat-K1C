#include <stdio.h>
#include "../data/data.h"
#include "../adt/listdin/listdin.h"
#include "../adt/tree/tree.h"

void displayCookbook()
{
    printf("List Resep\n");
    printf("(aksi yang diperlukan - bahan...)\n");

    int i;

    for (i = getFirstIdxDin(recipes); i <= getLastIdxDin(recipes); ++i)
    {
        Address node = ELMT(recipes, i);

        // print number
        printf("%d. ", i + 1);

        // print menu
        printf("%s\n", SBUFFER(NAME(INFO(node))));

        // print action
        printf("   %s", SBUFFER(ACTION(INFO(node))));

        // print bahan
        int j;
        for (j = getFirstIdxDin(CHILDREN(node)); j <= getLastIdxDin(CHILDREN(node)); ++j)
        {
            printf(" - %s", SBUFFER(NAME(INFO(ELMT(CHILDREN(node), j)))));
        }
        printf("\n");
    }
}