#include "data.h"
#include "../mesinkata/wordmachine.h"
#include "../string/string.h"
#include "../waktu/time.h"
#include <stdio.h>

Matrix map;
ListStatik foods;
ListDin recipes;

void initData(char *mapFile, char *foodsFile, char *recipesFile)
{
  readMapConfig(mapFile);
  readFoodsConfig(foodsFile);
  readRecipesConfig(recipesFile);
}

void readMapConfig(char *filename)
{
  readMatrix(&map, filename);
}

void readFoodsConfig(char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("File %s tidak ditemukan", filename);
    return;
  }
  STARTWORD(file, true);
  int nFoods = wordToInt(currentWord);
  CreateListStatik(&foods);
  int i;
  for (i = 0; i < nFoods; i++)
  {
    String name, action;
    Time expiry, deliv;
    Makanan newFood;

    ADVWORD();
    int id = wordToInt(currentWord);

    CreateEmptyString(&name, 5);
    CreateEmptyString(&action, 3);
    ADVWORD();
    while (!isNewLine)
    {
      appendWord(&name, currentWord);
      ADVWORD();
    }

    int d, h, m;
    d = wordToInt(currentWord);
    ADVWORD();
    h = wordToInt(currentWord);
    ADVWORD();
    m = wordToInt(currentWord);

    CreateTime(&expiry, d, h, m);

    ADVWORD();
    d = wordToInt(currentWord);
    ADVWORD();
    h = wordToInt(currentWord);
    ADVWORD();
    m = wordToInt(currentWord);

    CreateTime(&deliv, d, h, m);

    ADVWORD();
    appendWord(&action, currentWord);

    CreateMakanan(&newFood, id, name, expiry, action, deliv);
    insertLast(&foods, newFood);
  }

  while (!endWord)
  {
    ADVWORD();
  }
}