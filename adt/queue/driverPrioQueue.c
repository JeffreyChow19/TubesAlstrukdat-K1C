#include "prioqueue.h"
#include <stdio.h>

int main()
{
    PrioQueue Q;
    CreateQueue(&Q, 5, true);
    String name, act;
    Time exp, del;

    // Make A
    Makanan A;
    setLiteral(&name, "Ayam");
    setLiteral(&act, "CHOP");
    CreateTime(&exp, 0, 2, 0);
    CreateTime(&del, 0, 0, 5);
    CreateMakanan(&A, 2, name, exp, act, del);

    // Make B
    Makanan B;
    setLiteral(&name, "Cabe");
    setLiteral(&act, "MIX");
    CreateTime(&exp, 0, 5, 0);
    CreateTime(&del, 0, 0, 5);
    CreateMakanan(&B, 4, name, exp, act, del);

    // Make C
    Makanan C;
    setLiteral(&name, "Bawang");
    setLiteral(&act, "MIX");
    CreateTime(&exp, 0, 3, 0);
    CreateTime(&del, 0, 0, 5);
    CreateMakanan(&C, 5, name, exp, act, del);

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