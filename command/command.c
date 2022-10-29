#include "command.h"
#include <stdio.h>
#include "../adt/mesinkata/wordmachine.h"
#include "../catalog/catalog.h"
#include "../cookbook/cookbook.h"

boolean startCommand(Sim *s)
{
  printf("\nEnter Command: ");

  STARTWORD(stdin, false);
  String command;
  CreateEmptyString(&command, 5);

  while (!endWord)
  {
    appendWord(&command, currentWord);
    ADVWORD();
  }
  toUpper(&command);

  if (isStringEqualLiteral(command, "MOVE NORTH"))
  {
  }
  else if (isStringEqualLiteral(command, "MOVE EAST"))
  {
  }
  else if (isStringEqualLiteral(command, "MOVE SOUTH"))
  {
  }
  else if (isStringEqualLiteral(command, "MOVE WEST"))
  {
  }
  else if (isStringEqualLiteral(command, "CATALOG"))
  {
    displayCatalog();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "COOKBOOK"))
  {
    displayCookbook();
  }
  else if (isStringEqualLiteral(command, "EXIT"))
  {
    return true;
  }

  dealocateString(&command);
  return false;
}

void enterToContinue()
{
  printf("Press ENTER to continue...");
  STARTWORD(stdin, false);
  IgnoreWords();
}