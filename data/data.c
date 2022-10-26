#include "data.h"
#include "../adt/mesinkata/wordmachine.h"
#include "../adt/string/string.h"
#include "../adt/waktu/time.h"
#include <stdio.h>

Matrix map;
ListStatik foods;
ListDin recipesTrees;
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
  ADVWORD();
  for (i = 0; i < nFoods; i++)
  {
    String name, action;
    Time expiry, deliv;
    Makanan newFood;

    int id = wordToInt(currentWord);

    CreateEmptyString(&name, 5);
    CreateEmptyString(&action, 3);
    ADVWORD();
    while (!isNewLine || LENGTH(name) == 0)
    {
      appendWord(&name, currentWord);
      ADVWORD();
    }

    int d,
        h, m;
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
    ADVWORD();
  }

  while (!endWord)
  {
    ADVWORD();
  }
}

void readRecipesConfig(char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("File %s tidak ditemukan", filename);
    return;
  }
  STARTWORD(file, true);
  int nRecipes = wordToInt(currentWord);
  CreateListDin(&recipes, nRecipes);
  CreateListDin(&recipesTrees, 1);

  ADVWORD();
  int i;
  for (i = 0; i < nRecipes; i++)
  {
    int parentId = wordToInt(currentWord);

    Makanan parent = StELMT(foods, indexOf(foods, parentId));

    ADVWORD();
    int childCount = wordToInt(currentWord);

    Tree parentTree = newNode(parent, childCount);
    boolean added = false;
    int j;
    ADVWORD();
    for (j = 0; j < childCount; j++)
    {
      int childId = wordToInt(currentWord);
      Tree childTree = findNodeInList(recipesTrees, childId);
      if (childTree == NULL)
      {
        Makanan child = StELMT(foods, indexOf(foods, childId));
        childTree = newNode(child, 0);
      }
      else
      {
        int idx = indexOfDin(recipesTrees, childId);
        if (idx != -1)
        {
          added = true;
          ELMT(recipesTrees, idx) = parentTree;
        }
      }
      insertLastDin(&CHILDREN(parentTree), childTree);
      ADVWORD();
    }
    if (!added)
    {
      insertLastDin(&recipesTrees, parentTree);
    }
    insertLastDin(&recipes, parentTree);
  }
}