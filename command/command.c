#include "command.h"
#include <stdio.h>
#include "../adt/mesinkata/wordmachine.h"
#include "../catalog/catalog.h"
#include "../cookbook/cookbook.h"
#include "../olah/olah.h"
#include "../Map/moveNact.h"
#include "../data/data.h"
#include "../buy/buy.h"
#include "../delivery/delivery.h"

boolean startCommand(Sim *s)
{
  printf("\nEnter Command: ");

  STARTWORD(stdin, false);

  if (isKataEqualLiteral(currentWord, "WAIT"))
  {
    // handle wait
    ADVWORD();
    String str = wordToString(currentWord);
    if (endWord || !isStringInt(str))
    {
      printf("Command invalid. Jam harus merupakan angka. Silahkan coba lagi\n");
      IgnoreWords();
      dealocateString(&str);
      return startCommand(s);
    }

    int h = stringToInt(str);
    clearString(&str);
    ADVWORD();
    appendWord(&str, currentWord);
    if (endWord || !isStringInt(str))
    {
      printf("Command invalid. Menit harus merupakan angka. Silahkan coba lagi\n");
      IgnoreWords();
      dealocateString(&str);
      return startCommand(s);
    }
    int m = stringToInt(str);
    dealocateString(&str);
    IgnoreWords();
    // TODO: call wait handling

    return false;
  }
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
    setPos(s, 'N', map);
  }
  else if (isStringEqualLiteral(command, "MOVE EAST"))
  {
    setPos(s, 'E', map);
  }
  else if (isStringEqualLiteral(command, "MOVE SOUTH"))
  {
    setPos(s, 'S', map);
  }
  else if (isStringEqualLiteral(command, "MOVE WEST"))
  {
    setPos(s, 'W', map);
  }
  else if (isStringEqualLiteral(command, "CATALOG"))
  {
    displayCatalog();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "COOKBOOK"))
  {
    displayCookbook();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "FRY"))
  {
    processFood(command);
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "CHOP"))
  {
    processFood(command);
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "MIX"))
  {
    processFood(command);
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "BOIL"))
  {
    processFood(command);
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "BUY"))
  {
    buy(s);
    STARTWORD(stdin, false);
    IgnoreWords();
  }
  else if (isStringEqualLiteral(command, "DELIVERY"))
  {
    delivery(s);
    enterToContinue();
  }
    else if (isStringEqualLiteral(command, "INVENTORY"))
  {
    openInv(simulator);
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "EXIT"))
  {
    return true;
  }
  else
  {
    printf("Command tidak valid. Silakan coba lagi.\n");
    dealocateString(&command);
    return startCommand(s);
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