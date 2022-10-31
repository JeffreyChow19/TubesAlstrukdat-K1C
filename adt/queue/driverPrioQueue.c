#include "prioqueue.h"
#include <stdio.h>

// gcc driverPrioQueue.c prioqueue.c ../makanan/makanan.c ../waktu/time.c ../string/string.c

int main()
{
    PrioQueue Q;
    CreateQueue(&Q, 5, 'e'); // diurut sesuai expiry
    Time exp, del;

    // Make A
    Makanan A;
    String name1, act1;
    CreateEmptyString(&name1, 10);
    CreateEmptyString(&act1, 10);
    setLiteral(&name1, "Ayam");
    setLiteral(&act1, "CHOP");
    CreateTime(&exp, 0, 2, 0);
    CreateTime(&del, 0, 0, 4);
    CreateMakanan(&A, 2, name1, exp, act1, del);

    // Make B
    Makanan B;
    String name2, act2;
    CreateEmptyString(&name2, 10);
    CreateEmptyString(&act2, 10);
    setLiteral(&name2, "Cabe");
    setLiteral(&act2, "MIX");
    CreateTime(&exp, 0, 5, 0);
    CreateTime(&del, 0, 0, 1);
    CreateMakanan(&B, 4, name2, exp, act2, del);

    // Make C
    Makanan C;
    String name3, act3;
    CreateEmptyString(&name3, 10);
    CreateEmptyString(&act3, 10);
    setLiteral(&name3, "Bawang");
    setLiteral(&act3, "MIX");
    CreateTime(&exp, 0, 3, 0);
    CreateTime(&del, 0, 0, 3);
    CreateMakanan(&C, 5, name3, exp, act3, del);

    enqueue(&Q, A);
    enqueue(&Q, B);
    enqueue(&Q, C);

    while (!isQueueEmpty(Q))
    {
        Makanan temp;
        dequeue(&Q, &temp);
        printMakananDetails(temp);
    }

    return 0;
}