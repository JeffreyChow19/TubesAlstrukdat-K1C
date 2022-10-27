#include "adt/simulator/simulator.h"
#include <stdio.h>
#include "data/data.h"
#include "adt/mesinkata/wordmachine.h"

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
  printf("\nEnter Command: ");

  STARTWORD(stdin, false);
  String command;
  CreateEmptyString(&command, 5);

  while (!endWord)
  {
    appendWord(&command, currentWord);
    ADVWORD();
  }

  dealocateString(&command);
}

int main()
{

  printf("Welcome to BNMO :)\nPress enter to start");
  scanf("%*c");
  initData("./data/peta.txt", "./data/makanan.txt", "./data/resep.txt");

  Sim sim = initSim();
  boolean running = true;

  while (running)
  {
    printStatus(sim);
  }

  return 0;
}