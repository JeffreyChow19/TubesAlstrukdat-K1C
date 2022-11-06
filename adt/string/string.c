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
  free(SBUFFER(*s));
  SCAPACITY(*s) = 0;
  LENGTH(*s) = 0;
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

void appendWord(String *s, Word w)
{
  if (LENGTH(*s) != 0)
    appendChar(s, ' ');
  int i;
  for (i = 0; i < w.Length; i++)
  {
    appendChar(s, w.TabWord[i]);
  }
}

void clearString(String *s)
{
  LENGTH(*s) = 0;
  CHAR(*s, 0) = '\0';
}

void setLiteral(String *s, char *literal)
{
  clearString(s);
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
  int i;
  for (i = 0; i < LENGTH(s1); i++)
    if (CHAR(s1, i) != CHAR(s2, i))
      return false;
  return true;
}

boolean isStringEqualLiteral(String s, char *literal)
{
  int i = 0;
  while (literal[i] != '\0')
  {
    if (i >= LENGTH(s))
      return false;
    if (CHAR(s, i) != literal[i])
      return false;
    i++;
  }
  return i == LENGTH(s);
}

boolean isKataEqualLiteral(Word w, char *literal)
{
  int i = 0;
  while (literal[i] != '\0')
  {
    if (i >= w.Length)
      return false;
    if (w.TabWord[i] != literal[i])
      return false;
    i++;
  }
  return i == w.Length;
}

boolean isStringInt(String s)
{
  if (LENGTH(s) == 0)
    return false;

  int i;
  for (i = 0; i < LENGTH(s); i++)
  {
    if (CHAR(s, i) < '0' || CHAR(s, i) > '9')
      return false;
  }
  return true;
}

boolean isWordInt(Word w)
{
  if (w.Length == 0)
    return false;

  int i;
  for (i = 0; i < w.Length; i++)
  {
    if (w.TabWord[i] < '0' || w.TabWord[i] > '9')
      return false;
  }
  return true;
}

int stringToInt(String s)
{
  int res = 0;
  int i;
  for (i = 0; i < LENGTH(s); i++)
  {
    res *= 10;
    res += CHAR(s, i) - '0';
  }
  return res;
}

int countChar(String s, char c)
{
  int res = 0;
  int i;
  for (i = 0; i < LENGTH(s); i++)
    if (CHAR(s, i) == c)
      res++;
  return res;
}

String getCopyString(String s)
{
  String res;
  CreateEmptyString(&res, LENGTH(s));
  int i;
  for (i = 0; i < LENGTH(s); i++)
    appendChar(&res, CHAR(s, i));
  return res;
}

String wordToString(Word w)
{
  String res;
  CreateEmptyString(&res, w.Length);
  int i;
  for (i = 0; i < w.Length; i++)
    appendChar(&res, w.TabWord[i]);
  return res;
}

int wordToInt(Word w)
{
  int res = 0;
  int i;
  for (i = 0; i < w.Length; i++)
  {
    res *= 10;
    res += w.TabWord[i] - '0';
  }
  return res;
}

void toUpper(String *s)
{
  int i;
  for (i = 0; i < LENGTH(*s); i++)
    if (CHAR(*s, i) >= 'a' && CHAR(*s, i) <= 'z')
      CHAR(*s, i) -= 'a' - 'A';
}

void wordToUpper(Word *w)
{
  int i;
  for (i = 0; i < w->Length; i++)
    if (w->TabWord[i] >= 'a' && w->TabWord[i] <= 'z')
      w->TabWord[i] -= 'a' - 'A';
}

boolean startsWithLiteral(String s, char *literal)
{
  int i = 0;
  while (literal[i] != '\0')
  {
    if (i >= LENGTH(s))
      return false;
    if (CHAR(s, i) != literal[i])
      return false;
    i++;
  }
  return true;
}

boolean startsWith(String s1, String s2)
{
  int i = 0;
  if (LENGTH(s2) > LENGTH(s1))
    return false;
  while (i < LENGTH(s2))
  {
    if (CHAR(s1, i) != CHAR(s2, i))
      return false;
    i++;
  }
  return true;
}