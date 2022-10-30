#include "color.h"
#include <stdio.h>

void red(boolean bold)
{
  if (bold)
    printf("\033[1;31m");
  else
    printf("\033[0;31m");
}

void green(boolean bold)
{
  if (bold)
    printf("\033[1;32m");
  else
    printf("\033[0;32m");
}

void yellow(boolean bold)
{
  if (bold)
    printf("\033[1;33m");
  else
    printf("\033[0;33m");
}

void blue(boolean bold)
{
  if (bold)
    printf("\033[1;34m");
  else
    printf("\033[0;34m");
}

void reset()
{
  printf("\033[0m");
}