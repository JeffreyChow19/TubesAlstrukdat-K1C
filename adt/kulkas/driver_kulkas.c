#include "kulkas.h"

// gcc driver_kulkas.c kulkas.c ../matriks/matriks.c ../makanan/makanan.c ../string/string.c ../point/point.c ../waktu/time.c ../mesinkata/wordmachine.c ../mesinkarakter/charmachine.c ../../error/error.c

int main()
{
  Kulkas k;
  CreateKulkas(&k);

  Makanan m;
  String name;
  CreateEmptyString(&name, 10);
  setLiteral(&name, "Makanan");
  Point p;
  Time expiry, delivery;
  CreateTime(&expiry, 0, 0, 30);
  CreateTime(&delivery, 0, 0, 10);

  CreatePoint(&p, 2, 3);
  CreateMakanan(&m, 1, name, expiry, name, delivery, p);

  addItemKulkas(&k, m, 0, 0);
  addItemKulkas(&k, m, 5, 7);

  displayKulkas(k);

  printf("%d\n", canAddInKulkas(k, m, 0, 0));

  return 0;
}