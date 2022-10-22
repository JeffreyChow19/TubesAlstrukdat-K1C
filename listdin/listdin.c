#include "listdin.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void CreateListDin(ListDin *l, int capacity)
{
  BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
  CAPACITY(*l) = capacity;
  NEFF(*l) = 0;
}

void dealocateList(ListDin *l)
{
  CAPACITY(*l) = 0;
  NEFF(*l) = 0;
  free(BUFFER(*l));
}

int listLength(ListDin l)
{
  return NEFF(l);
}

IdxType getFirstIdx(ListDin l)
{
  return IDX_MIN;
}

IdxType getLastIdx(ListDin l)
{
  return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i)
{
  return i >= IDX_MIN && i < CAPACITY(l);
}

boolean isIdxEff(ListDin l, IdxType i)
{
  if (isEmpty(l))
    return false;
  return i >= getFirstIdx(l) && i <= getLastIdx(l);
}

boolean isEmpty(ListDin l)
{
  return NEFF(l) == 0;
}

boolean isFull(ListDin l)
{
  return NEFF(l) == CAPACITY(l);
}

IdxType indexOf(ListDin l, int id)
{
  IdxType i;

  if (isEmpty(l))
    return IDX_UNDEF;

  i = getFirstIdx(l);
  while (i <= getLastIdx(l) && ID(INFO(ELMT(l, i))) != id)
    i++;
  return i > getLastIdx(l) ? IDX_UNDEF : i;
}

void copyList(ListDin lIn, ListDin *lOut)
{
  IdxType i;

  CreateListDin(lOut, CAPACITY(lIn));
  NEFF(*lOut) = NEFF(lIn);
  for (i = getFirstIdx(lIn); i <= getLastIdx(lIn); i++)
  {
    ELMT(*lOut, i) = ELMT(lIn, i);
  }
}

void insertLast(ListDin *l, ElType val)
{
  if (isEmpty(*l))
    NEFF(*l) = 1;
  else
    NEFF(*l) += 1;

  ELMT(*l, getLastIdx(*l)) = val;
}

void deleteLast(ListDin *l, ElType *val)
{
  *val = ELMT(*l, getLastIdx(*l));
  NEFF(*l) -= 1;
}

void expandList(ListDin *l, int num)
{
  CAPACITY(*l) += num;
  BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void shrinkList(ListDin *l, int num)
{
  CAPACITY(*l) -= num;
  BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void compressList(ListDin *l)
{
  CAPACITY(*l) = NEFF(*l);
  BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}