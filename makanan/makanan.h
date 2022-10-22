#ifndef MAKANAN_H
#define MAKANAN_H

#include "../string/string.h"

#define ID(m) (m).id
#define NAME(m) (m).name
#define ACTION(m) (m).action

typedef struct
{
  int id;
  String name;
  String action;
} Makanan;

/* ********** KONSTRUKTOR ********** */
/*
  Mengisi id dan nama makanan
  I.S. m sembarang
  F.S. terbentuk makanan dengan id dan nama yang sesuai
 */
void CreateMakanan(Makanan *m, int id, String name, String action);

#endif