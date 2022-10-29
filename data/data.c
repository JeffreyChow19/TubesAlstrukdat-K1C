#include "data.h"
#include "../adt/mesinkata/wordmachine.h"
#include "../adt/string/string.h"
#include "../adt/waktu/time.h"
#include "../error/error.h"
#include <stdio.h>

Matrix map;
ListStatik foods;
ListDin recipesTrees;
ListDin recipes;
Sim simulator;
Stack undoStack;
Stack redoStack;
LString notifs;

void initData(char *mapFile, char *foodsFile, char *recipesFile)
{
  initSimulator();
  readMapConfig(mapFile);
  readFoodsConfig(foodsFile);
  readRecipesConfig(recipesFile);
  CreateStack(&undoStack, 10);
  CreateStack(&redoStack, 10);
  CreateLString(&notifs, 10);
}

void readMapConfig(char *filename)
{
  readMatrix(&map, filename, &simulator);
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
    if (endWord)
      throwError("File konfigurasi makanan tidak valid\nJumlah food lebih sedikit daripada yang dispesifikasikan\n");
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

  if (!endWord)
    throwError("File konfigurasi makanan tidak valid\nJumlah food lebih banyak daripada yang dispesifikasikan\n");
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
    if (endWord)
      throwError("File konfigurasi resep tidak valid\nJumlah resep lebih sedikit daripada yang dispesifikasikan\n");
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
          if (added)
            deleteAtDin(&recipesTrees, idx);
          else
          {
            ELMT(recipesTrees, idx) = parentTree;
            added = true;
          }
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
  if (!endWord)
    throwError("File konfigurasi resep tidak valid\nJumlah resep lebih banyak daripada yang dispesifikasikan\n");
}

void initSimulator()
{
  String name;
  Point pos;

  CreateEmptyString(&name, 4);
  setLiteral(&name, "BNMO");

  CreatePoint(&pos, 0, 0);

  CreateSim(&simulator, name, pos);
}
