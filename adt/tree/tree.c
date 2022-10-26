#include "tree.h"

Address newNode(Makanan val, int childrenCapacity)
{
  Address a = (Address)malloc(sizeof(Node));
  if (a != NULL)
  {
    INFO(a) = val;
    CreateListDin(&CHILDREN(a), childrenCapacity);
  }
  return a;
}

Address findNodeInTree(Address t, int id)
{
  if (t == NULL)
    return NULL;
  if (ID(INFO(t)) == id)
    return t;
  Address res;
  int i;
  for (i = getFirstIdxDin(CHILDREN(t)); i <= getLastIdxDin(CHILDREN(t)); ++i)
  {
    res = findNodeInTree(ELMT(CHILDREN(t), i), id);
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
    i++;
  }
  return NULL;
}

ListDin getAllRecipeNodes(ListDin l)
{
  ListDin res;
  CreateListDin(&res, 10);
  int i;
  for (i = getFirstIdxDin(l); i <= getLastIdxDin(l); ++i)
  {
    if (NEFF(CHILDREN(ELMT(l, i))) > 0)
      insertLastDin(&res, ELMT(l, i));
    ListDin childRecipes = getAllRecipeNodes(CHILDREN(ELMT(l, i)));
    concatListDin(&res, &childRecipes);
  }
  return res;
}
