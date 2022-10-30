#ifndef KULKAS_H
#define KULKAS_H
#include "../matriks/matriks.h"
#include "../point/point.h"
#include "../makanan/makanan.h"
#include <stdlib.h>

#define IDX_UNDEF_K -1
#define NROWKULKAS 10
#define NCOLKULKAS 20
#define INITIALCAP 10

typedef struct
{
  Point pos;
  Makanan makanan;
} InfoKulkas;

typedef struct kulkas
{
  Matrix mat;
  InfoKulkas *buffer;
  int nEff;
  int cap;
} Kulkas;

#define KMAT(k) (k).mat
#define KBUFFER(k) (k).buffer
#define KNEFF(k) (k).nEff
#define KCAPACITY(k) (k).cap
#define KELMT(k, i) (k).buffer[i]
#define KPOS(e) (e).pos
#define KFOOD(e) (e).makanan

void CreateKulkas(Kulkas *k);

void dealocateFridge(Kulkas *k);

void copyFridge(Kulkas k, Kulkas *copy);

void addItemKulkas(Kulkas *k, Makanan m, int x, int y);

void removeItemKulkasByIndex(Kulkas *k, Makanan *val, int idx);

void removeItemKulkas(Kulkas *k, Makanan *val, int id);

boolean canAddInKulkas(Kulkas k, Makanan m, int x, int y);

int searchIdxKulkas(Kulkas k, int idx);

void displayKulkas(Kulkas k);

#endif