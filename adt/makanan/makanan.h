#ifndef MAKANAN_H
#define MAKANAN_H

#include "../string/string.h"
#include "../waktu/time.h"
#include "../point/point.h"

#define ID(m) (m).id
#define NAME(m) (m).name
#define EXPIRY(m) (m).expiry
#define ACTION(m) (m).action
#define DELIVERY(m) (m).delivery
#define SIZE(m) (m).size

typedef struct makanan
{
  int id;
  String name;
  Time expiry;
  String action;
  Time delivery;
  Point size;
} Makanan;

/* ********** KONSTRUKTOR ********** */
/*
  Mengisi id dan nama makanan
  I.S. m sembarang
  F.S. terbentuk makanan dengan id dan nama yang sesuai
 */
void CreateMakanan(Makanan *m, int id, String name, Time expiry, String action, Time delivery, Point size);

/*
  I.S. m terdefinisi
  F.S. m di-free (dealokasi semua string)
 */
void dealocateMakanan(Makanan *m);

/*
  Menampilkan makanan dengan format <nama> (<durasi delivery>)
 */
void printWithDelivery(Makanan m);

/*
  Menampilkan makanan dengan format <nama> (<durasi kedaluarsa>)
 */
void printWithExpired(Makanan m);

/*
  Menampilkan dengan format <nama> - <durasi kedaluarsa> - <aksi> - <durasi delivery>
 */
void printMakananDetails(Makanan m);

/*
  Mengembalikan duplikat makanan
 */
Makanan getCopyMakanan(Makanan m);

#endif