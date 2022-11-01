#include "multiset.h"
#include <stdio.h>

int main()
{
  MultiSet m;
  CreateSet(&m, 1);

  addElmtSet(&m, 1, 1);

  // should be 1
  printf("CAP: %d\n", SetCAPACITY(m));
  addElmtSet(&m, 10, 1);
  // should be 2
  printf("CAP: %d\n", SetCAPACITY(m));

  // should be 0
  printf("%d\n", indexOfSet(m, 1));

  // should be 1 1
  printf("%d %d\n", SetELMT(m, 0).id, SetELMT(m, 0).num);

  addElmtSet(&m, 1, 1);

  // should be 2 1 0
  printf("%d %d %d\n", getOccurence(m, 1), hasOccurence(m, 1, 2), hasOccurence(m, 1, 3));

  dealocateSet(&m);

  // should be 0
  printf("CAP: %d\n", SetCAPACITY(m));

  return 0;
}