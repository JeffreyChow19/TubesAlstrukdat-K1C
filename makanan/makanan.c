#include "makanan.h"
#include <stdio.h>
#include "../waktu/time.h"

void CreateMakanan(Makanan *m, int id, String name, Time expiry, String action, Time delivery)
{
  ID(*m) = id;
  NAME(*m) = name;
  EXPIRY(*m) = expiry;
  ACTION(*m) = action;
  DELIVERY(*m) = delivery;
}

void printWithDelivery(Makanan m)
{
  printf("%s (", SBUFFER(NAME(m)));
  WriteDuration(DELIVERY(m));
  printf(")\n");
}

void printWithExpired(Makanan m)
{
  printf("%s (", SBUFFER(NAME(m)));
  WriteDuration(EXPIRY(m));
  printf(")\n");
}

void printMakananDetails(Makanan m)
{
  printf("%s - ", SBUFFER(NAME(m)));
  WriteDuration(EXPIRY(m));
  printf(" - %s - ", SBUFFER(ACTION(m)));
  WriteDuration(DELIVERY(m));
  printf("\n");
}