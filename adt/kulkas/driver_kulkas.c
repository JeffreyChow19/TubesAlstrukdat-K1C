#include "kulkas.h"

// gcc driver_kulkas.c kulkas.c ../matriks/matriks.c ../makanan/makanan.c ../string/string.c ../point/point.c ../waktu/time.c ../mesinkata/wordmachine.c ../mesinkarakter/charmachine.c ../../error/error.c ../../color/color.c

int main()
{
  Kulkas k, k2;
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

  copyFridge(k, &k2);
  displayKulkas(k2);

  printf("Can add in 0,0: %d\n", canAddInKulkas(k, m, 0, 0));
  printf("Can add in 8,0: %d\n", canAddInKulkas(k, m, 8, 0));

  printf("%d\n", canAddInKulkas(k, m, 0, 0));

  removeItemKulkas(&k, &m, m.id);

  displayKulkas(k);

  dealocateFridge(&k);
  printf("NEFF: %d\nCAP: %d\n", KNEFF(k), KCAPACITY(k));

  return 0;
}