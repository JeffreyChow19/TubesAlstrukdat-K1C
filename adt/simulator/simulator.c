#include "simulator.h"
#include <stdio.h>

void CreateSim(Sim *S, String Name, Point Pos)
{
    Name(*S) = Name;
    Pos(*S) = Pos;
    CreateTime(&Clock(*S), 0, 0, 0);
    CreateQueue(&Inv(*S), 50, 'i');
    CreateQueue(&Delv(*S), 50, 'd');
    CreateQueue(&Proc(*S), 50, 'p');
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

void addDelv(Sim *S, Makanan val)
{
    enqueue(&Delv(*S), val);
}

void addProc(Sim *S, Makanan val)
{
    enqueue(&Proc(*S), val);
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
    int proc = TimeToMinute(DELIVERY(InfoHead(Proc(*S))));
    if (proc <= 0)
    {
        dequeue(&Proc(*S), val);
    }
}

void openInv(Sim S)
{
    if (isQueueEmpty(Inv(S)))
        printf("Inventory kosong\n");
    else
    {
        printf("List Makanan di Inventory\nnama (waktu sisa kedaluwarsa)\n");
        int i = 0;
        while (i < queueLength(Inv(S)))
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
        printf("List Makanan di Delivery list\nnama (waktu sisa delivery)\n");
        int len = queueLength(Delv(S));
        for (int i = 0; i < len; i++)
        {
            printf("%d. ", i + 1);
            printWithDelivery(FoodDelv(S, i));
        }
    }
}

void openProc(Sim S)
{
    if (isQueueEmpty(Proc(S)))
        printf("Process list kosong\n");
    else
    {
        printf("List Makanan di Process list\nnama (waktu sisa proses)\n");
        int i = 0;
        while (i < queueLength(Proc(S)))
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
