#include "adt/simulator/simulator.h"
#include <stdio.h>
#include "data/data.h"

int main()
{
  printf("Welcome to BNMO :)\nPress enter to start");
  scanf("%*c");
  initData("./data/peta.txt", "./data/makanan.txt", "./data/resep.txt");

  return 0;
}