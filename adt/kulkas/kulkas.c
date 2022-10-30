#include "kulkas.h"
#include "../point/point.h"
#include <stdio.h>

void CreateKulkas(Kulkas *k)
{
  createMatrix(NROWKULKAS, NCOLKULKAS, &KMAT(*k));
  int i, j;
  for (i = 0; i < NROWKULKAS; i++)
  {
    for (j = 0; j < NCOLKULKAS; j++)
    {
      ELMTMat(KMAT(*k), i, j) = false;
    }
  }
  KNEFF(*k) = 0;
  KCAPACITY(*k) = INITIALCAP;
  KBUFFER(*k) = (InfoKulkas *)malloc(INITIALCAP * sizeof(InfoKulkas));
}

void addItemKulkas(Kulkas *k, Makanan m, int x, int y)
{
  if (KNEFF(*k) == KCAPACITY(*k))
  {
    KCAPACITY(*k) += 2;
    KBUFFER(*k) = (InfoKulkas *)realloc(KBUFFER(*k), KCAPACITY(*k) * sizeof(InfoKulkas));
  }
  InfoKulkas e;
  KFOOD(e) = m;
  CreatePoint(&KPOS(e), x, y);
  KELMT(*k, KNEFF(*k)) = e;
  KNEFF(*k) += 1;

  int i, j;
  for (i = y; i < y + Ordinat(SIZE(m)); i++)
  {
    for (j = x; j < x + Absis(SIZE(m)); j++)
    {
      ELMTMat(KMAT(*k), i, j) = true;
    }
  }
}

void removeItemKulkas(Kulkas *k, int idx)
{
  int i, j, x, y;
  InfoKulkas e = KELMT(*k, idx);
  for (i = idx; i < KNEFF(*k) - 1; i++)
  {
    KELMT(*k, i) = KELMT(*k, i + 1);
  }
  KNEFF(*k) -= 1;
  if (KNEFF(*k) < KCAPACITY(*k) - 2 && KCAPACITY(*k) > INITIALCAP)
  {
    KCAPACITY(*k) -= 2;
    KBUFFER(*k) = (InfoKulkas *)realloc(KBUFFER(*k), KCAPACITY(*k) * sizeof(InfoKulkas));
  }

  x = Absis(KPOS(e));
  y = Ordinat(KPOS(e));

  for (i = y; i < y + Ordinat(SIZE(KFOOD(e))); i++)
  {
    for (j = x; j < x + Absis(SIZE(KFOOD(e))); j++)
    {
      ELMTMat(KMAT(*k), i, j) = false;
    }
  }
}

boolean canAddInKulkas(Kulkas k, Makanan m, int x, int y)
{
  int i, j;
  for (i = x; i < x + Absis(SIZE(m)); i++)
  {
    for (j = y; j < y + Ordinat(SIZE(m)); j++)
    {
      if (ELMTMat(KMAT(k), i, j))
      {
        return false;
      }
    }
  }
  return true;
}

void displayKulkas(Kulkas k)
{
  int i, j;
  printf("* ");
  for (i = 0; i < COL_EFF(KMAT(k)); i++)
  {
    printf("%d ", i % 10);
  }
  printf("*");
  printf("\n");
  for (i = 0; i < ROW_EFF(KMAT(k)); i++)
  {
    printf("%d ", i % 10);
    for (j = 0; j < COL_EFF(KMAT(k)); j++)
    {
      if (ELMTMat(KMAT(k), i, j))
      {
        printf("X ");
      }
      else
      {
        printf("- ");
      }
    }
    printf("*\n");
  }

  for (i = 0; i < COL_EFF(KMAT(k)) + 2; i++)
  {
    printf("* ");
  }
  printf("\n");
}