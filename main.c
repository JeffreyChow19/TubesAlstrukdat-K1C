#include "adt/simulator/simulator.h"
#include <stdio.h>
#include "data/data.h"

int main()
{
  printf("Welcome to BNMO :)\nPress enter to start");
  scanf("%*c");
  initData("./data/peta.txt", "./data/makanan.txt", "./data/resep.txt");
  // return 0;
  int i;
  for (i = 0; i < NEFF(recipesTrees); i++)
  {
    Tree t = Elmt(recipesTrees, i);
    printf("%d. %s\n", i + 1, SBUFFER(NAME(INFO(t))));
    int j;
    for (j = 0; j < NEFF(CHILDREN(t)); j++)
    {
      Tree c = Elmt(CHILDREN(t), j);
      printf("%s %x\n", SBUFFER(NAME(INFO(c))));
    }
  }

  return 0;
}