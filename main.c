#include "adt/simulator/simulator.h"
#include <stdio.h>
#include "data/data.h"
#include "adt/mesinkata/wordmachine.h"
#include "command/command.h"

void printNotifications()
{
  printf("Notifikasi: ");
  if (isEmptyLString(notifs))
  {
    printf("-\n\n");
    return;
  }
  printf("\n");
  int i;
  for (i = getFirstIdxLString(notifs); i <= getLastIdxLString(notifs); i++)
  {
    printf("%d. %s\n", i + 1, BUFFER(ELMTLString(notifs, i)));
  }
  printf("\n");
  clearListString(&notifs);
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

int main()
{

  printf("Welcome to BNMO :)\nType START to start, EXIT to exit the program\n");
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
      printf("Invalid command\n");
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