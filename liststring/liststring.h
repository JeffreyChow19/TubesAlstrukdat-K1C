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
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMTLString(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* KONSTRUKTOR */
void CreateLString(LString *l, int capacity);
/*  Create List of String kosong
    I.S. l sembarang, capacity > 0
    F.S. Terbentuk list of string dinamis dengan kapasitas capacity
*/

void dealocateLString(LString *l);
/*  I.S. l terdefinisi
    F.S. l dikembalikan ke system, CAPACITY(l) = 0; NEFF(l) = 0
*/

/* SELECTOR TAMBAHAN */
int lStringLength(LString l);
/* Mengirimkan banyaknya elemen efektif list*/

/* SELEKTOR INDEKS */
IdxType getFirstIdx(LString l);
/*  Prekondisi : LString l tidak kosong */
/*  Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(LString l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

boolean isEmpty(LString l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
boolean isFull(LString l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandLString(LString *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

/* *** Menambahkan elemen terakhir *** */
void insertLastString(LString *l, SElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong */
/* F.S. val adalah elemen terakhir l yang baru, jika list penuh maka akan dialokasikan 2 kali kapasitas sebelumnya */

#endif