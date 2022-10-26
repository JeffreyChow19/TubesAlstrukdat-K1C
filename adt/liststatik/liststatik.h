#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "../boolean.h"
#include "../makanan/makanan.h"

/* Kasus Umum */
#define StCAPACITY 100
/* Kapasitas list */
#define IDX_MIN 0
/* Index minimum list*/
#define IDX_UNDEF -1
/* Index tidak terdefinisi */

/* Definisi elemen dan koleksi objek*/
typedef Makanan ElType;
typedef int IdxType;
typedef struct
{
   ElType buffer[StCAPACITY]; /* memori tempat penyimpanan elemen */
   int Neff;
} ListStatik;
/* Indeks yang digunakan [0..StCAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define StELMT(l, i) (l).buffer[(i)]
#define StNeff(l) (l).Neff

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong (Neff = 0) dengan kapasitas StCAPACITY */
void CreateListStatik(ListStatik *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
int listLength(ListStatik l);

/* *** Selektor INDEKS *** */
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getFirstIdx(ListStatik l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
IdxType getLastIdx(ListStatik l);

/* ********** Test Indeks yang valid ********** */
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValid(ListStatik l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
boolean isIdxEff(ListStatik l, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
boolean isEmpty(ListStatik l);
/* *** Test List penuh *** */
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
boolean isFull(ListStatik l);

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
int indexOf(ListStatik l, int id);

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
void insertLast(ListStatik *l, ElType val);

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pada index tertentu *** */
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, id adalah index yang valid di l */
/* F.S. val adalah nilai elemen dengan id, id  sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteId(ListStatik *l, ElType *val, int id);
/* *** Menghapus elemen terakhir *** */
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteLast(ListStatik *l, ElType *val);

#endif