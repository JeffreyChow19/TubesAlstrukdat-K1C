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

/* Definisi struktur data kulkas dan elemen kulkas */
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

/* Selektor */
#define KMAT(k) (k).mat
#define KBUFFER(k) (k).buffer
#define KNEFF(k) (k).nEff
#define KCAPACITY(k) (k).cap
#define KELMT(k, i) (k).buffer[i]
#define KPOS(e) (e).pos
#define KFOOD(e) (e).makanan

/* Konstruktor kulkas */
/* I.S. k sembarang */
/* F.S. Terbentuk kulkas dengan ukuran NROWKULKAS * NCOLKULKAS kosong dengan capacity sebesar INITIALCAP */
void CreateKulkas(Kulkas *k);

/* I.S. k terdefinisi */
/* F.S. buffer k didealokasi, capacity=0, neff=0 */
void dealocateFridge(Kulkas *k);

/* I.S. k terdefinisi, copy sembarang */
/* F.S. k dicopy ke copy dengan mengalokasikan buffer baru */
void copyFridge(Kulkas k, Kulkas *copy);

/* Menambahkan makanan ke kulkas pada koordinat tertentu */
/* I.S. k terdefinisi, canAddInKulkas(*k, m, x, y) = true */
/* F.S. k pada koordinat (x, y) terisi makanan m */
void addItemKulkas(Kulkas *k, Makanan m, int x, int y);

/* Menghapus elemen pada kulkas berdasarkan index pada buffer */
/* I.S. k terdefinisi, idx merupakan index yang valid pada buffer kulkas */
/* F.S. makanan pada index ke-idx dikeluarkan dari kulkas dan disimpan pada val */
void removeItemKulkasByIndex(Kulkas *k, Makanan *val, int idx);

/* Menghapus elemen pada kulkas berdasarkna id makanan */
/* I.S. k terdefinisi, id makanan terdapat pada kulkas */
/* F.S. makanan dengan id tersebut dikeluarkan dari kulkas dan disimpan pada val */
void removeItemKulkas(Kulkas *k, Makanan *val, int id);

/* Mengecek apakah makanan dapat dimasukkan ke kulkas pada koordinat tertentu */
/* Mengembalikan true jika m dapat dimasukkan ke k pada (x, y) */
boolean canAddInKulkas(Kulkas k, Makanan m, int x, int y);

/* Mengembalikan indeks kemunculan pertama makanan dengan id tertentu pada kulkas */
int searchIdxKulkas(Kulkas k, int id);

/* Menampilkan isi kulkas */
void displayKulkas(Kulkas k);

#endif