#ifndef LISTDIN_H
#define LISTDIN_H

#include "../boolean.h"
#include "../tree/tree.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

#ifndef LISTDIN_S
#define LISTDIN_S
/* Definisi elemen dan koleksi objek */
typedef struct node *ElTypeDin; /* type elemen list */
typedef int IdxType;
typedef struct listdin
{
  ElTypeDin *buffer; /* memori tempat penyimpan elemen (container) */
  int nEff;          /* >=0, banyaknya elemen efektif */
  int capacity;      /* ukuran elemen */
} ListDin;
#endif
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
void dealocateListDin(ListDin *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
int listLengthDin(ListDin l);

/* *** Daya tampung container *** */
/* *** Selektor INDEKS *** */
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getFirstIdxDin(ListDin l);

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
IdxType getLastIdxDin(ListDin l);

/* ********** Test Indeks yang valid ********** */
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValidDin(ListDin l, IdxType i);

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
boolean isIdxEffDin(ListDin l, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isEmptyDin(ListDin l);

/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean isFullDin(ListDin l);

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
boolean isListEqualDin(ListDin l1, ListDin l2);

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
/* Search apakah ada elemen List l yang memiliki id=id */
/* Jika ada, menghasilkan indeks i terkecil, dengan id elemen ke-i = id */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
IdxType indexOfDin(ListDin l, int id);

/* ********** OPERASI LAIN ********** */
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
void copyListDin(ListDin lIn, ListDin *lOut);

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong */
/* F.S. val adalah elemen terakhir l yang baru, jika list penuh maka akan dialokasikan 2 kali kapasitas sebelumnya */
void insertLastDin(ListDin *l, ElTypeDin val);

/* ********** MENGHAPUS ELEMEN ********** */
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong, jika panjang list menjadi */
/*      < seperempat kapasitas, maka kapasitas akan dikurangi setengahnya */
void deleteLastDin(ListDin *l, ElTypeDin *val);

void deleteAtDin(ListDin *l, IdxType i);

/*
  Menambahkan seluruh elemen l2 ke l1 lalu dealokasi l2.
  I.S. l1 dan l2 terdefinisi, mungkin kosong
  F.S. l1 berisi semua elemen l1 dan l2, l2 terdealokasi
 */
void concatListDin(ListDin *l1, ListDin *l2);

/* ********* MENGUBAH UKURAN ARRAY ********* */
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
void expandListDin(ListDin *l, int num);

/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
void shrinkListDin(ListDin *l, int num);

/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
void compressListDin(ListDin *l);

#endif