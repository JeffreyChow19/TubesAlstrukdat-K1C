#include "tree.h"

Address newNode(Makanan val)
{
  Address a = (Address)malloc(sizeof(Node));
  if (a != NULL)
  {
    INFO(a) = val;
    CreateListDin(&CHILDREN(a), 10);
  }
  return a;
}

Address findNodeInTree(Address t, int id)
{
  if (t == NULL || listLength(CHILDREN(t)) == 0)
    return NULL;
  if (ID(INFO(t)) == id)
    return t;
  Address res;
  for (int i = getFirstIdx(CHILDREN(t)); i <= getLastIdx(CHILDREN(t)); ++i)
  {
    res = getNodeById(Elmt(CHILDREN(t), i), id);
    if (res != NULL)
      return res;
  }
  return NULL;
}

Address findNodeInList(ListDin l, int id)
{
  int i = 0;
  while (i < NEFF(l))
  {
    Address e = findNodeInTree(ELMT(l, i), id);
    if (e != NULL)
      return e;
  }
  return NULL;
}
