#include "tree.h"
#include <stdio.h>

// command:
// gcc driver_tree.c tree.c ../listdin/listdin.c ../string/string.c ../makanan/makanan.c ../waktu/time.c ../point/point.c
Address createNode(int id, char *name, int dex, int hex, int mex, char *action, int ddel, int hdel, int mdel, int sizex, int sizey)
{
  Time expiry, delivery;
  String sname, saction;
  Makanan m;
  Address a;
  Point size;

  CreateTime(&expiry, dex, hex, mex);
  CreateTime(&delivery, ddel, hdel, mdel);
  CreateEmptyString(&sname, 5);
  CreateEmptyString(&saction, 5);

  setLiteral(&sname, name);
  setLiteral(&saction, action);

  CreatePoint(&size, sizex, sizey);

  CreateMakanan(&m, id, sname, expiry, saction, delivery, size);

  a = newNode(m, 5);
  return a;
}

int main()
{
  Address root = createNode(1, "Nasi Goreng", 1, 0, 0, "FRY", 0, 0, 0, 2, 2);
  Address nasi = createNode(2, "Nasi", 1, 0, 0, "BOIL", 0, 0, 0, 2, 2);
  insertLast(&CHILDREN(root), nasi);

  Address beras = createNode(3, "Beras", 1, 0, 0, "BUY", 0, 0, 5, 2, 2);
  insertLast(&CHILDREN(nasi), beras);

  Address ayam = createNode(4, "Ayam", 3, 0, 0, "BUY", 0, 0, 5, 2, 2);

  insertLast(&CHILDREN(root), ayam);

  printMakananDetails(INFO(findNodeInTree(root, 3)));
  ListDin trees;
  CreateListDin(&trees, 1);
  insertLast(&trees, root);

  printf("List of recipes:\n");
  ListDin recipes = getAllRecipeNodes(trees);
  for (int i = getFirstIdx(recipes); i <= getLastIdx(recipes); ++i)
  {
    Address node = ELMT(recipes, i);
    printf("%s (%s): ", SBUFFER(NAME(INFO(node))), SBUFFER(ACTION(INFO(node))));
    for (int j = getFirstIdx(CHILDREN(node)); j <= getLastIdx(CHILDREN(node)); ++j)
    {
      printf("%s", SBUFFER(NAME(INFO(ELMT(CHILDREN(node), j)))));
      if (j != getLastIdx(CHILDREN(node)))
        printf(", ");
    }
    printf("\n");
  }

  return 0;
}