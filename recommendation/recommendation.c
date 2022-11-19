#include "recommendation.h"
#include "../data/data.h"
#include "../adt/multiset/multiset.h"
#include "../cookbook/cookbook.h"
#include "../color/color.h"

void showRecommendation()
{
  ListDin recs;
  CreateListDin(&recs, recipes.nEff);
  MultiSet inv;
  CreateSet(&inv, 10);
  addAllToSet(simulator, &inv);

  int i;
  for (i = getLastIdxDin(recipes); i >= getFirstIdxDin(recipes); i--)
  {
    int id = ID(INFO(ELMT(recipes, i)));
    MultiSet invCop;
    copySet(inv, &invCop);
    if (canBeMade(invCop, id))
    {
      insertLastDin(&recs, ELMT(recipes, i));
    }
    dealocateSet(&invCop);
  }

  dealocateSet(&inv);

  if (recs.nEff == 0)
  {
    red(false);
    printf("\nTidak ada resep yang dapat dibuat.\n");
    reset();
  }
  else
  {
    printf("\nResep yang dapat dibuat:\n");
    for (i = getFirstIdxDin(recs); i <= getLastIdxDin(recs); i++)
    {
      printf("%d. ", i + 1);
      displayRecipe(ELMT(recs, i));
    }
  }
  dealocateListDin(&recs);
}

void addAllToSet(Sim s, MultiSet *set)
{
  int i;
  for (i = 0; i < queueLength(Inv(s)); i++)
  {
    addElmtSet(set, ID(Elmt(Inv(s), i)), 1);
  }
  for (i = 0; i < KNEFF(Fridge(s)); i++)
  {
    addElmtSet(set, ID(KFOOD(KELMT(Fridge(s), i))), 1);
  }
}

MultiSet getFoodBahan(int id)
{
  MultiSet set;
  CreateSet(&set, 10);
  int idx = indexOfDin(recipes, id);
  if (idx == IDX_UNDEF)
  {
    addElmtSet(&set, id, 1);
    return set;
  }
  ListDin children = CHILDREN(ELMT(recipes, idx));

  int i;
  for (i = getFirstIdxDin(children); i <= getLastIdxDin(children); i++)
  {
    addElmtSet(&set, ID(INFO(ELMT(children, i))), 1);
  }
  return set;
}

boolean canBeMade(MultiSet inv, int id)
{
  int parentIdx = indexOfDin(recipes, id);

  // if not a recipe, then false
  if (parentIdx == IDX_UNDEF)
    return false;
  Address parent = ELMT(recipes, parentIdx);

  MultiSet bahan = getFoodBahan(id);

  // if all bahan is in inv, then true
  if (isSubset(bahan, inv))
  {
    subtractSet(&inv, bahan);
    dealocateSet(&bahan);
    return true;
  }

  int j;

  // reduce all bahan that is in inv
  // inv = inv - (inv intersect bahan)
  // bahan = bahan - (inv intersect bahan)
  MultiSet inter = intersection(inv, bahan);
  subtractSet(&inv, inter);
  subtractSet(&bahan, inter);
  dealocateSet(&inter);

  // check if remaining bahan can be made
  for (j = 0; j < SetNEFF(bahan); j++)
  {
    if (!canBeMade(inv, SetELMT(bahan, j).id))
    {
      dealocateSet(&bahan);
      return false;
    }
  }
  dealocateSet(&bahan);

  return true;
}