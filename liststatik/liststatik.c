#include "liststatik.h"
#include <stdio.h>

void CreateListStatik(ListStatik *l)
{
    Neff(*l) = 0;
}

int listLength(ListStatik l)
{
    return Neff(l);
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
    return (i >= IDX_MIN && i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i)
{
    return (i >= 0 && i < listLength(l));
}

boolean isEmpty(ListStatik l)
{
    return (listLength == 0);
}

boolean isFull(ListStatik l)
{
    return (listLength == CAPACITY);
}

int indexOf(ListStatik l, int id)
{
    if (isEmpty(l))
        return IDX_UNDEF;
    else
    {
        IdxType i = getFirstIdx(l);
        while (i <= getLastIdx(l) && ELMT(l,i).id != id)
        {
            i++;
        }
        if (i > getLastIdx(l))
            return IDX_UNDEF;
        else
            return i;
    };  
}

void inserLast(ListStatik *l, ElType val)
{
    if (isEmpty(*l))
        Neff(*l) = 1;
    else
        Neff(*l) += 1;
    ELMT(*l, getLastIdx(*l) + 1) = val;
}

void deleteID(ListStatik *l, ElType *val, int id)
{
    int i = indexOf(*l, id);
    *val = ELMT(*l,i);
    for (i; i < getLastIdx(*l); i++)
    {
        ELMT(*l,i) = ELMT(*l, i + 1);
    }
    Neff(*l) -= 1;
}

void deleteLast(ListStatik *l, ElType *val)
{
    *val = ELMT(*l, getLastIdx(*l));
    Neff(*l) -= 1;
}