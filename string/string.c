#include "string.h"
#include <stdlib.h>

void CreateEmptyString(String *s, int capacity)
{
  /* ALGORITMA */
  SBUFFER(*s) = (char *)malloc((capacity + 1) * sizeof(char));
  SCAPACITY(*s) = capacity;
  LENGTH(*s) = 0;
  CHAR(*s, 0) = '\0';
}

void dealocateString(String *s)
{
  SCAPACITY(*s) = 0;
  LENGTH(*s) = 0;
  free(SBUFFER(*s));
}

boolean isStringFull(String s)
{
  return LENGTH(s) == SCAPACITY(s);
}

void appendChar(String *s, char c)
{
  if (isStringFull(*s))
    expandString(s, LENGTH(*s));
  CHAR(*s, LENGTH(*s)) = c;
  LENGTH(*s) += 1;
  CHAR(*s, LENGTH(*s)) = '\0';
}

void setLiteral(String *s, char *literal)
{
  LENGTH(*s) = 0;
  CHAR(*s, 0) = '\0';
  int i = 0;
  while (literal[i] != '\0')
  {
    appendChar(s, literal[i]);
    i++;
  }
}

void expandString(String *s, int num)
{
  int newCapacity = SCAPACITY(*s) + num;
  SBUFFER(*s) = (char *)realloc(SBUFFER(*s), (newCapacity + 1) * sizeof(char));
  SCAPACITY(*s) = newCapacity;
}

boolean isStringEqual(String s1, String s2)
{
  if (LENGTH(s1) != LENGTH(s2))
    return false;
  for (int i = 0; i < LENGTH(s1); i++)
    if (CHAR(s1, i) != CHAR(s2, i))
      return false;
  return true;
}