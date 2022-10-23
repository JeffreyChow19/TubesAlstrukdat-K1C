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
  if (t == NULL)
    return NULL;
  if (ID(INFO(t)) == id)
    return t;
  Address res;
  for (int i = getFirstIdx(CHILDREN(t)); i <= getLastIdx(CHILDREN(t)); ++i)
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
  }
  return NULL;
}

ListDin getAllRecipeNodes(ListDin l)
{
  ListDin res;
  CreateListDin(&res, 10);
  for (int i = getFirstIdx(l); i <= getLastIdx(l); ++i)
  {
    if (NEFF(CHILDREN(ELMT(l, i))) > 0)
      insertLast(&res, ELMT(l, i));
    ListDin childRecipes = getAllRecipeNodes(CHILDREN(ELMT(l, i)));
    concatList(&res, &childRecipes);
  }
  return res;
}