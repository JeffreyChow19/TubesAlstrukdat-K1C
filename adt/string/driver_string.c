#include "string.h"
#include <stdio.h>

int main()
{
  String a, b, c, num;
  CreateEmptyString(&a, 2);
  CreateEmptyString(&b, 10);
  CreateEmptyString(&c, 10);
  CreateEmptyString(&num, 10);

  appendChar(&a, 'a');
  appendChar(&a, 'a');
  appendChar(&a, 'a');
  appendChar(&a, 'a');
  appendChar(&a, 'a');

  printf("a = %s\n", SBUFFER(a));
  printf("length a = %d\n", LENGTH(a));
  printf("capacity a = %d\n", SCAPACITY(a));
  printf("count 'a' in a = %d\n", countChar(a, 'a'));

  setLiteral(&b, "Hello World");
  printf("b = %s\n", SBUFFER(b));
  printf("length b = %d\n", LENGTH(b));
  printf("capacity b = %d\n", SCAPACITY(b));
  printf("count 'l' in b = %d\n", countChar(b, 'l'));

  setLiteral(&c, "Hello World");
  printf("a = b is %s\n", isStringEqual(a, b) ? "true" : "false");
  printf("b = c is %s\n", isStringEqual(b, c) ? "true" : "false");

  setLiteral(&num, "123");

  int x = stringToInt(num);
  printf("x = 123 is %s\n", x == 123 ? "true" : "false");

  setLiteral(&num, "000124");
  x = stringToInt(num);
  printf("x = 124 is %s\n", x == 124 ? "true" : "false");

  dealocateString(&num);

  return 0;
}