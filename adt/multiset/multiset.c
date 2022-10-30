#include "multiset.h"
#include <stdlib.h>
#include <stdio.h>

void CreateSet(MultiSet *m, int cap)
{
  SetBUFFER(*m) = (SetInfo *)malloc(cap * sizeof(SetInfo));

  SetCAPACITY(*m) = cap;
  SetNEFF(*m) = 0;
}

void dealocateSet(MultiSet *m)
{
  free(SetBUFFER(*m));
  SetCAPACITY(*m) = 0;
  SetNEFF(*m) = 0;
}

int indexOfSet(MultiSet m, int id)
{
  int low = 0;
  int high = SetNEFF(m) - 1;
  int mid;

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (SetELMT(m, mid).id == id)
    {
      return mid;
    }
    else if (SetELMT(m, mid).id < id)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return IDX_UNDEF_SET;
}

void addElmtSet(MultiSet *m, int id, int n)
{
  int idx = indexOfSet(*m, id);

  if (idx != IDX_UNDEF_SET)
  {
    SetELMT(*m, idx).num += n;
  }
  else
  {
    if (SetNEFF(*m) == SetCAPACITY(*m))
    {
      expandSet(m, SetCAPACITY(*m));
    }

    int i = SetNEFF(*m) - 1;
    while (i >= 0 && SetELMT(*m, i).id > id)
    {
      SetELMT(*m, i + 1) = SetELMT(*m, i);
      i--;
    }

    SetELMT(*m, i + 1).id = id;
    SetELMT(*m, i + 1).num = n;
    SetNEFF(*m)++;
  }
}

void removeElmtSet(MultiSet *m, int id, int n)
{
  int idx = indexOfSet(*m, id);

  if (idx != IDX_UNDEF_SET)
  {
    if (SetELMT(*m, idx).num > n)
    {
      SetELMT(*m, idx).num -= n;
    }
    else
    {
      int i = idx;
      while (i < SetNEFF(*m) - 1)
      {
        SetELMT(*m, i) = SetELMT(*m, i + 1);
        i++;
      }
      SetNEFF(*m)--;
      if (SetNEFF(*m) < SetCAPACITY(*m) / 4)
      {
        shrinkSet(m, SetCAPACITY(*m) / 2);
      }
    }
  }
}

void combineSet(MultiSet *m1, MultiSet *m2)
{
  int i;
  for (i = 0; i < SetNEFF(*m2); i++)
  {
    int j;
    int id = SetELMT(*m2, i).id;
    int num = SetELMT(*m2, i).num;

    int idx = indexOfSet(*m1, id);
    addElmtSet(m1, id, num);
  }
  dealocateSet(m2);
}

void multiplySet(MultiSet *m, int n)
{
  int i;
  for (i = 0; i < SetNEFF(*m); i++)
  {
    SetELMT(*m, i).num *= n;
  }
}

boolean isSubset(MultiSet m1, MultiSet m2)
{
  int i;
  for (i = 0; i < SetNEFF(m1); i++)
  {
    int id = SetELMT(m1, i).id;
    int num = SetELMT(m1, i).num;
    if (!hasOccurence(m2, id, num))
    {
      return false;
    }
  }
  return true;
}

void subtractSet(MultiSet *m1, MultiSet m2)
{
  int i;
  for (i = 0; i < SetNEFF(m2); i++)
  {
    int id = SetELMT(m2, i).id;
    int num = SetELMT(m2, i).num;
    int j;
    removeElmtSet(m1, id, num);
  }
}

int getOccurence(MultiSet m, int id)
{
  int idx = indexOfSet(m, id);

  if (idx != IDX_UNDEF_SET)
  {
    return SetELMT(m, idx).num;
  }
  else
  {
    return 0;
  }
}

boolean hasOccurence(MultiSet m, int id, int num)
{
  int idx = indexOfSet(m, id);

  if (idx != IDX_UNDEF_SET)
  {
    return SetELMT(m, idx).num >= num;
  }
  else
  {
    return false;
  }
}

void expandSet(MultiSet *m, int num)
{
  SetBUFFER(*m) = (SetInfo *)realloc(SetBUFFER(*m), (SetCAPACITY(*m) + num) * sizeof(SetInfo));
  SetCAPACITY(*m) += num;
}

void shrinkSet(MultiSet *m, int num)
{
  SetBUFFER(*m) = (SetInfo *)realloc(SetBUFFER(*m), (SetCAPACITY(*m) - num) * sizeof(SetInfo));
  SetCAPACITY(*m) -= num;
}

void displaySet(MultiSet m)
{
  printf("{");
  int i;
  for (i = 0; i < SetNEFF(m); i++)
  {
    printf("(%d,%d)", SetELMT(m, i).id, SetELMT(m, i).num);
    if (i < SetNEFF(m) - 1)
    {
      printf(", ");
    }
  }
  printf("}\n");
}