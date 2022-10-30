#include <stdio.h>
#include <stdlib.h>
#include "../color/color.h"

void throwError(char *message)
{
  red(true);
  printf("Error: %s\n", message);
  reset();
  exit(1);
}