#include "liststring.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

void CreateLString(LString *l, int capacity)
{
    LSCAPACITY(*l) = capacity > 0 ? capacity : 1;
    LSBUFFER(*l) = (String *)malloc(sizeof(SElType) * LSCAPACITY(*l));
    LSNEFF(*l) = 0;
}

void dealocateLString(LString *l)
{
    clearListString(l, true);
    LSCAPACITY(*l) = 0;
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

    // realloc doesnt work
    SElType *temp = (SElType *)malloc(sizeof(SElType) * LSCAPACITY(*l));

    for (int i = 0; i < LSNEFF(*l); i++)
    {
        temp[i] = LSBUFFER(*l)[i];
    }

    free(LSBUFFER(*l));
    LSBUFFER(*l) = temp;
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
    int idx = LSCAPACITY(*l);
    ELMTLString(*l, getLastIdxLString(*l)) = val;
}

void clearListString(LString *l, boolean dealocateEl)
{
    if (dealocateEl)
    {
        int i;
        for (i = getFirstIdxLString(*l); i <= getLastIdxLString(*l); i++)
        {
            dealocateString(&(ELMTLString(*l, i)));
        }
    }
    LSNEFF(*l) = 0;
}

void copyListString(LString l, LString *l1)
{
    CreateLString(l1, LSNEFF(l));
    LSNEFF(*l1) = LSNEFF(l);
    int i;
    for (i = 0; i < LSNEFF(l); i++)
    {
        ELMTLString(*l1, i) = ELMTLString(l, i);
    }
}