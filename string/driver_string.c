#include "string.h"
#include <stdio.h>

int main()
{
  String a, b, c;
  CreateEmptyString(&a, 2);
  CreateEmptyString(&b, 10);
  CreateEmptyString(&c, 10);

  appendChar(&a, 'a');
  appendChar(&a, 'a');
  appendChar(&a, 'a');
  appendChar(&a, 'a');
  appendChar(&a, 'a');

  printf("a = %s\n", SBUFFER(a));
  printf("length a = %d\n", LENGTH(a));
  printf("capacity a = %d\n", SCAPACITY(a));

  setLiteral(&b, "Hello World");
  printf("b = %s\n", SBUFFER(b));
  printf("length b = %d\n", LENGTH(b));
  printf("capacity b = %d\n", SCAPACITY(b));

  setLiteral(&c, "Hello World");
  printf("a = b is %s\n", isStringEqual(a, b) ? "true" : "false");
  printf("b = c is %s\n", isStringEqual(b, c) ? "true" : "false");

  return 0;
}