#include "fridge.h"
#include "../data/data.h"
#include "../adt/mesinkata/wordmachine.h"
#include "../color/color.h"

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

boolean showFridgeMenu()
{
  printf("\n");
  displayKulkas(Fridge(simulator));
  printf("\nList Makanan dalam kulkas:\n");
  if (KNEFF(Fridge(simulator)) == 0)
  {
    red(false);
    printf("Kulkas kosong\n");
    reset();
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
    return addFoodToFridge();
  case 2:
    return removeFoodFromFridge();
  default:
    return false;
  }
}

boolean addFoodToFridge()
{
  if (queueLength(Inv(simulator)) == 0)
  {
    red(false);
    printf("\nTidak ada bahan di inventory\n\n");
    reset();
    return false;
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
    return false;

  Makanan m = FoodInv(simulator, chosen - 1);
  printf("\n");
  displayKulkas(Fridge(simulator));
  printf("\nMasukkan posisi makanan dalam kulkas (ukuran makanan %dx%d): \n", Absis(SIZE(m)), Ordinat(SIZE(m)));
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
    green(false);
    printf("\n%s berhasil dimasukkan ke kulkas\n\n", SBUFFER(NAME(m)));
    reset();
    return true;
  }
  else
  {
    red(false);
    printf("\n%s tidak dapat dimasukkan ke kulkas\n\n", SBUFFER(NAME(m)));
    reset();
    return false;
  }
}

boolean removeFoodFromFridge()
{
  if (KNEFF(Fridge(simulator)) == 0)
  {
    red(false);
    printf("\nKulkas kosong. Tidak ada makanan yang dapat dikeluarkan.\n\n");
    reset();
    return false;
  }

  printf("Pilih makanan yang ingin dikeluarkan dari kulkas:\n");
  printAllBahanKulkas();
  printf("\nKirim 0 untuk exit.\n\n");

  int chosen = readIntWithRange(0, KNEFF(Fridge(simulator)));

  if (chosen == 0)
    return false;
  Makanan m;
  removeItemKulkasByIndex(&Fridge(simulator), &m, chosen - 1);
  enqueue(&Inv(simulator), m);
  green(false);
  printf("\n%s berhasil dikeluarkan dari kulkas\n\n", SBUFFER(NAME(m)));
  reset();
  return true;
}