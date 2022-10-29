#include "prioqueue.h"
#include <stdio.h>
#include <stdlib.h>

boolean isQueueEmpty(PrioQueue Q)
{
    return ((Head(Q) == IDX_UNDEF) && (Tail(Q) == IDX_UNDEF));
}

boolean isQueueFull(PrioQueue Q)
{
    return (Tail(Q) == MaxQueue(Q) - 1);
}

int queueLength(PrioQueue Q)
{
    if (isQueueEmpty(Q))
    {
        return 0;
    }
    else
    {
        return Tail(Q) + 1;
    }
}

void CreateQueue(PrioQueue *Q, int Max, char type)
{
    (*Q).buffer = (QElType *)malloc((Max) * sizeof(QElType));

    if ((*Q).buffer != NULL)
    {
        MaxQueue(*Q) = Max;
        Head(*Q) = IDX_UNDEF;
        Tail(*Q) = IDX_UNDEF;
        QueueType(*Q) = type;
    }
    else /* alokasi gagal */
    {
        MaxQueue(*Q) = 0;
    }
}

void dealocateQueue(PrioQueue *Q)
{
    MaxQueue(*Q) = 0;
    free((*Q).buffer);
}

void enqueue(PrioQueue *Q, QElType X)
{
    if (isQueueFull(*Q))
    {
        expandQueue(Q, MaxQueue(*Q));
    }
    if (isQueueEmpty(*Q))
    {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else
    {
        boolean found = false;
        int i = queueLength(*Q) - 1;
        while ((i >= 0) && (found == false))
        {
            int timeInput;
            int timeIdx;
            if (isForExpiry(*Q))
            {
                timeInput = TimeToMinute(EXPIRY(X));
                timeIdx = TimeToMinute(EXPIRY(Elmt(*Q, i)));
            }
            else if (isForDelivery(*Q) || isForProcess(*Q))
            {
                timeInput = TimeToMinute(DELIVERY(X));
                timeIdx = TimeToMinute(DELIVERY(Elmt(*Q, i)));
            }

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

void dequeue(PrioQueue *Q, QElType *X)
{
    if (queueLength(*Q) == 1)
    {
        *X = InfoHead(*Q);
        Head(*Q) = IDX_UNDEF;
        Tail(*Q) = IDX_UNDEF;
    }
    else
    {
        *X = InfoHead(*Q);
        int i;
        for (i = 0; i < queueLength(*Q) - 1; i++)
        {
            Elmt(*Q, i) = Elmt(*Q, i + 1);
        }
        Tail(*Q) -= 1;
    }
}

void removeLast(PrioQueue *Q, QElType *X)
{
    if (queueLength(*Q) == 1)
    {
        *X = InfoHead(*Q);
        Head(*Q) = IDX_UNDEF;
        Tail(*Q) = IDX_UNDEF;
    }
    else
    {
        *X = InfoTail(*Q);
        Tail(*Q) -= 1;
    }
}

int searchIdx(PrioQueue Q, int id)
{
    boolean found = false;
    int i = 0;
    while ((i < queueLength(Q)) && (found == false))
    {
        if (ID(Elmt(Q, i)) == id)
        {
            found = true;
        }
        else
        {
            i += 1;
        }
    }
    if (found == false)
    {
        return IDX_UNDEF;
    }
    else
    {
        return i;
    }
}

void removeIdx(PrioQueue *Q, Makanan *val, int id)
{
    int idx = searchIdx(*Q, id);
    if (idx == IDX_UNDEF)
    {
        printf("ID tidak ditemukan dalam List Queue\n");
    }
    else
    {
        *val = Elmt(*Q, idx);
        if (queueLength(*Q) == 1)
        {
            Head(*Q) = IDX_UNDEF;
            Tail(*Q) = IDX_UNDEF;
        }
        else
        {
            int i = idx;
            if (i < Tail(*Q))
            {
                for (i; i < queueLength(*Q) - 1; i++)
                {
                    Elmt(*Q, i) = Elmt(*Q, i + 1);
                }
            }
            Tail(*Q) -= 1;
        }
    }
}

void copyQueue(PrioQueue Q, PrioQueue *Q2)
{
    CreateQueue(Q2, MaxQueue(Q), QueueType(Q));
    int i;
    for (i = 0; i < queueLength(Q); i++)
    {
        Elmt(*Q2, i) = Elmt(Q, i);
    }
    Head(*Q2) = Head(Q);
    Tail(*Q2) = Tail(Q);
}

boolean isForDelivery(PrioQueue Q)
{
    return (QueueType(Q) == 'd');
}

boolean isForExpiry(PrioQueue Q)
{
    return (QueueType(Q) == 'i');
}

boolean isForProcess(PrioQueue Q)
{
    return (QueueType(Q) == 'p');
}

void expandQueue(PrioQueue *Q, int num)
{
    MaxQueue(*Q) += num;
    (*Q).buffer = realloc((*Q).buffer, MaxQueue(*Q) * sizeof(QElType));
}

void reduceAllTime(PrioQueue *Q)
{
    int i;
    if (QueueType(*Q) == 'i')
    {
        for (i = 0; i < queueLength(*Q); i++)
        {
            decDuration(&EXPIRY(Elmt(*Q, i)));
        }
    }
    else if (QueueType(*Q) == 'd' || QueueType(*Q) == 'p')
    {
        for (i = 0; i < queueLength(*Q); i++)
        {
            decDuration(&DELIVERY(Elmt(*Q, i)));
        }
    }
}