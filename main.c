#include "adt/simulator/simulator.h"
#include <stdio.h>
#include "data/data.h"
#include "adt/mesinkata/wordmachine.h"
#include "command/command.h"
#include "color/color.h"
#include "undoredo/undoredo.h"

LString *lastNotifs;

void printNotifications()
{
  printf("Notifikasi: ");
  LString *notifs = (isUndo && IDX_TOP(redoStack) != -1) ? &UndoNotifs(InfoTop(redoStack)) : &Notifs(simulator);

  if (lastNotifs == notifs || isEmptyLString(*notifs))
  {
    lastNotifs = notifs;
    printf("-\n\n");
    return;
  }

  lastNotifs = notifs;
  printf("\n");
  int i;
  yellow(false);
  for (i = getFirstIdxLString(*notifs); i <= getLastIdxLString(*notifs); i++)
  {
    printf("%d. %s\n", i + 1, SBUFFER(ELMTLString(*notifs, i)));
  }
  reset();
  printf("\n");
}

void printStatus()
{
  printf("\n%s di posisi: ", SBUFFER(Name(simulator)));
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
  int i = 120;
  boolean inc = true;
  rgb(255, 150, i);
  while (!EOP)
  {
    printf("%c", currentChar);
    if (currentChar == '\n')
    {
      reset();
      if (inc)
      {
        i += 8;
        if (i >= 255)
        {
          i = 255;
          inc = false;
        }
      }
      else
      {
        i -= 8;
        if (i <= 120)
        {
          i = 120;
          inc = true;
        }
      }
      rgb(255, 150, i);
    }
    ADV();
  }
  reset();

  printf("\n");
}

int main()
{
  printAsciiArt();
  green(false);
  printf("Welcome to BNMO :)\n");
  reset();
  printf("Type ");
  green(true);
  printf("START");
  reset();
  printf(" to start, ");
  red(true);
  printf("EXIT");
  reset();
  printf(" to exit the program\n");

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