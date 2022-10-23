#include "liststring.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

void CreateLString(LString *l, int capacity)
{
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (String *)malloc(sizeof(SElType) * capacity);
    NEFF(*l) = 0;
}

void dealocateLString(LString *l)
{
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

int lStringLength(LString l)
{
    return NEFF(l);
}

IdxType getFirstIdx(LString l)
{
    return 0;
}

IdxType getLastIdx(LString l)
{
    return (NEFF(l) - 1);
}

boolean isEmpty(LString l)
{
    return NEFF(l) == 0;
}

boolean isFull(LString l)
{
    return NEFF(l) == CAPACITY(l);
}

void expandLString(LString *l, int num)
{
    CAPACITY(*l) += num;
    BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(SElType));
}

void insertLastString(LString *l, SElType val)
{
    if (isFull(*l))
    {
        expandLString(l, CAPACITY(*l));
    }
    if (isEmpty(*l))
    {
        NEFF(*l) = 1;
    }
    else
    {
        NEFF(*l) += 1;
    }

    SBUFFER(ELMTLString(*l, getLastIdx(*l))) = val.buffer;
}
