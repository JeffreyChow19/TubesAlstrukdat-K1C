#include "simulator.h"
#include <stdio.h>

void CreateSim(Sim *S, String Name, Point Pos)
{
    Name(*S) = Name;
    Pos(*S) = Pos;
    CreateTime(&Clock(*S), 0, 0, 0);
    CreateQueue(&Inv(*S), 50, 'i');
    CreateQueue(&Delv(*S), 50, 'd');
    CreateQueue(&Delv(*S), 50, 'p');
}

void copySim(Sim S, Sim *CS)
{
    Name(*CS) = Name(S);
    Pos(*CS) = Pos(S);
    Clock(*CS) = Clock(S);
    copyQueue(Inv(S), &Inv(*CS));
    copyQueue(Delv(S), &Delv(*CS));
    copyQueue(Proc(S), &Proc(*CS));
}

void moveSim(Sim *S, char dir)
{
    if (dir == 'E')
        nextPoint(&Pos(*S), 1, 0);
    else if (dir == 'W')
        nextPoint(&Pos(*S), -1, 0);
    else if (dir == 'N')
        nextPoint(&Pos(*S), 0, -1);
    else if (dir == 'S')
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
    int i = searchIdx(Inv(S), id);
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

void removeExp(Sim *S, Makanan *val)
{
    int exp = TimeToMinute(EXPIRY(InfoHead(Inv(*S))));
    if (exp <= 0)
    {
        dequeue(&Inv(*S), val);
    }
}

void removeDelv(Sim *S, Makanan *val)
{
    int delv = TimeToMinute(DELIVERY(InfoHead(Delv(*S))));
    if (delv <= 0)
    {
        dequeue(&Delv(*S), val);
    }
}

void removeProc(Sim *S, Makanan *val)
{
    int delv = TimeToMinute(DELIVERY(InfoHead(Proc(*S))));
    if (delv <= 0)
    {
        dequeue(&Delv(*S), val);
    }
}

void openInv(Sim S)
{
    if (isQueueEmpty(Inv(S)))
        printf("Inventory kosong\n");
    else
    {
        printf("List Makanan di Inventory\n nama (waktu sisa kedaluwarsa)");
        int i = queueLength(Inv(S)) - 1;
        while (i >= 0)
        {
            printf("%d. ", i + 1);
            printWithExpired(FoodInv(S, i));
            i++;
        }
    }
}

void openDelv(Sim S)
{
    if (isQueueEmpty(Delv(S)))
        printf("Delivery list kosong\n");
    else
    {
        printf("List Makanan di Delivery list\n nama (waktu sisa delivery)");
        int i = queueLength(Delv(S)) - 1;
        while (i >= 0)
        {
            printf("%d. ", i + 1);
            printWithDelivery(FoodDelv(S, i));
            i++;
        }
    }
}

void openProc(Sim S)
{
    if (isQueueEmpty(Proc(S)))
        printf("Process list kosong\n");
    else
    {
        printf("List Makanan di Process list\n nama (waktu sisa proses)");
        int i = queueLength(Proc(S)) - 1;
        while (i >= 0)
        {
            printf("%d. ", i + 1);
            printWithDelivery(FoodProc(S, i));
            i++;
        }
    }
}

void currPos(Sim S)
{
    WritePoint(Pos(S));
}

void currTime(Sim S)
{
    WriteTime(Clock(S));
}