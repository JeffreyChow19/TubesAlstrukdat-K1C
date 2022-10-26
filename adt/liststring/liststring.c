#include "liststring.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

void CreateLString(LString *l, int capacity)
{
    LSCAPACITY(*l) = capacity;
    LSBUFFER(*l) = (String *)malloc(sizeof(SElType) * capacity);
    LSNEFF(*l) = 0;
}

void dealocateLString(LString *l)
{
    LSCAPACITY(*l) = 0;
    LSNEFF(*l) = 0;
    free(LSBUFFER(*l));
}

int lStringLength(LString l)
{
    return LSNEFF(l);
}

IdxType getFirstIdxLString(LString l)
{
    return 0;
}

IdxType getLastIdxLString(LString l)
{
    return (LSNEFF(l) - 1);
}

boolean isEmptyLString(LString l)
{
    return LSNEFF(l) == 0;
}

boolean isFullLString(LString l)
{
    return LSNEFF(l) == LSCAPACITY(l);
}

void expandLString(LString *l, int num)
{
    LSCAPACITY(*l) += num;
    LSBUFFER(*l) = realloc(LSBUFFER(*l), LSCAPACITY(*l) * sizeof(SElType));
}

void insertLastString(LString *l, SElType val)
{
    if (isFullLString(*l))
    {
        expandLString(l, LSCAPACITY(*l));
    }
    if (isEmptyLString(*l))
    {
        LSNEFF(*l) = 1;
    }
    else
    {
        LSNEFF(*l) += 1;
    }

    SBUFFER(ELMTLString(*l, getLastIdxLString(*l))) = val.buffer;
}
