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
#include "../schedule/schedule.h"
#include "../undoredo/undoredo.h"

void addToStack()
{
  Sim s;
  copySim(simulator, &s);
  push(&undoStack, s);
  clearStack(&redoStack);
}

void move(char dir)
{
  addToStack();
  boolean moved = setPos(&simulator, dir, map);
  if (moved)
    tick();
  else
  {
    dealocateSim(&simulator);
    pop(&undoStack, &simulator);
  }
}

boolean startCommand()
{
  printf("\nEnter Command: ");

  STARTWORD(stdin, false);

  if (isKataEqualLiteral(currentWord, "WAIT"))
  {
    ADVWORD();
    String str = wordToString(currentWord);
    if (endWord || !isStringInt(str))
    {
      printf("Command invalid. Jam harus merupakan angka. Silahkan coba lagi\n");
      IgnoreWords();
      dealocateString(&str);
      return startCommand();
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
      return startCommand();
    }
    int m = stringToInt(str);
    dealocateString(&str);
    IgnoreWords();
    Time t;
    CreateTime(&t, 0, h, m);

    addToStack();
    tickWithTime(h, m);
    printf("Waktu telah berjalan ");
    WriteDuration(t);
    printf("\n\n");

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
    move('N');
  }
  else if (isStringEqualLiteral(command, "MOVE EAST"))
  {
    move('E');
  }
  else if (isStringEqualLiteral(command, "MOVE SOUTH"))
  {
    move('S');
  }
  else if (isStringEqualLiteral(command, "MOVE WEST"))
  {
    move('W');
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
  else if (isStringEqualLiteral(command, "BUY"))
  {

    if (!isActionAdj(map, Pos(simulator), 'T'))
    {
      printf("\nBNMO tidak berada di area telepon!\n\n");
      return false;
    }

    addToStack();
    buy(&simulator);
    tick();
    STARTWORD(stdin, false);
    IgnoreWords();
  }
  else if (isStringEqualLiteral(command, "DELIVERY"))
  {
    delivery(&simulator);
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "FRY"))
  {
    addToStack();
    processFood(command);
    tick();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "CHOP"))
  {
    if (!isActionAdj(map, Pos(simulator), 'C'))
    {
      printf("\nBNMO tidak berada di area chop!\n\n");
      return false;
    }
    addToStack();
    processFood(command);
    tick();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "MIX"))
  {
    if (!isActionAdj(map, Pos(simulator), 'M'))
    {
      printf("\nBNMO tidak berada di area mix!\n\n");
      return false;
    }
    addToStack();
    processFood(command);
    tick();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "BOIL"))
  {
    if (!isActionAdj(map, Pos(simulator), 'B'))
    {
      printf("\nBNMO tidak berada di area boil!\n\n");
      return false;
    }
    addToStack();
    processFood(command);
    tick();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "UNDO"))
  {
    undo();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "REDO"))
  {
    redo();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "INVENTORY"))
  {
    openInv(simulator);
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "PROCESS"))
  {
    openProc(simulator);
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
    return startCommand();
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