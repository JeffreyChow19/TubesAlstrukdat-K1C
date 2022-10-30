#include "fridge.h"
#include "../data/data.h"
#include "../adt/mesinkata/wordmachine.h"

void printAllBahanKulkas()
{
  printf("(nama - ukuran - posisi)\n");
  int i;
  for (i = 0; i < KNEFF(Fridge(simulator)); i++)
  {
    InfoKulkas info = KELMT(Fridge(simulator), i);
    printf("%d. %s - %dx%d ", i + 1, SBUFFER(NAME(KFOOD(info))), Absis(SIZE(KFOOD(info))), Ordinat(SIZE(KFOOD(info))));
    WritePoint(KPOS(info));
  }
}

void showFridgeMenu()
{
  displayKulkas(Fridge(simulator));
  printf("\nList Makanan dalam kulkas:\n");
  if (KNEFF(Fridge(simulator)) == 0)
  {
    printf("Kulkas kosong\n");
  }
  else
  {
    printAllBahanKulkas();
  }

  printf("\nMasukkan perintah yang ingin dilakukan:\n");
  printf("1. Masukkan ke kulkas\n");
  printf("2. Keluarkan dari kulkas\n");

  printf("\nKirim 0 untuk exit.\n\n");
  int command = readIntWithRange(0, 2);
  switch (command)
  {
  case 1:
    addFoodToFridge();
    break;
  case 2:
    removeFoodFromFridge();
    break;
  default:
    break;
  }
}

void addFoodToFridge()
{
  if (queueLength(Inv(simulator)) == 0)
  {
    printf("\nTidak ada bahan di inventory\n\n");
    return;
  }

  printf("Pilih bahan yang ingin dimasukkan ke kulkas:\n");
  printf("(nama - ukuran)\n");
  int i;
  for (i = 0; i < queueLength(Inv(simulator)); i++)
  {
    Makanan m = FoodInv(simulator, i);
    printf("%d. %s - %dx%d\n", i + 1, SBUFFER(NAME(m)), Absis(SIZE(m)), Ordinat(SIZE(m)));
  }

  printf("\nKirim 0 untuk exit.\n\n");
  int chosen = readIntWithRange(0, queueLength(Inv(simulator)));

  if (chosen == 0)
    return;

  Makanan m = FoodInv(simulator, chosen - 1);
  displayKulkas(Fridge(simulator));
  printf("Masukkan posisi makanan dalam kulkas (ukuran makanan %dx%d): \n", Absis(SIZE(m)), Ordinat(SIZE(m)));
  int x, y;
  boolean valid = false;
  do
  {
    STARTWORD(stdin, false);
    if (!isWordInt(currentWord))
    {
      IgnoreWords();
    }
    else
    {

      x = wordToInt(currentWord);

      ADVWORD();

      if (endWord || !isWordInt(currentWord))
      {
        IgnoreWords();
      }
      else
      {
        y = wordToInt(currentWord);
        ADVWORD();
        valid = endWord && isIdxEffMat(KMAT(Fridge(simulator)), y, x);
      }
    }

    IgnoreWords();
    if (!valid)
      printf("Masukan tidak valid. Posisi dalam format x y\n");
  } while (!valid);

  if (canAddInKulkas(Fridge(simulator), m, x, y))
  {
    removeByIndex(&Inv(simulator), &m, chosen - 1);
    addItemKulkas(&Fridge(simulator), m, x, y);
    printf("\n%s berhasil dimasukkan ke kulkas\n\n", SBUFFER(NAME(m)));
  }
  else
  {
    printf("\n%s tidak dapat dimasukkan ke kulkas\n\n", SBUFFER(NAME(m)));
  }
}

void removeFoodFromFridge()
{
  if (KNEFF(Fridge(simulator)) == 0)
  {
    printf("\nKulkas kosong. Tidak ada makanan yang dapat dikeluarkan.\n\n");
    return;
  }

  printf("Pilih makanan yang ingin dikeluarkan dari kulkas:\n");
  printAllBahanKulkas();
  printf("\nKirim 0 untuk exit.\n\n");

  int chosen = readIntWithRange(0, KNEFF(Fridge(simulator)));

  if (chosen == 0)
    return;
  Makanan m;
  removeItemKulkasByIndex(&Fridge(simulator), &m, chosen - 1);
  enqueue(&Inv(simulator), m);
  printf("\n%s berhasil dikeluarkan dari kulkas\n\n", SBUFFER(NAME(m)));
}