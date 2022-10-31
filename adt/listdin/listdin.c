#include "listdin.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void CreateListDin(ListDin *l, int capacity)
{
  CAPACITY(*l) = capacity > 0 ? capacity : 1;
  BUFFER(*l) = (ElTypeDin *)malloc(CAPACITY(*l) * sizeof(ElTypeDin));
  NEFF(*l) = 0;
}

void dealocateListDin(ListDin *l)
{
  CAPACITY(*l) = 0;
  NEFF(*l) = 0;
  free(BUFFER(*l));
}

int listLengthDin(ListDin l)
{
  return NEFF(l);
}

IdxType getFirstIdxDin(ListDin l)
{
  return IDX_MIN;
}

IdxType getLastIdxDin(ListDin l)
{
  return NEFF(l) - 1;
}

boolean isIdxValidDin(ListDin l, IdxType i)
{
  return i >= IDX_MIN && i < CAPACITY(l);
}

boolean isIdxEffDin(ListDin l, IdxType i)
{
  if (isEmptyDin(l))
    return false;
  return i >= getFirstIdxDin(l) && i <= getLastIdxDin(l);
}

boolean isEmptyDin(ListDin l)
{
  return NEFF(l) == 0;
}

boolean isFullDin(ListDin l)
{
  return NEFF(l) == CAPACITY(l);
}

IdxType indexOfDin(ListDin l, int id)
{
  IdxType i;

  if (isEmptyDin(l))
    return IDX_UNDEF;

  i = getFirstIdxDin(l);
  while (i <= getLastIdxDin(l) && ID(INFO(ELMT(l, i))) != id)
    i++;
  return i > getLastIdxDin(l) ? IDX_UNDEF : i;
}

void copyListDin(ListDin lIn, ListDin *lOut)
{
  IdxType i;

  CreateListDin(lOut, CAPACITY(lIn));
  NEFF(*lOut) = NEFF(lIn);
  for (i = getFirstIdxDin(lIn); i <= getLastIdxDin(lIn); i++)
  {
    ELMT(*lOut, i) = ELMT(lIn, i);
  }
}

void insertLastDin(ListDin *l, ElTypeDin val)
{
  if (isFullDin(*l))
    expandListDin(l, CAPACITY(*l));
  if (isEmptyDin(*l))
    NEFF(*l) = 1;
  else
    NEFF(*l) += 1;

  ELMT(*l, getLastIdxDin(*l)) = val;
}

void deleteLastDin(ListDin *l, ElTypeDin *val)
{
  *val = ELMT(*l, getLastIdxDin(*l));
  NEFF(*l) -= 1;
  if (NEFF(*l) < CAPACITY(*l) / 4)
    shrinkListDin(l, CAPACITY(*l) / 2);
}

void deleteAtDin(ListDin *l, IdxType i)
{
  IdxType j;
  for (j = i; j < getLastIdxDin(*l); j++)
  {
    ELMT(*l, j) = ELMT(*l, j + 1);
  }
  NEFF(*l) -= 1;
  if (NEFF(*l) < CAPACITY(*l) / 4)
    shrinkListDin(l, CAPACITY(*l) / 2);
}

void concatListDin(ListDin *l1, ListDin *l2)
{
  IdxType i;

  for (i = getFirstIdxDin(*l2); i <= getLastIdxDin(*l2); i++)
  {
    insertLastDin(l1, ELMT(*l2, i));
  }
  dealocateListDin(l2);
}

void expandListDin(ListDin *l, int num)
{
  CAPACITY(*l) += num;
  BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElTypeDin));
}

void shrinkListDin(ListDin *l, int num)
{
  CAPACITY(*l) -= num;
  BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElTypeDin));
}

void compressListDin(ListDin *l)
{
  CAPACITY(*l) = NEFF(*l);
  BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElTypeDin));
}