#include "prioqueue.h"
#include <stdio.h>
#include <stdlib.h>

boolean isQueueEmpty(PrioQueue Q)
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean isQueueFull(PrioQueue Q)
{
    return (MaxEl(Q) == Tail(Q));
}

int queueLength(PrioQueue Q)
{
    if (isQueueEmpty(Q))
    {
        return 0;
    }
    else
    {
        return Tail(Q);
    }
}

void CreateQueue(PrioQueue *Q, int Max)
{
    (*Q).buffer = (ElType *)malloc((Max + 1) * sizeof(ElType));

    if ((*Q).buffer != NULL)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else /* alokasi gagal */
    {
        MaxEl(*Q) = 0;
    }
}

void DeAlokasi(PrioQueue *Q)
{
    MaxEl(*Q) = 0;
    free((*Q).buffer);
}

void enqueue(PrioQueue *Q, ElType X)
{
    if (isQueueEmpty(*Q))
    {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoTail(*Q) = X;
    }
    else
    {
        boolean found = false;
        int i = queueLength(*Q);
        while ((i > 0) && (found == false))
        {
            int timeInput = TimeToMinute(EXPIRY(X));
            int timeIdx = TimeToMinute(EXPIRY(Elmt(*Q, i)));

            if (timeInput < timeIdx)
            {
                Elmt(*Q, i + 1) = Elmt(*Q, i);
                i -= 1;
            }
            else
            {
                Elmt(*Q, i + 1) = X;
                found = true;
            }
        }
        if (found == false)
        {
            InfoHead(*Q) = X;
        }
        Tail(*Q) += 1;
    }
}

void dequeue(PrioQueue *Q, ElType *X)
{
    if (queueLength(*Q) == 1)
    {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        *X = InfoHead(*Q);
        for (int i = 1; i < queueLength(*Q); i++)
        {
            Elmt(*Q, i) = Elmt(*Q, i + 1);
        }
        Tail(*Q) -= 1;
    }
}