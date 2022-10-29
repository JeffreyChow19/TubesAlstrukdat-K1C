#include <stdio.h>
#include <stdlib.h>

void throwError(char *message)
{
  printf("\033[0;31mError: %s\033[0m\n", message);
  exit(1);
}