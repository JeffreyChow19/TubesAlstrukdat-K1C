#include "simulator.h"
#include <stdio.h>

void CreateSim(Sim *S, String Name, Point Pos)
{
    Name(*S) = Name;
    Pos(*S) = Pos;
    CreateQueue(&Inv(*S), 50);
}

void moveSim(Sim *S, String dir)
{
    if (SBUFFER(dir) == "EAST")
        nextPoint(&Pos(*S), 1, 0);
    else if (SBUFFER(dir) == "WEST")
        nextPoint(&Pos(*S), -1, 0);
    else if (SBUFFER(dir) == "NORTH")
        nextPoint(&Pos(*S), -1, 0);
    else if (SBUFFER(dir) == "SOUTH")
        nextPoint(&Pos(*S), 0, 1);
}

void getFood(Sim S, Makanan *val, int id)
{
    int i = searchIdx(Inv(S), id);
    *val = (Food(S, i));
}

void addFood(Sim *S, Makanan val)
{
    enqueue(&Inv(*S), val);
}

void removeFoodID(Sim *S, Makanan *val, int id)
{
    Makanan food;
    removeIdx(&Inv(*S), &food, id);
    *val = food;
}

void removeFoodLast(Sim *S, Makanan *val)
{
    Makanan food;
    removeLast(&Inv(*S), &food);
    *val = food;
}

void openInv(Sim S)
{
    if (isQueueEmpty(Inv(S)))
        printf("Inventory kosong\n");
    else
    {
        printf("List Makanan di Inventory\n (nama - waktu sisa kedaluwarsa)");
        int i = queueLength(Inv(S)) - 1;
        while (i >= 0)
        {
            printf("%d. ", i + 1);
            printWithExpired(Food(S, i));
            i++;
        }
    }
}

void currPos(Sim S)
{
    WritePoint(Pos(S));
}