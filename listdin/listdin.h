#ifndef LISTDIN_H
#define LISTDIN_H

#include "boolean.h"
#include "../tree/tree.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Address ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
  ElType *buffer; /* memori tempat penyimpan elemen (container) */
  int nEff;       /* >=0, banyaknya elemen efektif */
  int capacity;   /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
void CreateListDin(ListDin *l, int capacity);

/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
void dealocateList(ListDin *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
int listLength(ListDin l);

/* *** Daya tampung container *** */
/* *** Selektor INDEKS *** */
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getFirstIdx(ListDin l);

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
IdxType getLastIdx(ListDin l);

/* ********** Test Indeks yang valid ********** */
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValid(ListDin l, IdxType i);

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
boolean isIdxEff(ListDin l, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isEmpty(ListDin l);

/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean isFull(ListDin l);

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
boolean isListEqual(ListDin l1, ListDin l2);

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, int id);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l);
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */

#endif