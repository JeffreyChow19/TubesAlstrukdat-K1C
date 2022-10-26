#include "simulator/simulator.h"
#include <stdio.h>
#include "data/data.h"

int main()
{
  printf("Welcome to BNMO :)\nPress enter to start");
  scanf("%*c");
  initData("./data/map.txt", "./data/foods.txt", "./data/recipes.txt");

  return 0;
}