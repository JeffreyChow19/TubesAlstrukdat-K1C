#ifndef MAKANAN_H
#define MAKANAN_H

#include "../string/string.h"
#include "../waktu/time.h"

#define ID(m) (m).id
#define NAME(m) (m).name
#define EXPIRY(m) (m).expiry
#define ACTION(m) (m).action
#define DELIVERY(m) (m).delivery

typedef struct
{
  int id;
  String name;
  Time expiry;
  String action;
  Time delivery;
} Makanan;

/* ********** KONSTRUKTOR ********** */
/*
  Mengisi id dan nama makanan
  I.S. m sembarang
  F.S. terbentuk makanan dengan id dan nama yang sesuai
 */
void CreateMakanan(Makanan *m, int id, String name, Time expiry, String action, Time delivery);

/*
  Menampilkan makanan dengan format <nama> <waktu delivery>
 */
void printWithDelivery(Makanan m);

/*
  Menampilkan dengan format <nama> - <durasi kedaluarsa> - <aksi> - <durasi delivery>
 */
void printMakananDetails(Makanan m);

#endif