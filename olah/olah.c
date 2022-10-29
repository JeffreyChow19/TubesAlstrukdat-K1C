#include "../adt/simulator/simulator.h"
#include "../data/data.h"
#include "../adt/liststring/liststring.h"
#include <stdio.h>

void mix();

void chop();

void fry()
{
    printf("===============\n");
    printf("=     FRY     =\n");
    printf("===============\n");

    printf("List Bahan Makanan yang Bisa Dibuat:\n");

    int i;
    int j = 1;

    LString menus;
    CreateLString(&menus, recipes.nEff);

    for (i = getFirstIdxDin(recipes); i <= getLastIdxDin(recipes); ++i)
    {
        Address node = ELMT(recipes, i);

        if (isStringEqualLiteral(ACTION(INFO(node)), "FRY"))
        {
            // print number
            printf("%d. ", j);

            // print menu
            printf("%s\n", SBUFFER(NAME(INFO(node))));

            // insert to menu
            insertLastString(&menus, NAME(INFO(node)));
            j++;
        }
    }

    int command;
    printf("Enter Command: ");
    scanf("%d", &command);

    if (command == 0)
    {
        
    }
    else
    {
        if (command <= menus.nEff && command > 0)
        {

        }
    }
}

void boil();