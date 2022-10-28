#include "multiset.h"
#include <stdlib.h>

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

void addElmtSet(MultiSet *m, int id)
{
  int idx = indexOfSet(*m, id);

  if (idx != IDX_UNDEF_SET)
  {
    SetELMT(*m, idx).num++;
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
    SetELMT(*m, i + 1).num = 1;
    SetNEFF(*m)++;
  }
}

void removeElmtSet(MultiSet *m, int id)
{
  int idx = indexOfSet(*m, id);

  if (idx != IDX_UNDEF_SET)
  {
    if (SetELMT(*m, idx).num > 1)
    {
      SetELMT(*m, idx).num--;
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