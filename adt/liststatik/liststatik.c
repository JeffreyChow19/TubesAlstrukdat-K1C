#include "liststatik.h"
#include <stdio.h>

void CreateListStatik(ListStatik *l)
{
    StNeff(*l) = 0;
}

int listLength(ListStatik l)
{
    return StNeff(l);
}

IdxType getFirstIdx(ListStatik l)
{
    return 0;
}

IdxType getLastIdx(ListStatik l)
{
    return listLength(l) - 1;
}

boolean isIdxValid(ListStatik l, IdxType i)
{
    return (i >= IDX_MIN && i < StCAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i)
{
    return (i >= 0 && i < listLength(l));
}

boolean isEmpty(ListStatik l)
{
    return (listLength(l) == 0);
}

boolean isFull(ListStatik l)
{
    return (listLength(l) == StCAPACITY);
}

int indexOf(ListStatik l, int id)
{
    if (isEmpty(l))
        return IDX_UNDEF;
    else
    {
        IdxType i = getFirstIdx(l);
        while (i <= getLastIdx(l) && StELMT(l, i).id != id)
        {
            i++;
        }
        if (i > getLastIdx(l))
            return IDX_UNDEF;
        else
            return i;
    };
}

void insertLast(ListStatik *l, ElType val)
{
    if (isEmpty(*l))
        StNeff(*l) = 1;
    else
        StNeff(*l) += 1;
    StELMT(*l, getLastIdx(*l)) = val;
}

void deleteID(ListStatik *l, ElType *val, int id)
{
    int i = indexOf(*l, id);
    *val = StELMT(*l, i);
    for (i; i < getLastIdx(*l); i++)
    {
        StELMT(*l, i) = StELMT(*l, i + 1);
    }
    StNeff(*l) -= 1;
}

void deleteLast(ListStatik *l, ElType *val)
{
    *val = StELMT(*l, getLastIdx(*l));
    StNeff(*l) -= 1;
}