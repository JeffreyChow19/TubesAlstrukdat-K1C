#include "listdin.h"
#include <stdio.h>

// command:
// gcc driver_listdin.c listdin.c ../tree/tree.c ../string/string.c ../makanan/makanan.c ../waktu/time.c ../point/point.c

Address createNode(int id, char *name, int dex, int hex, int mex, char *action, int ddel, int hdel, int mdel, int sizex, int sizey)
{
  Time expiry, delivery;
  String sname, saction;
  Makanan m;
  Address a;
  Point size;

  CreateTime(&expiry, dex, hex, mex);
  CreateTime(&delivery, ddel, hdel, mdel);
  CreateEmptyString(&sname, 5);
  CreateEmptyString(&saction, 5);

  setLiteral(&sname, name);
  setLiteral(&saction, action);

  CreatePoint(&size, sizex, sizey);

  CreateMakanan(&m, id, sname, expiry, saction, delivery, size);

  a = newNode(m, 5);
  return a;
}

int main()
{
  ListDin l;

  CreateListDin(&l, 5);

  printf("is empty: %d\n", isEmptyDin(l));

  Address nasgor = createNode(1, "Nasi Goreng", 1, 0, 0, "FRY", 0, 0, 0, 2, 2);
  insertLastDin(&l, nasgor);

  printf("%d\n", listLengthDin(l));

  Address nasi = createNode(2, "Nasi", 1, 0, 0, "BOIL", 0, 0, 0, 2, 2);

  insertLastDin(&l, nasi);

  printf("nasgor: %d, nasi: %d\n", indexOfDin(l, 1), indexOfDin(l, 2));

  ListDin l2;
  copyListDin(l, &l2);

  dealocateListDin(&l);
  printf("%d\n", listLengthDin(l2));

  printf("cap: %d\n", CAPACITY(l));

  return 0;
}