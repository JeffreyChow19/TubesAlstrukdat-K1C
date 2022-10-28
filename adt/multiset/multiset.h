#ifndef MULTISET_H
#define MULTISET_H

#include "../boolean.h"

typedef struct multisetinfo
{
  int id;
  int num;
} SetInfo;

typedef struct multiset
{
  SetInfo *buffer;
  int cap;
  int nEff;
} MultiSet;

#define SetBUFFER(m) (m).buffer
#define SetELMT(m, i) (m).buffer[i]
#define SetCAPACITY(m) (m).cap
#define SetNEFF(m) (m).nEff
#define IDX_UNDEF_SET -1

void CreateSet(MultiSet *m, int cap);

void dealocateSet(MultiSet *m);

int indexOfSet(MultiSet m, int id);

void addElmtSet(MultiSet *m, int id);

void removeElmtSet(MultiSet *m, int id);

int getOccurence(MultiSet m, int id);

boolean hasOccurence(MultiSet m, int id, int num);

void expandSet(MultiSet *m, int num);

void shrinkSet(MultiSet *m, int num);

#endif