#include "adt/simulator/simulator.h"
#include <stdio.h>
#include "data/data.h"
#include "adt/mesinkata/wordmachine.h"
#include "command/command.h"
#include "color/color.h"
#include "undoredo/undoredo.h"

void printNotifications()
{
  printf("Notifikasi: ");
  LString notifs = (isUndo && IDX_TOP(redoStack) != -1) ? UndoNotifs(InfoTop(redoStack)) : Notifs(simulator);
  if (isEmptyLString(notifs))
  {
    printf("-\n\n");
    return;
  }
  printf("\n");
  int i;
  yellow(false);
  for (i = getFirstIdxLString(notifs); i <= getLastIdxLString(notifs); i++)
  {
    printf("%d. %s\n", i + 1, SBUFFER(ELMTLString(notifs, i)));
  }
  reset();
  printf("\n");
}

void printStatus()
{
  printf("%s di posisi: ", SBUFFER(Name(simulator)));
  WritePoint(Pos(simulator));
  printf("Waktu: ");
  WriteTime(Clock(simulator));

  printNotifications();
  displayMatrix(map, Pos(simulator));
}

void printAsciiArt()
{
  String filename;
  CreateEmptyString(&filename, 15);
  SBUFFER(filename) = "asciiArt.txt";

  START(fopen(SBUFFER(filename), "r"), true);

  while (!EOP)
  {
    printf("%c", currentChar);
    ADV();
  }

  printf("\n");
}

int main()
{
  green(false);
  printf("Welcome to BNMO :)\n");
  printAsciiArt();
  reset();
  printf("Type START to start, EXIT to exit the program\n");
  boolean valid = false;
  do
  {
    STARTWORD(stdin, false);
    String command = wordToString(currentWord);
    IgnoreWords();
    toUpper(&command);
    if (isStringEqualLiteral(command, "START"))
    {
      valid = true;
    }
    else if (isStringEqualLiteral(command, "EXIT"))
    {
      printf("Goodbye :)\n");
      return 0;
    }
    else
    {
      red(false);
      printf("Invalid command\n");
      reset();
    }
    dealocateString(&command);
    IgnoreWords();
  } while (!valid);

  initData("./data/peta.txt", "./data/makanan.txt", "./data/resep.txt");

  boolean running = true;

  while (running)
  {
    printStatus();
    running = !startCommand(&simulator);
  }

  return 0;
}