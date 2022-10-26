#include "makanan.h"
#include <stdio.h>

// command:
// gcc driver_makanan.c makanan.c ../string/string.c ../waktu/time.c ../point/point.c

int main()
{
  int id;
  String name, action;
  Makanan m;
  Time expiry, delivery;
  CreateTime(&expiry, 1, 0, 0);
  CreateTime(&delivery, 0, 0, 0);
  CreateEmptyString(&name, 10);
  printf("Masukkan id: ");
  scanf("%d", &id);
  setLiteral(&name, "Nasi Goreng");
  setLiteral(&action, "FRY");

  CreateMakanan(&m, id, name, expiry, action, delivery);
  printf("Makanan: %s\nid: %d\n", SBUFFER(NAME(m)), ID(m));
  printWithDelivery(m);
  printWithExpired(m);
  printMakananDetails(m);

  return 0;
}