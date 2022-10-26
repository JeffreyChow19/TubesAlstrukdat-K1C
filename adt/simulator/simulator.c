#include "simulator.h"
#include <stdio.h>

void CreateSim(Sim *S, String Name, Point Pos)
{
    Name(*S) = Name;
    Pos(*S) = Pos;
    CreateTime(&Clock(*S), 0, 0, 0);
    CreateQueue(&Inv(*S), 50);
    CreateQueue(&Delv(*S), 50);
}

void copySim(Sim S, Sim *CS)
{
    Name(*CS) = Name(S);
    Pos(*CS) = Pos(S);
    Clock(*CS) = Clock(S);
    /* masih perlu copy queue */
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

void addTime(Sim *S, int dd, int hh, int mm)
{
    Time add; 
    CreateTime(&add, dd, hh, mm);
    int added = TimeToMinute(add);
    incNTime(&Clock(*S), added);
}

void removeTime(Sim *S, int dd, int hh, int mm)
{
    Time remove;
    CreateTime(&remove, dd, hh, mm);
    int removed = TimeToMinute(remove);
    decNDuration(&Clock(*S), removed);
}

void getFood(Sim S, Makanan *val, int id)
{
    int i = indexOf(Inv(S), id);
    *val = (FoodInv(S, i));
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
            printWithExpired(FoodInv(S, i));
            i++;
        }
    }
}

void currPos(Sim S)
{
    WritePoint(Pos(S));
}