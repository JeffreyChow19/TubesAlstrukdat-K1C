#include <stdio.h>
#include "../data/data.h"
#include "../adt/listdin/listdin.h"
#include "../adt/tree/tree.h"
#include "../color/color.h"

boolean hasBahan(int id)
{
    int idx = searchIdx(Inv(simulator), id);
    if (idx != IDX_UNDEF)
        return true;

    idx = searchIdxKulkas(Fridge(simulator), id);
    return idx != IDX_UNDEF_K;
}

void displayRecipe(Tree node)
{
    // print menu
    printf("%s\n", SBUFFER(NAME(INFO(node))));

    // print action
    printf("   %s", SBUFFER(ACTION(INFO(node))));

    // print bahan
    int j;
    for (j = getFirstIdxDin(CHILDREN(node)); j <= getLastIdxDin(CHILDREN(node)); ++j)
    {
        boolean has = hasBahan(ID(INFO(ELMT(CHILDREN(node), j))));
        printf(" - ");
        if (has)
            green(false);
        printf("%s", SBUFFER(NAME(INFO(ELMT(CHILDREN(node), j)))));
        if (has)
            reset();
    }
    printf("\n");
}

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

        displayRecipe(node);
    }
}
