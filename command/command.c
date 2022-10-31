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
#include "../fridge/fridge.h"
#include "../recommendation/recommendation.h"
#include "../color/color.h"

void cancelAddToStack()
{
  dealocateSim(&simulator);
  pop(&undoStack, &simulator);
}

void addToStack(boolean clearRedo)
{
  Sim s;
  copySim(simulator, &s);
  clearListString(&UndoNotifs(simulator), false);
  clearListString(&Notifs(simulator), false);
  push(&undoStack, s);
  if (clearRedo)
  {
    isUndo = false;
    clearStack(&redoStack);
  }
}

void move(char dir)
{
  addToStack(false);
  boolean moved = setPos(&simulator, dir, map);
  if (moved)
  {
    isUndo = false;
    tick();
    clearStack(&redoStack);
  }
  else
  {
    cancelAddToStack();
  }
}

void processFoodCommand(String command, char action, char *name)
{
  if (!isActionAdj(map, Pos(simulator), action))
  {
    red(false);
    printf("\nBNMO tidak berada di area %s!\n\n", name);
    reset();
    return;
  }

  addToStack(false);
  boolean success = processFood(command);
  if (success)
  {
    isUndo = false;
    tick();
    clearStack(&redoStack);
  }
  else
  {
    cancelAddToStack();
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
      red(false);
      printf("Command invalid. Jam harus merupakan angka. Silahkan coba lagi\n");
      reset();
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
      red(false);
      printf("Command invalid. Menit harus merupakan angka. Silahkan coba lagi\n");
      reset();
      IgnoreWords();
      dealocateString(&str);
      return startCommand();
    }
    int m = stringToInt(str);
    dealocateString(&str);
    IgnoreWords();
    Time t;
    CreateTime(&t, 0, h, m);

    addToStack(true);
    tickWithTime(h, m);
    green(false);
    printf("\nWaktu telah berjalan ");
    WriteDuration(t);
    reset();
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
      red(false);
      printf("\nBNMO tidak berada di area telepon!\n\n");
      reset();
      return false;
    }

    addToStack(false);
    boolean bought = buy(&simulator);
    if (bought)
    {
      isUndo = false;
      tick();
      clearStack(&redoStack);
    }
    else
    {
      cancelAddToStack();
    }
  }
  else if (isStringEqualLiteral(command, "DELIVERY"))
  {
    delivery(&simulator);
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "FRY"))
  {
    processFoodCommand(command, 'F', "fry");
  }
  else if (isStringEqualLiteral(command, "CHOP"))
  {
    processFoodCommand(command, 'C', "chop");
  }
  else if (isStringEqualLiteral(command, "MIX"))
  {
    processFoodCommand(command, 'M', "mix");
  }
  else if (isStringEqualLiteral(command, "BOIL"))
  {
    processFoodCommand(command, 'B', "boil");
  }
  else if (isStringEqualLiteral(command, "UNDO"))
  {
    boolean success = undo();
    if (!success)
      enterToContinue();
  }
  else if (isStringEqualLiteral(command, "REDO"))
  {
    boolean success = redo();
    if (!success)
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
  else if (isStringEqualLiteral(command, "FRIDGE"))
  {
    addToStack(false);
    boolean changed = showFridgeMenu();
    if (!changed)
      cancelAddToStack();
    else
    {
      isUndo = false;
      clearStack(&redoStack);
    }
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "RECOMMENDATION"))
  {
    showRecommendation();
    enterToContinue();
  }
  else if (isStringEqualLiteral(command, "EXIT"))
  {
    return true;
  }
  else
  {
    red(false);
    printf("Command tidak valid. Silakan coba lagi.\n");
    reset();
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