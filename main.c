#include "adt/simulator/simulator.h"
#include <stdio.h>
#include "data/data.h"
#include "adt/mesinkata/wordmachine.h"
#include "command/command.h"

Sim initSim()
{
  Sim s;
  String name;
  Point pos;

  CreateEmptyString(&name, 4);
  setLiteral(&name, "BNMO");

  CreatePoint(&pos, 0, 0);

  CreateSim(&s, name, pos);
  return s;
}

void printStatus(Sim s)
{
  printf("%s di posisi: ", SBUFFER(Name(s)));
  WritePoint(Pos(s));
  printf("Waktu: ");
  WriteTime(Clock(s));

  // TODO: Print notifikasi
  printf("Notifikasi: -\n\n");
  displayMatrix(map, Pos(s));
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

  Sim sim = initSim();
  boolean running = true;

  while (running)
  {
    printStatus(sim);
    running = !startCommand(&sim);
  }

  return 0;
}