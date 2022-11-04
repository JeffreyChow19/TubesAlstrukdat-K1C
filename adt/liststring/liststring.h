#ifndef __LISTSTRING_H__
#define __LISTSTRING_H__
/* LIST OF STRING DINAMIS */

#include "../boolean.h"
#include "../string/string.h"

/* DEFINISI ELEMEN DAN KOLEKSI OBJEK */
typedef String SElType;
typedef int IdxType;
typedef struct
{
    String *buffer; /* container */
    int nEff;       /* banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} LString;

/* SELEKTOR */
#define LSNEFF(l) (l).nEff
#define LSBUFFER(l) (l).buffer
#define ELMTLString(l, i) (l).buffer[i]
#define LSCAPACITY(l) (l).capacity

/* KONSTRUKTOR */
/*  Create List of String kosong
    I.S. l sembarang, capacity > 0
    F.S. Terbentuk list of string dinamis dengan kapasitas capacity
*/
void CreateLString(LString *l, int capacity);

/*  I.S. l terdefinisi
    F.S. l dikembalikan ke system, CAPACITY(l) = 0; NEFF(l) = 0
*/
void dealocateLString(LString *l);

/* SELECTOR TAMBAHAN */
/* Mengirimkan banyaknya elemen efektif list*/
int lStringLength(LString l);

/* SELEKTOR INDEKS */
/*  Prekondisi : LString l tidak kosong */
/*  Mengirimkan indeks elemen l pertama */
IdxType getFirstIdxLString(LString l);

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
IdxType getLastIdxLString(LString l);

/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
boolean isEmptyLString(LString l);

/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean isFullLString(LString l);

/* ********* MENGUBAH UKURAN ARRAY ********* */
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
void expandLString(LString *l, int num);

/* *** Menambahkan elemen terakhir *** */
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong */
/* F.S. val adalah elemen terakhir l yang baru, jika list penuh maka akan dialokasikan 2 kali kapasitas sebelumnya */
void insertLastString(LString *l, SElType val);

/* *** Menghapus semua elemen *** */
/* Proses: Menghapus semua elemen pada string */
/* I.S. List l terdefinisi */
/* F.S. neff l = 0, semua elemen string didealokasi */
void clearListString(LString *l, boolean dealocateEl);

/* *** Menyalin ListString *** */
/* Proses : menyalin seluruh elemen pada l ke l1*/
/* I.S. List l terdefinisi */
/* F.S. List l1 terdefinisi dan elemennya sama dengan l */
void copyListString(LString l, LString *l1);

#endif